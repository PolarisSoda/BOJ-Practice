#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> info;

constexpr int LEN = 45;
constexpr int INF = 0x1010101;
vector<int> edge[LEN];
int dist[LEN][LEN][LEN];
info pt[LEN][LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<LEN; i++) for(int j=1; j<LEN; j++) for(int k=1; k<LEN; k++) dist[i][j][k] = INF, pt[i][j][k] = {i,j,k};

    int N,M,A,B,C;
    cin >> N >> M >> A >> B >> C;
    for(int i=0; i<M; i++) {
        int S,E;
        cin >> S >> E;
        edge[S].push_back(E);
    }

    int ans = -1, dd = -1;
    queue<pair<info,int>> task;
    task.push({{A,B,C},0});
    while(!task.empty()) {
        int P,D,A;
        tie(P,D,A) = task.front().first;
        int total = task.front().second;
        task.pop();

        if(dist[P][D][A] < total) continue;
        dist[P][D][A] = total;

        if(P == D && D == A) {
            ans = P, dd = total;
            break;
        }
        
        for(int np : edge[P]) {
            for(int nd : edge[D]) {
                for(int na : edge[A]) {
                    if(dist[np][nd][na] > total + 1) {
                        dist[np][nd][na] = total+1;
                        pt[np][nd][na] = {P,D,A};
                        task.push({{np,nd,na},total+1});
                    }
                }
            }
        }
    }
    cout << ans;
    if(ans == -1) exit(0);
    cout << " " << dd << "\n";

    int np = ans, nd = ans, na = ans;
    vector<int> a[3];
    while(true) {
        a[0].push_back(np);
        a[1].push_back(nd);
        a[2].push_back(na);
        int pp,pd,pa;
        tie(pp,pd,pa) = pt[np][nd][na];
        if(pp == np && pd == nd && pa == na) break;
        np = pp, nd = pd, na = pa;
    }
    for(int i=0; i<3; i++) {
        for(auto it=a[i].rbegin(); it!=a[i].rend(); it++) cout << *it << " ";
        cout << endl;
    }
}