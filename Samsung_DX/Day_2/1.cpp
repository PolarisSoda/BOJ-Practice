#include <iostream>
#include <vector>

using namespace std;

constexpr int LEN = 101;
vector<int> edge[LEN];
char arr[LEN];

void DFS(int num) {
    if(edge[num].size() > 0) DFS(edge[num][0]);
    cout << arr[num];
    if(edge[num].size() > 1) DFS(edge[num][1]);
}
void solve() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int ND,L,R;
        char C;
        cin >> ND >> C;
        arr[ND] = C;
        if(ND<<1 <= N) {
            cin >> L;
            edge[ND].push_back(L);
        }
        if((ND<<1|1) <= N) {
            cin >> R;
            edge[ND].push_back(R);
        }
    }
    DFS(1);
    cout << "\n";
    for(int i=0; i<LEN; i++) edge[i] = vector<int>();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<=10; i++) cout << "#" << i << " ", solve();
    return 0;
}