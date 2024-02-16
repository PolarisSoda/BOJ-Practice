#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct tank {
    int x,y,idx;
};

vector<tank> plat;
vector<pair<int,char>> ans;
bool rev;

bool compare(tank a,tank b) {
    if(rev) {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    } else {
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int X,Y;
        cin >> Y >> X;
        plat.push_back({X,Y,i+1});
    }

    sort(plat.begin(),plat.end(),compare);
    vector<pii> temp[2];

    for(int i=0; i<N; i++) {
        int idx = i+1;
        if(plat[i].x > idx) temp[0].push_back({i,idx}); //왼쪽으로
        if(plat[i].x < idx) temp[1].push_back({i,idx}); //오른쪽으로
    }

    for(auto it=temp[0].begin(); it!=temp[0].end(); it++) {
        int idx = it->first;
        int diff = plat[idx].x - it->second;
        for(int i=0; i<diff; i++) ans.push_back({plat[idx].idx,'L'}), plat[idx].x--;
    }
    for(auto it=temp[1].rbegin(); it!=temp[1].rend(); it++) {
        int idx = it->first;
        int diff = it->second - plat[idx].x;
        for(int i=0; i<diff; i++) ans.push_back({plat[idx].idx,'R'}), plat[idx].x++;
    }

    rev = true;
    sort(plat.begin(),plat.end(),compare);

    for(int i=0; i<N; i++) {
        int idx = i+1;
        if(plat[i].y > idx) {
            int diff = plat[i].y - idx;
            for(int j=0; j<diff; j++) ans.push_back({plat[i].idx,'U'});
        }
        if(plat[i].y < idx) {
            int diff = idx - plat[i].y;
            for(int j=0; j<diff; j++) ans.push_back({plat[i].idx,'D'});
        }
    }
    cout << ans.size() << "\n";
    for(auto t : ans) cout << t.first << " " << t.second << "\n";
    exit(0);
}