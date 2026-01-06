#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,M;
    scanf("%d %d",&N,&M);
    printf("%d",N/M+(N%M!=0));
}