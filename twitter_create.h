#ifndef PROJECT2_TWITTER_CREATE_H
#define PROJECT2_TWITTER_CREATE_H

//Max length of a tweet
#define TWEET_LENGTH 270

//Max length of a username
#define USR_LENGTH 100

//Max num of a followers
#define MAX_FOLLOWERS 30

//Max num of following users
#define MAX_FOLLOWING 30

//Max num of users
#define MAX_USERS 100

typedef struct tweet//defining struct for tweets data
{
    int id;
    char message[TWEET_LENGTH];
    char user[USR_LENGTH];
    struct tweet *nextPointer;
}tweet;

typedef tweet *tweetPtr;

typedef struct user//struct for user data
{
    char username[USR_LENGTH];

    char followers[MAX_FOLLOWERS][USR_LENGTH];
    int numFollowers;

    char following[MAX_FOLLOWING][USR_LENGTH];
    int numFollowing;

    struct user *nextPtr;
}user;

typedef user *userPtr;


typedef struct twitter
{
    userPtr headPtr;
    tweetPtr tweetHeadPtr;
} twitter;

void createTwitterSystem(twitter * twitterSystem);//function prototype

#endif //PROJECT2_TWITTER_CREATE_H