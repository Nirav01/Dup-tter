//importing useful header files and library
#include "tweets.h"
#include "twitter_create.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"

void postTweet(twitter *twitterSystem, user* ptr)//function to post tweets by current user
{
    tweetPtr currentPtr = malloc(sizeof(struct tweet));//allocating dynamic memory for new tweet
    printf("What's on your mind?\n");
    fgets(currentPtr->message, TWEET_LENGTH,stdin);//taking tweet(message) input
    fflush(stdin);
    if(currentPtr->message[strlen(currentPtr->message) - 1] == '\n')
    {
        currentPtr->message[strlen(currentPtr->message) - 1] = '\0';     }//terminating message with '\0'
    strcpy(currentPtr->user,ptr->username);
    //connecting nodes of struct
    if(twitterSystem->tweetHeadPtr == NULL)
    {
        twitterSystem->tweetHeadPtr=currentPtr;
        currentPtr->nextPointer=NULL;
    }
    else
    {
        currentPtr->nextPointer=twitterSystem->tweetHeadPtr;
        twitterSystem->tweetHeadPtr= currentPtr;
    }
}
void getNewsFeed(twitter *twitterSystem, user *currentUser)//function to print tweets by current user and users followed
{
    tweetPtr currentPtr; //temp ptr
    int count = 0;
    currentPtr = twitterSystem->tweetHeadPtr;
    while(currentPtr != NULL)
    {
        if(currentUser->numFollowing>0)//checking if user follow anyone
        {
            for (int i = 0; i < currentUser->numFollowing; i++)
            {
                if (strcasecmp(currentPtr->user, currentUser->following[i]) == 0 ||strcasecmp(currentPtr->user, currentUser->username) == 0)
                {//printing tweets by users followed
                    count++;//keeping count of number of tweets displayed
                    printf("%s\n", currentPtr->message);
                    printf("%d\n", currentPtr->id);
                }
            }
        }
        else
        {
            if(strcasecmp(currentPtr->user, currentUser->username)==0)//printing user messages
            {
                count++;
                printf("%s\n", currentPtr->message);
            }
        }
        if(count==10)//for maximum 10 tweets to be displayed
        {
            break;
        }
        currentPtr = currentPtr->nextPointer;
    }
}