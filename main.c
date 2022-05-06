#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"



int main()//function to call the twitter system
{

    twitter twitterSystem;
    createTwitterSystem(&twitterSystem); //calling the function

    userPtr currentPtr = twitterSystem.headPtr; //calling the headPtr inside the twitter system
    printf("Last Active Users on the System:\n");
    puts("--------------------------------------------------------------------------");
    if(twitterSystem.headPtr == NULL)
    {
        exit(EXIT_SUCCESS);
    }
    // prints out all the users // linked list style
    while(currentPtr != NULL)
    {
        printf("User:%s\t\t  Following:%d\t    Followers:%d\n", currentPtr->username, currentPtr->numFollowing, currentPtr->numFollowers);
        currentPtr = currentPtr->nextPtr;
    }
    return 0;

}