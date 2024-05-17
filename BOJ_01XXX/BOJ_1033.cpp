#include <bits/stdc++.h>

using namespace std;

vector<int> edge[10];
int ret[10];

int gcd(int a,int b) {
    int r = a%b;
    if (r == 0) return b;
    return gcd(b,r);
}
void DFS(int now,int prev,int num) {
    ret[now] *= num;
    for(int next : edge[now]) if(next != prev) DFS(next,now,num);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) ret[i] = 1;
    for(int i=0; i<N-1; i++) {
        int A,B,P,Q;
        cin >> A >> B >> P >> Q;
        int RA = ret[A] * Q;
        int RB = ret[B] * P;
        int G = gcd(RA,RB);
        edge[A].push_back(B);
        edge[B].push_back(A);
        DFS(A,B,RB/G);
        DFS(B,A,RA/G);
    }
    for(int i=0; i<N; i++) cout << ret[i] << " ";
    exit(0);
}