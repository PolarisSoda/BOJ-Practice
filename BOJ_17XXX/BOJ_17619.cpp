#include <bits/stdc++.h>

using namespace std;

struct wood {
    int L,R,idx;
};

constexpr int LEN = 100001; 
vector<wood> V;
int pt[LEN];

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

bool compare(const wood A,const wood B) {
    if(A.L == B.L) return A.R > B.R;
    return A.L < B.L;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,Q;
    cin >> N >> Q;

    for(int i=1; i<=N; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        V.push_back({A,B,i});
        pt[i] = i;
    }
    sort(V.begin(),V.end(),compare);
    
    int parent = -1, right = -1;
    for(int i=0; i<N; i++) {
        if(V[i].L > right) parent = V[i].idx, right = max(right,V[i].R);
        else right = max(right,V[i].R), uni(parent,V[i].idx);
    }

    for(int i=0; i<Q; i++) {
        int A,B;
        cin >> A >> B;
        if(root(A) != root(B)) cout << "0\n";
        else cout << "1\n";
    }
    exit(0);
}