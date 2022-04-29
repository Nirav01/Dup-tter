#include "twitter_create.h"
#include "Menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void create_twitter_system(twitter * ts) 
{
    Userptr currptr;
    ts->headptr = NULL;
    ts->tweetheadptr = NULL;
    for (int i = 0; i < MAX_USERS; i++) 
    {
        Userptr newptr = malloc(sizeof(user));
        if (newptr != NULL) {
            printf("\nEnter username of the next user or press 'tab key' then 'Enter' to exit:\n");
            fgets(newptr->username, USR_LENGHT, stdin);
            fflush(stdin);
            if (newptr->username[0] == ' ') 
            {
                printf("(Do not start username with a 'Space'!!!)");
                i--;
                continue;
            }
            if (newptr->username[0] == '\t') 
            {
                break;
            }
            if (newptr->username[strlen(newptr->username) - 1] == '\n') 
            {
                newptr->username[strlen(newptr->username) - 1] = '\0';
            }
            newptr->num_followers = 0;
            newptr->num_following = 0;
            newptr->nextptr = NULL;
        }
        if (ts->headptr == NULL) 
        {
            ts->headptr = newptr;
        } 
        else 
        {
            currptr = ts->headptr;
            while (currptr->nextptr != NULL) 
            {
                currptr = currptr->nextptr;
            }
            currptr->nextptr = newptr;
        }
    }
    currptr = ts->headptr;
    while (currptr != NULL) 
    {
        printf("User: %s  \t\tfollowing: %d\tfollowers: %d\n", currptr->username, currptr->num_followers,
               currptr->num_followers);
        currptr = currptr->nextptr;
    }
    currptr = ts->headptr;
    int control;
    while (1) 
    {
        printf("\n\nCurrent User: %s\n", currptr->username);
        control = menu(ts, currptr);
        if (control == 6) {
            if (currptr->nextptr == NULL) 
            {
                currptr = ts->headptr;
            } 
            else 
            {
                currptr = currptr->nextptr;
            }
            continue;
        } 
        else if (control == 7) 
        {
            break;
        }
    }
}