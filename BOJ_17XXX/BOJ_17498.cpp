#include <iostream>
#include <vector>
#include <algorithm>
#define nocalc 200000000000000

using namespace std;

typedef long long int ll;

vector<vector<ll>> DP;
vector<vector<int>> PF;
int N,M,D;

ll Dynamic(int width,int height) {
    if(DP[width][height] != nocalc) {
        return DP[width][height];
    }
    
    ll ans = -99999999999999;
    
    for(int i=1; i<=D; i++) {
        if(width-i == 0) {
            break;
        }
        int bias = D-i;
        for(int j=max(height-bias,1); j<=min(height+bias,M); j++) {
            ll temp = Dynamic(width-i,j);
            temp += PF[width-i][j] * PF[width][height];
            if(ans < temp) {
                ans = temp;
            }
        }
    }
    DP[width][height] = ans;
    return ans;
}

int main() {
	cin >> N >> M >> D;
	DP.resize(N+1);
	PF.resize(N+1);
	for(int i=0; i<=N; i++) {
	    DP[i].resize(M+1);
	    PF[i].resize(M+1);
	}
	for(int i=1; i<=N; i++) {
	    for(int j=1; j<=M; j++) {
	        cin >> PF[i][j];
	        DP[i][j] = nocalc;
	        if(i==1) {
	        	DP[i][j] = 0;
			}
	    }
	}
	ll ans = -99999999999999;
	for(int i=1; i<=M; i++) {
	    ll temp = Dynamic(N,i);
	    if(ans < temp) {
	        ans = temp;
	    }
	}
	cout << ans;
}