//files required import
#include "twitter_create.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void createTwitterSystem(twitter * twitterSystem)//function for twitter system
{
    userPtr currentPtr;//current user pointer
    twitterSystem->headPtr = NULL;
    twitterSystem->tweetHeadPtr = NULL;
    for (int i = 0; i < MAX_USERS; i++)
    {
        userPtr newPtr = malloc(sizeof(user));//assigning dynamic memory to assign users
        if (newPtr != NULL)
        {//taking input of usernames.
            printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
            fgets(newPtr->username, USR_LENGTH, stdin);
            fflush(stdin);
            if (newPtr->username[0] == ' ')//error check wrong input
            {
                printf("(Do not start username with a 'Space'!!!)");
                i--;
                continue;
            }
            if (newPtr->username[0] == '\t')
            {
                break;
            }//defining members of struct user
            if (newPtr->username[strlen(newPtr->username) - 1] == '\n')
            {
                newPtr->username[strlen(newPtr->username) - 1] = '\0';
            }
            newPtr->numFollowers = 0;
            newPtr->numFollowing = 0;
            newPtr->nextPtr = NULL;
        }
        if (twitterSystem->headPtr == NULL)//replacing header data with newPtr data
        {
            twitterSystem->headPtr = newPtr;
        }
        else
        {
            currentPtr = twitterSystem->headPtr;
            while (currentPtr->nextPtr != NULL)
            {
                currentPtr = currentPtr->nextPtr;
            }
            currentPtr->nextPtr = newPtr;//pointing to newPtr appending new data
        }
    }
    currentPtr = twitterSystem->headPtr;
    while (currentPtr != NULL)
    {//printing user info
        printf("User: %s  \t\tfollowing: %d\tfollowers: %d\n", currentPtr->username, currentPtr->numFollowers,
               currentPtr->numFollowers);
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr = twitterSystem->headPtr;
    int control;
    while (1)
    {
        printf("\n\nCurrent User: %s\n", currentPtr->username);
        control = menu(twitterSystem, currentPtr);
        if (control == 6)//iterating to next user
        {
            if (currentPtr->nextPtr == NULL)
            {
                currentPtr = twitterSystem->headPtr;
            }
            else
            {
                currentPtr = currentPtr->nextPtr;
            }
            continue;
        }
        else if (control == 7)//terminating twitter program
        {
            break;
        }
    }
}