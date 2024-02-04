#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 200001;
int pt[LEN];
int pt_query[LEN];
vector<pii> Query;
vector<bool> ANS;

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

    int N,Q;
    cin >> N >> Q;
    for(int i=1; i<=N; i++) pt[i] = i;
    for(int i=2; i<=N; i++) {
        int A;
        cin >> A;
        pt_query[i] = A;
    }
    for(int i=0; i<Q+N-1; i++) {
        int X,A,B;
        cin >> X;
        if(X == 0) {
            cin >> A;
            Query.push_back({-1,A});
        } else {
            cin >> A >> B;
            Query.push_back({A,B});
        }
    }
    for(auto it=Query.rbegin(); it!=Query.rend(); it++) {
        if(it->first == -1) {
            int now = it->second;
            uni(pt_query[now],now);
        } else {
            int a = it->first;
            int b = it->second;
            ANS.push_back(root(a) == root(b));
        }
    }
    for(auto it=ANS.rbegin(); it!=ANS.rend(); it++) cout << (*it == true ? "YES\n" : "NO\n");
    exit(0);
}