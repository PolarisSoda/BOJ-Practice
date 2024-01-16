#include <iostream>
#include <vector>

using namespace std;

constexpr int LEN = 201;
vector<int> edge[LEN];
int arr[LEN];

int solve() {
    for(int i=0; i<LEN; i++) edge[i] = vector<int>();

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int ND,L,R;
        string ctx;
        cin >> ND >> ctx;

        if(ctx[0] >= 48 && ctx[0] <= 57) arr[ND] = 1;
        else arr[ND] = 0;

        if(ND<<1 <= N) {
            cin >> L;
            edge[ND].push_back(L);
        }
        if((ND<<1|1) <= N) {
            cin >> R;
            edge[ND].push_back(R);
        }
    }
    for(int i=1; i<=N; i++) {
        if(arr[i] == 1) {
            if(edge[i].size() == -1) return 0;
        } else {
            if(edge[i].size() != 2) return 0;
        }
    }
    return 1;
    
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<=10; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}