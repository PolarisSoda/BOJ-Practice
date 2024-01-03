#include <bits/stdc++.h>

using namespace std;

struct SCV {
    int health[3];
};

int DP[61][61][61];

int main() {
    int N;
    cin >> N;

    SCV fi;
    memset(fi.health,0,sizeof(fi.health));
    memset(DP,-1,sizeof(DP));
    for(int i=0; i<N; i++) cin >> fi.health[i];

    queue<pair<SCV,int>> task;
    task.push({fi,0});

    while(!task.empty()) {
        SCV sta = task.front().first;
        int cnt = task.front().second;
        task.pop();

        vector<int> permute = {1,3,9};

        do {
            SCV next = sta;
            for(int i=0; i<N; i++) next.health[i] = max(0,next.health[i] - permute[i]);
            int fi = next.health[0];
            int se = next.health[1];
            int th = next.health[2];
            if(DP[fi][se][th] == -1 || DP[fi][se][th] > cnt+1) {
                DP[fi][se][th] = cnt+1;
                if(fi+se+th == 0) goto FOUND;
                task.push({next,cnt+1});
            }
        } while(next_permutation(permute.begin(),permute.end()));
    }
    FOUND:
    cout << DP[0][0][0];
    exit(0);
}