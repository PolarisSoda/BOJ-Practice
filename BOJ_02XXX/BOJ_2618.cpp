#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

int N,W;
int DPLC[1001][1001] = {};
ll DP[1001][1001] = {};
pair<int,int> BT[1001][1001] = {};
vector<pair<int,int>> location;

ll LDynamic(int f,int s,int bias) {
    int fx,fy,sx,sy;
    fx = location[f].first;
    fy = location[f].second;
    sx = location[s].first;
    sy = location[s].second;
    if(f == 0 && bias == 2) {
        fx = N;
        fy = N;
        return abs(fx-sx) + abs(fy-sy);
    }
    if(DPLC[f][s] != 0) {
        return DPLC[f][s];
    }
    DPLC[f][s] = abs(fx-sx) + abs(fy-sy);
    return DPLC[f][s];
}

ll Dynamic(int first,int second) {
    if(DP[first][second] != -1) {
        return DP[first][second];
    }
    if(first > second) {
        if(first - 1 == second) {
            DP[first][second] = Dynamic(0,second) + LDynamic(0,first,1);
            BT[first][second] = {0,second};
            for(int i=1; i<second; i++) {
                ll temp = Dynamic(i,second) + LDynamic(i,first,1);
                if(DP[first][second] > temp) {
                    DP[first][second] = temp;
                    BT[first][second] = {i,second};
                }
            }
        } else {
            DP[first][second] = Dynamic(first-1,second) + LDynamic(first-1,first,1);
            BT[first][second] = {first-1,second};
        }
    } else {
        if(second - 1 == first) {
            
            DP[first][second] = Dynamic(first,0) + LDynamic(0,second,2);
            BT[first][second] = {first,0};
            for(int i=1; i<first; i++) {
                ll temp = Dynamic(first,i) + LDynamic(i,second,2);
                if(DP[first][second] > temp) {
                    DP[first][second] = temp;
                    BT[first][second] = {first,i};
                }
            }
        } else {
            DP[first][second] = Dynamic(first,second-1) + LDynamic(second-1,second,2);
            BT[first][second] = {first,second-1};
        }
    }
    return DP[first][second];
}

int main() {
    cin >> N >> W;
    location.push_back({1,1});
    for(int i=0; i<W; i++) {
        int x,y;
        cin >> x >> y;
        location.push_back({x,y});
    }
    for(int i=0; i<=W; i++) {
        for(int j=0; j<=W; j++) {
            DP[j][i] = -1;
        }
    }
    DP[0][0] = 0;
    DP[0][1] = 2*N - location[1].first - location[1].second;
    BT[0][1] = {0,0};
    ll ans = 1000000000;
    int x,y;
    for(int i=0; i<W; i++) {
        ll temp = Dynamic(W,i);
        ll temp2 = Dynamic(i,W);
        if(ans > temp) {
            ans = temp;
            x = W;
            y = i;
        }
        if(ans > temp2) {
            ans = temp2;
            x = i;
            y = W;
        }
    }
    deque<int> answer;
    while(true) {
        if(x == 0 && y == 0) {
            break;
        }
        int nx = BT[x][y].first;
        int ny = BT[x][y].second;
        if(x == nx) {
            answer.push_front(2);
        } else {
            answer.push_front(1);
        }
        x = nx;
        y = ny;
    }
    cout << ans << "\n";
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    
}