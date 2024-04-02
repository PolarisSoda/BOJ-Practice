#include <bits/stdc++.h>

using namespace std;

struct info {
    int s,e,x;
};

constexpr int LEN = 301;
vector<info> edge;
int pt[LEN];

bool compare(info a,info b) {
    return a.x < b.x;
}
int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}
void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int W;
        cin >> W;
        edge.push_back({i,0,W});
        pt[i] = i;
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
        int W;
        cin >> W;
        if(i < j) edge.push_back({i,j,W});
    }

    sort(edge.begin(),edge.end(),compare);
    int sum = 0, ecnt = 0;
    for(info now : edge) {
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            sum += now.x;
            if(++ecnt == N) break;
        }
    }
    cout << sum;
    exit(0);
}