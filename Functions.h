

#ifndef ENGPROJECT2_FUNCTIONS_H
#define ENGPROJECT2_FUNCTIONS_H

#include "twitter_create.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void follow(twitter *ts, user *ptr); 

void unfollow(twitter *ts, user *ptr); 

void delete_user(twitter *ts, user *curruser); 

void sub_delete(twitter *ts, user *curruser);

#endif //ENGPROJECT2_FUNCTIONS_H
