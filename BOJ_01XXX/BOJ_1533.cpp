#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

constexpr ll DIV = 1000003;

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
//i, i+1, i+2, i+3, i+4
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,S,E,T;
    cin >> N >> S >> E >> T;
    S--, E--;

    matrix graph(N*5,vector<ll>(N*5,0));
    for(int i=0; i<N; i++) for(int j=1; j<5; j++) graph[i*5+j-1][i*5+j] = 1;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        char temp;
        cin >> temp;
        int t = temp - '0';
        if(t == 0) continue;
        graph[i*5+4][j*5+(5-t)] = 1;
    }

    graph = power(graph,T);
    cout << graph[S*5+4][E*5+4];
}