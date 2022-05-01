
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