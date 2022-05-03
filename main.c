
#include <stdio.h>
#include <stdlib.h>
#include "twitter_create.h"



int main() {

    twitter ts;
    create_twitter_system(&ts); //calling the function

    Userptr currptr = ts.headptr; //calling the headptr inside the twitter system
    printf("Last Active Users on the System:\n");
    puts("--------------------------------------------------------------------------");
    if(ts.headptr == NULL)
    {
        exit(EXIT_SUCCESS);
    }
    // prints out all the users // linked list style
    while(currptr != NULL){
        printf("User:%s\t\t  Following:%d\t    Followers:%d\n", currptr->username, currptr->num_following, currptr->num_followers);
        currptr = currptr->nextptr;
    }
    return 0;

}
