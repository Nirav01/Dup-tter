
#include "twitter_create.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void follow(twitter *ts, user *ptr)
{
    char mUser[USR_LENGHT];
    printf("Enter user you want to Follow:\n");
    fflush(stdin);
    fgets(mUser, USR_LENGHT, stdin);
    if(mUser[strlen(mUser) -1] == '\n')
    {
        mUser[strlen(mUser) - 1] = '\0';
    }
    for(int d = 0; d < MAX_FOLLOWING; d++){
        if(strcasecmp(mUser,ptr->username)==0){
            printf("You are not allowed to follow yourself!\n Try entering a different user.\n");
            return;
        }
        if(strcasecmp(mUser,ptr->following[d])==0){
            printf("You already follow this User!\n No point in following them twice!\n\n");
            return;
        }
    }
    Userptr currptr;
    currptr = ts->headptr;
    int user_check = 0;
    while(currptr != NULL)
    {
        if(strcasecmp(currptr->username,mUser) == 0)
        {
            strcpy(ptr->following[ptr->num_following], currptr->username );
            ptr->num_following++;
            strcpy(currptr->followers[currptr->num_followers], ptr->username);
            currptr->num_followers++;
            user_check = 1;
            break;
        }
        else{
            currptr = currptr->nextptr;
        }
    }
    if(user_check == 0)
    {
        puts("Username you have entered is not in the System! You will be returned to the menu Now!");
        return;
    }
}

void delete_user(twitter *ts, user *curruser)
{
    Userptr tmp;
    tmp = ts->headptr;
    if(curruser == ts->headptr)
    {
        ts->headptr = curruser->nextptr;
        free(curruser);
        return;
    }
    while(strcasecmp(tmp->nextptr->username, curruser->username) != 0){
        tmp = tmp->nextptr;
    }
    tmp->nextptr = curruser->nextptr;
    sub_delete(ts, curruser);
    free(curruser);
}
void sub_delete(twitter *ts, user *curruser)
{
    char tmpuser[USR_LENGTH];
    for(int i = 0; i < curruser->num_followers; i++){
        strcpy(tmpuser,curruser->followers[i]);
        userPtr tmpptr = ts->headPtr;
        while(strcasecmp(tmpptr->username,tmpuser)!=0)
        {
            tmpptr = tmpptr->nextptr;
        }
        int k = 0;
        while(strcasecmp(tmpptr->following[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_following; o++){
            strcpy(tmpptr->following[k],tmpptr->following[o]);
            k++;
        }
        tmpptr->num_following--;
    }
    for(int i = 0; i < curruser->num_following; i++){
        strcpy(tmpuser,curruser->following[i]);
        userPtr tmpptr = ts->headPtr;
        while(strcasecmp(tmpptr->username,tmpuser)!=0){
            tmpptr = tmpptr->nextptr;
        }
        int k = 0;
        while(strcasecmp(tmpptr->followers[k],curruser->username)!=0){
            k++;
        }
        for(int o = k+1; o < tmpptr->num_followers; o++){
            strcpy(tmpptr->followers[k],tmpptr->followers[o]);
            k++;
        }
        tmpptr->num_followers--;
    }

    if(ts->tweetHeadPtr == NULL){
        return;
    }
    tweetPtr currtweet = ts->tweetHeadPtr;
    tweetPtr prevtweet = ts->tweetHeadPtr->nextPtr;
    while(currtweet != NULL){
        if(strcasecmp(curruser->username,currtweet->user) == 0){
            if(currtweet == ts->tweetHeadPtr){
                ts->tweetHeadPtr = currtweet->nextPtr;
                free(currtweet);
                currtweet = ts->tweetHeadPtr->nextPtr;
                continue;
            }
            prevtweet->nextPtr = currtweet->nextPtr;
            free(currtweet);
            currtweet = prevtweet->nextPtr;
            continue;
        }
        prevtweet = currtweet;
        currtweet = currtweet->nextPtr;
    }
}
void unfollow(twitter *ts, user *ptr)
{
    char name[USR_LENGHT];
    char null[USR_LENGHT];
    Userptr currptr;
    currptr = ts->headptr;
    for(int j = 0; j < USR_LENGHT; j++)
    {
        null[j] = '\0';
    }
    printf("\nEnter username of the user you would like to unfollow:\n");
    fflush(stdin);
    fgets(name,USR_LENGHT,stdin);
    if(name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    int i, check = 0;
    for(i = 0; ptr->num_following; i++){
        if(strcmp(ptr->following[i], name) == 0)
        {
            strcpy(ptr->following[i], null);
            ptr->num_following--;
            check = 1;
            break;
        }
    }
    if(check == 0)
    {
        printf("Error, entered user not found.\n"
               "You do not follow this User.\n");
        return;
    }
    while(currptr->nextptr != NULL)
    {
        if(strcasecmp(currptr->username, name) == 0){
            break;
        }
        currptr = currptr->nextptr;
    }
    for(int k = 0; k < currptr->num_followers; k++){
        if(strcmp(currptr->followers[i], ptr->username) == 0){
            strcpy(currptr->followers[i], null);
            currptr->num_followers--;
            break;
        }
    }
}
