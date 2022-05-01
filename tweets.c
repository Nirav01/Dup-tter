 
#include "tweets.h"
#include "twitter_create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

void posttweet(twitter *ts, user* ptr)
{
    Tweetptr currptr = malloc(sizeof(struct tweet));
    printf("What's on your mind?\n");
    fgets(currptr->msg, TWEET_LENGTH,stdin);
    fflush(stdin);
    if(currptr->msg[strlen(currptr->msg) - 1] == '\n') {
        currptr->msg[strlen(currptr->msg) - 1] = '\0';     }
    strcpy(currptr->user,ptr->username);
    if(ts->tweetheadptr == NULL){
        ts->tweetheadptr=currptr;
        currptr->nextpointer=NULL;
    }
    else
    {
        currptr->nextpointer=ts->tweetheadptr;
        ts->tweetheadptr= currptr;
    }
}
void getNewsFeed(twitter *ts, user *currUser)
{
    tweetPtr currptr; //temp ptr
    int count = 0;
    currptr = ts->tweetHeadPtr;
    while(currptr != NULL)
    {
        if(currUser->num_following>0) {
            for (int i = 0; i < currUser->num_following; i++) {
                if (strcasecmp(currptr->user, currUser->following[i]) == 0 ||strcasecmp(currptr->user, currUser->username) == 0)
                {
                    count++;
                    printf("%s\n", currptr->msg);
                    //                printf("%d\n", currptr->id);
                }
            }
        }
        else
        {
            if(strcasecmp(currptr->user, currUser->username)==0)
            {
                count++;
                printf("%s\n", currptr->msg);
            }
        }
        if(count==10)
        {
            break;
        }
        currptr = currptr->nextPtr;
    }
}