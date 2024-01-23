#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> hs;

int solve() {
    hs.clear();
    
    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        hs.insert({str,1});
    }
    int ret = 0;
    for(int i=0; i<M; i++) {
        string str;
        cin >> str;
        if(hs.count(str) != 0) ret++;
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}