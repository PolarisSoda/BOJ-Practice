#include <iostream>
#include <vector>

using namespace std;

constexpr int LEN = 1001;
vector<int> edge[LEN];
string arr[LEN];

double Trav(int num) {
    if(arr[num][0] >= 48 && arr[num][0] <= 57) return stod(arr[num]);
    switch(arr[num][0]) {
        case '+':
            return Trav(edge[num][0]) + Trav(edge[num][1]);
        case '-':
            return Trav(edge[num][0]) - Trav(edge[num][1]);
        case '*':
            return Trav(edge[num][0]) * Trav(edge[num][1]);
        default:
            return Trav(edge[num][0]) / Trav(edge[num][1]);
    }
}
int solve() {
    for(int i=0; i<LEN; i++) edge[i] = vector<int>();

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int ND,L,R;
        string ctx;
        cin >> ND >> ctx;
        arr[ND] = ctx;
        if(ctx[0] < 48 || ctx[0] > 57) {
            cin >> L >> R;
            edge[ND].push_back(L);
            edge[ND].push_back(R);
        }
    }
    double ret = Trav(1);
    return (int)ret;
    
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=1; i<=10; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}