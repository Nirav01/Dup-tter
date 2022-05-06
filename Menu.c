#include "twitter_create.h"
#include "Functions.h"
#include "Menu.h"
#include "tweets.h"
#include <stdio.h>

int menu(twitter *twitterSystem, user *sPtr)//printing options available to current user
{
    int choice = -1;
    puts("Choose an action: (by entering the corresponding number)");
    printf("Post tweet: \t\t 1\n");
    printf("get News Feed:\t\t 2\n");
    printf("follow others:\t\t 3\n");
    printf("unfollow users:\t\t 4\n");
    printf("Delete your account:\t 5\n");
    printf("End current user's turn: 6\n");
    printf("End twitter system:\t 7\n");
    //calling functions according to user choice
    while(choice != 0)
    {
        printf("Enter (next) choice:\n");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
            case 1:
                postTweet(twitterSystem,sPtr);
                return 1;
            case 2:
                getNewsFeed(twitterSystem, sPtr);
                return 2;
            case 3:
                follow(twitterSystem, sPtr);
                return 3;
            case 4:
                unfollow(twitterSystem, sPtr);
                return 4;
            case 5:
                deleteUser(twitterSystem, sPtr);
                return 6;
            case 6:
                return 6;
            case 7:
                return 7;
            default:
                printf("Error! Not an option!\n");
                continue;
        }
    }
    printf("Program will Self-Destruct now! Bye User:%s\n", sPtr->username);
    return 7;
}