#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

constexpr ll DIV = 1000;

matrix operator * (const matrix &a,const matrix &b) {
    int sz = a.size();
    matrix ret(sz,vector<ll>(sz));
    
    for(int i=0; i<sz; i++) { 
		for(int j=0; j<sz; j++) {
			for(int k=0; k<sz; k++) {
				ret[i][j] += a[i][k]*b[k][j];
				ret[i][j] %= DIV;
			}
		}
	}
    return ret;
}
matrix power(matrix X,ll P) {
    int sz = X.size();
    matrix ret(sz,vector<ll>(sz));
    for(int i=0; i<sz; i++) ret[i][i] = 1;
    while(P) {
        if(P&1LL) ret = ret*X;
        X = X*X;
        P >>= 1LL;
    }
    return ret;
}

string solve() {
    matrix graph;
    graph.push_back({6,-4}),graph.push_back({1,0});

    ll N;
    cin >> N;
    matrix ret = power(graph,N-1);
    ll temp = (6*((ret[0][0]+DIV)%DIV)+2*((ret[0][1]+DIV)%DIV)+DIV-1)%DIV;
    string ans = to_string(temp);
    while(ans.length() < 3) ans = "0" + ans;
    return ans;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "Case #" << i << ": " << solve() << "\n";
    exit(0); 
}