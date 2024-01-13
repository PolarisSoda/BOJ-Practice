#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    int left;
    int right;
    int where;
    ll val;
};

constexpr int LEN = 1001;
constexpr int INF = 0x7FFFFFFF;
ll DP[LEN][LEN][2];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=0; i<LEN; i++) for(int j=0; j<LEN; j++) DP[i][j][0] = DP[i][j][1] = INF;

    int N,L;
	cin >> N >> L;
    
    int idx = 0;
    vector<int> arr;
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        if(temp < L) idx++;
        arr.push_back(temp);
    }
    arr.push_back(L);
    sort(arr.begin(),arr.end());
    queue<info> task;
    task.push({idx,idx,0,0});

    while(!task.empty()) {
        int left = task.front().left;
        int right = task.front().right;
        int where = task.front().where;
        ll val = task.front().val;
        task.pop();

        if(val > DP[left][right][where]) continue;
        DP[left][right][where] = val;
        if(left != 0) {
            ll dist = arr[where == 0 ? left : right] - arr[left-1];
            ll cnt = N - (right-left);
            task.push({left-1,right,0,val + dist*cnt});
        }
        if(right != N) {
            ll dist = arr[right+1] - arr[where == 0 ? left : right];
            ll cnt = N - (right-left);
            task.push({left,right+1,1,val+dist*cnt});
        }
    }
    cout << min(DP[0][N][0],DP[0][N][1]);
    exit(0);
}
