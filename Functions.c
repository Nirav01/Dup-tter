//importing header files and library
#include "twitter_create.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *nextPointer, user *ptr)//function to follow other users
{
    char fUser[USR_LENGTH];
    printf("Enter user you want to Follow:\n");
    fflush(stdin);
    fgets(fUser, USR_LENGTH, stdin);//taking username of whom current user wants to follow
    if(fUser[strlen(fUser) -1] == '\n')
    {
        fUser[strlen(fUser) - 1] = '\0';
    }
    for(int d = 0; d < MAX_FOLLOWING; d++)
    {
        if(strcasecmp(fUser,ptr->username)==0)//checking if user entered his/her own username
        {
            printf("You are not allowed to follow yourself!\n Try entering a different user.\n");
            return;
        }
        if(strcasecmp(fUser,ptr->following[d])==0)//checking if you already follow the user
        {
            printf("You already follow this User!\n No point in following them twice!\n\n");
            return;
        }
    }
    userPtr currentPtr;
    currentPtr = nextPointer->headPtr;
    int userCheck = 0;
    while(currentPtr != NULL)
    {
        if(strcasecmp(currentPtr->username,fUser) == 0)//entering user to followers list
        {
            strcpy(ptr->following[ptr->numFollowing], currentPtr->username );
            ptr->numFollowing++;//increasing num_following of current user
            strcpy(currentPtr->followers[currentPtr->numFollowers], ptr->username);
            currentPtr->numFollowers++;//increasing num_followers of the user followed
            userCheck = 1;
            break;
        }
        else
        {
            currentPtr = currentPtr->nextPtr;
        }
    }
    if(userCheck == 0)
    {
        puts("Username you have entered is not in the System! You will be returned to the menu Now!");
        return;
    }
}

void deleteUser(twitter *nextPointer, user *currentUser)//function to delete user
{
    userPtr temp;
    temp = nextPointer->headPtr;
    if(currentUser == nextPointer->headPtr)
    {
        nextPointer->headPtr = currentUser->nextPtr;
        free(currentUser);//removing data from memory
        return;
    }
    while(strcasecmp(temp->nextPtr->username, currentUser->username) != 0)
    {
        temp = temp->nextPtr;
    }
    temp->nextPtr = currentUser->nextPtr;
    subDelete(nextPointer, currentUser);
    free(currentUser);
}

void subDelete(twitter *nextPointer, user *currentUser)//helper function to delete all the actions done by the user
{
    char tempUser[USR_LENGTH];
    for(int i = 0; i < currentUser->numFollowers; i++)//deleting num followers
    {
        strcpy(tempUser,currentUser->followers[i]);
        userPtr tempPtr = nextPointer->headPtr;
        while(strcasecmp(tempPtr->username,tempUser)!=0)
        {
            tempPtr = tempPtr->nextPtr;
        }
        int k = 0;
        while(strcasecmp(tempPtr->following[k],currentUser->username)!=0)
        {
            k++;
        }
        for(int o = k+1; o < tempPtr->numFollowing; o++)
        {
            strcpy(tempPtr->following[k],tempPtr->following[o]);
            k++;
        }
        tempPtr->numFollowing--;//decreasing numFollowing
    }
    for(int i = 0; i < currentUser->numFollowing; i++)//deleting trace of user from other users data
    {
        strcpy(tempUser,currentUser->following[i]);
        userPtr tempPtr = nextPointer->headPtr;
        while(strcasecmp(tempPtr->username,tempUser)!=0)
        {
            tempPtr = tempPtr->nextPtr;
        }
        int k = 0;
        while(strcasecmp(tempPtr->followers[k],currentUser->username)!=0)
        {
            k++;
        }
        for(int o = k+1; o < tempPtr->numFollowers; o++)
        {
            strcpy(tempPtr->followers[k],tempPtr->followers[o]);
            k++;
        }
        tempPtr->numFollowers--;//decreasing number of followers
    }

    if(nextPointer->tweetHeadPtr == NULL)
    {
        return;
    }
    tweetPtr currentTweet = nextPointer->tweetHeadPtr;
    tweetPtr previousTweet = nextPointer->tweetHeadPtr->nextPointer;
    while(currentTweet != NULL)
    {
        if(strcasecmp(currentUser->username,currentTweet->user) == 0)
        {
            if(currentTweet == nextPointer->tweetHeadPtr)
            {
                nextPointer->tweetHeadPtr = currentTweet->nextPointer;
                free(currentTweet);
                currentTweet = nextPointer->tweetHeadPtr->nextPointer;
                continue;
            }
            previousTweet->nextPointer = currentTweet->nextPointer;
            free(currentTweet);
            currentTweet = previousTweet->nextPointer;
            continue;
        }
        previousTweet = currentTweet;
        currentTweet = currentTweet->nextPointer;
    }
}
void unfollow(twitter *nextPointer, user *ptr)//unfollow any user
{
    char name[USR_LENGTH];
    char null[USR_LENGTH];
    userPtr currentPtr;
    currentPtr = nextPointer->headPtr;
    for(int j = 0; j < USR_LENGTH; j++)
    {
        null[j] = '\0';
    }
    printf("\nEnter username of the user you would like to unfollow:\n");
    fflush(stdin);
    fgets(name,USR_LENGTH,stdin);//user current user wants to unfollow
    if(name[strlen(name) - 1] == '\n')
    {
        name[strlen(name) - 1] = '\0';
    }
    int i, check = 0;
    for(i = 0; ptr->numFollowing; i++)
    {
        if(strcmp(ptr->following[i], name) == 0)
        {
            strcpy(ptr->following[i], null);
            ptr->numFollowing--;//decreasing number of following by one
            check = 1;
            break;
        }
    }
    if(check == 0)//checking if user exists
    {
        printf("Error, entered user not found.\n"
               "You do not follow this User.\n");
        return;
    }
    while(currentPtr->nextPtr != NULL)
    {
        if(strcasecmp(currentPtr->username, name) == 0)
        {
            break;
        }
        currentPtr = currentPtr->nextPtr;
    }
    for(int k = 0; k < currentPtr->numFollowers; k++)
    {
        if(strcmp(currentPtr->followers[k], ptr->username) == 0)
        {
            strcpy(currentPtr->followers[k], null);
            currentPtr->numFollowers--;//decreasing number of followers from user
            break;
        }
    }
}
