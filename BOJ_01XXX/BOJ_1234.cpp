#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll DP[11][101][101][101];
ll fact[11];
int N,R,G,B;

ll Dynamic(int l,vector<int> V) {
    ll &ret = DP[l][V[0]][V[1]][V[2]];
    if(ret != -1) return ret;
    if(l == N && V[0] + V[1] + V[2] >= 0) return ret = 1;

    int now = l+1;
    ll temp = 0;
    for(int i=0; i<3; i++) if(V[i] >= now) {
        vector<int> vt(V);
        vt[i] -= now;
        temp += Dynamic(now,vt);
    }
    if(now%2 == 0) {
        for(int i=0; i<2; i++) {
            for(int j=i+1; j<3; j++) {
                if(V[i] >= now/2 && V[j] >= now/2) {
                    vector<int> vt(V);
                    vt[i] -= now/2, vt[j] -= now/2;
                    ll bias = fact[now]/(fact[now/2]*fact[now/2]);
                    temp += bias*Dynamic(now,vt);
                }
            }
        }
    }
    if(now%3 == 0) {
        if(V[0] >= now/3 && V[1] >= now/3 && V[2] >= now/3) {
            vector<int> vt(V);
            vt[0] -= now/3, vt[1] -= now/3, vt[2] -= now/3;
            ll bias = fact[now]/(fact[now/3]*fact[now/3]*fact[now/3]);
            temp += bias*Dynamic(now,vt);
        }
    }
    return ret = temp;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> R >> G >> B;

    fact[0] = 1;
    for(int i=1; i<=10; i++) fact[i] = fact[i-1]*i;

    memset(DP,-1,sizeof(DP));
    cout << Dynamic(0,{R,G,B});
    exit(0);
}