#include <bits/stdc++.h>

using namespace std;

struct info {
    int s,e,x;
};

constexpr int LEN = 1001;
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

    int N,M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge.push_back({A,B,C});
    }

    sort(edge.begin(),edge.end(),compare);
    int sum = 0, ecnt = 0;
    for(info now : edge) {
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            sum += now.x;
            if(++ecnt == N-1) break;
        }
    }
}