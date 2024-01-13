#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

bool DP[51][1001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,S;
    cin >> N >> S;

    queue<pii> task;
    task.push({2,0});
    
    while(!task.empty()) {
        int nn = task.front().first;
        int ns = task.front().second;
        task.pop();
        if(nn == N && ns == S) {
            cout << 1;
            exit(0);
        }
        if(DP[nn][ns] == true || nn == N || ns > S) continue;
        DP[nn][ns] = true;
        for(int i=1; i<=N-nn; i++) task.push({nn+i,ns+i*(i+1)/2});
    }
    cout << 0;
    exit(0);
}