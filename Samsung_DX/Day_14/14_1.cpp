#define MAX_ROW 40
#define MAX_COL 30
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct Result {
    int row,col;
};

constexpr int INF = 0x7FFFFFF;
constexpr int TYPE = 5;
const vector<vector<pii>> pattern = {
	{{0,0}, {0,1}, {1,1}, {2,1}, {2,2}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {0,2}},
	{{0,0}, {1,0}, {2,0}},
	{{0,0}, {1,0}}
};

vector<pii> pq[5][1<<15];
int H, W;
bool used[MAX_COL][MAX_ROW];

bool Approx(int X,int Y) {
    if(X>=0 && X<W && Y>=0 && Y<H) return true;
    return false;
}

void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL]) {
    H = mRows, W = mCols;
    memset(used,false,sizeof(used));
    for(int i=0; i<5; i++) for(int j=0; j<(1<<15); j++) pq[i][j].clear();

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            for(int k=0; k<TYPE; k++) {
                int minv = 5;
                int kv = 0;
                for(pii tt : pattern[k]) {
                    int nx = j+tt.first;
                    int ny = i+tt.second;
                    if(Approx(nx,ny)) minv = min(minv,mCells[ny][nx]);
                    else goto skip;
                }
                for(pii tt: pattern[k]) {
                    int nx = j+tt.first;
                    int ny = i+tt.second;
                    int temp = mCells[ny][nx] - minv;
                    kv <<= 3;
                    kv += temp;
                }
                pq[k][kv].push_back({j,i});
                skip:
                continue;
            }
        }
    }
}

Result putPuzzle(int P[3][3]) {
    int type = -1;
	for (int i=0; i<TYPE; i++) {
        bool check = false;
        for(pii tt : pattern[i]) {
            if(P[tt.second][tt.first] == 0) {
                check = true;
                break;
            }
        }
        if(!check) {
            type = i;
            break;
        }
	}
	int minv = 5;
    for(pii tt : pattern[type]) minv = min(minv,P[tt.second][tt.first]);

	int kv = 0;
	for(pii tt: pattern[type]) {
        int temp = P[tt.second][tt.first] - minv;
        kv <<= 3;
        kv += temp;
    }

    Result ret = {-1,-1};
    for(pii cand : pq[type][kv]) {
        bool checker = false;
        int ox = cand.first;
        int oy = cand.second;
        for(pii tt : pattern[type]) checker |= used[ox+tt.first][oy+tt.second];
        if(checker) continue;
        ret = {cand.second,cand.first};
        for(pii tt : pattern[type]) used[ox+tt.first][oy+tt.second] = true;
        return ret;
    }
    return ret;
}

void clearPuzzles() {
    memset(used,false,sizeof(used));
}