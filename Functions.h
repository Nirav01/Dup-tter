

#ifndef ENGPROJECT2_FUNCTIONS_H
#define ENGPROJECT2_FUNCTIONS_H

#include "twitter_create.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void follow(twitter *twitterSystem, user *ptr);

void unfollow(twitter *twitterSystem, user *ptr);

void deleteUser(twitter *twitterSystem, user *currentUser);

void subDelete(twitter *twitterSystem, user *currentUser);

#endif //ENGPROJECT2_FUNCTIONS_H
