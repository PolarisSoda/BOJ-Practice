#include <bits/stdc++.h>

using namespace std;

int dx[9] = {0,0,1,1,1,0,-1,-1,-1};
int dy[9] = {0,1,1,0,-1,-1,-1,0,1};
int check[9];
int N,K,R,C;

bool Approx(int x,int y) {
    return x>=1 && x<=N && y>=1 && y<=N;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K >> R >> C;

    for(int i=0; i<K; i++) {
        int r,c;
        cin >> r >> c;
        
        for(int j=0; j<9; j++) {
            int nx = R + dx[j], ny = C + dy[j];
            check[j] |= nx == r || ny == c || abs(nx-r) == abs(ny-c);
        }
    }

    int cnt = 0, total = 0;
    for(int i=1; i<9; i++) {
        if(Approx(R+dx[i],C+dy[i])) {
            total++;
            cnt += check[i];
        }
    }
    
    if(check[0]) cout << (cnt == total ? "CHECKMATE" : "CHECK");
    else cout << (cnt == total ? "STALEMATE" : "NONE");
}