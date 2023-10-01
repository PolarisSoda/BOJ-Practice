#include <bits/stdc++.h>
#define LEN 10001

using namespace std;

typedef pair<int,int> pii;

struct info {
    int s,e,x,n;
};
int pt[LEN];
vector<info> edge;
bool used[300001];

bool compare(info a,info b) {
    return a.x < b.x;
}

int root(int a) {
    if(pt[a] == a)
        return a;
    return pt[a] = root(pt[a]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b)
        pt[b] = a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0; i<M; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge.push_back({A,B,C,i});
    }
    for(int i=1; i<=N; i++) pt[i] = i;
    sort(edge.begin(),edge.end(),compare);
    
    int ecnt = 0;
    for(int i=0; i<M; i++) {
        info now = edge[i];
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            cout << now.n << " ";
            used[now.n] = true;
            if(++ecnt == N-1) break;
        }
    }
    for(int i=0; i<M; i++) {
        if(used[i])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
    return 0;
}
