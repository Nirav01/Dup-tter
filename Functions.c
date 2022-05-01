
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