#include <bits/stdc++.h>
#define MAX 0x7FFFFFFF
#define LEN 20001

using namespace std;

vector<int> edge[LEN];
bool finished[LEN];
int cnt[LEN],nscc[LEN];
stack<int> checker;
vector<vector<int>> SCC;
int dcnt,cur;

int DFS(int num) {
    cnt[num] = ++dcnt;
    checker.push(num);
    int ret = cnt[num];
    for(auto it=edge[num].begin(); it!=edge[num].end(); it++) {
        int next = *it;
        if(cnt[next] == 0)
            ret = min(ret,DFS(next));
        else if(!finished[next])
            ret = min(ret,cnt[next]);
    }
    if(ret == cnt[num]) {
        vector<int> temp;
        while(true) {
            int now = checker.top();
            checker.pop();
            temp.push_back(now);
            finished[now] = true;
            nscc[now] = cur;
            if(now == num)
                break;
        }
        SCC.push_back(temp);
        cur++;
    }
    return ret;
} 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;
    
}

