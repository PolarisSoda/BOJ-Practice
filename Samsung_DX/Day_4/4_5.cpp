#include <bits/stdc++.h>

using namespace std;

struct info {
    int pID,ts,like;
};

constexpr int LEN = 1001;
int follow[LEN][LEN];

void init(int N) {
    memset(follow,-1,sizeof(follow));

}

void follow(int uID1, int uID2, int timestamp) {
    
}

void makePost(int uID, int pID, int timestamp)
{
}

void like(int pID, int timestamp)
{
}

void getFeed(int uID, int timestamp, int pIDList[])
{
}