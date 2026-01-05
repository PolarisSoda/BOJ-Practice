#include <bits/stdc++.h>

using namespace std;

unordered_map<string,vector<string>> HS;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S,E,Q;
    cin >> S >> E >> Q;

    string T,N;
    while(cin >> T >> N) {
        if(HS.count(N) == 0) HS.insert({N,{T}});
        else HS[N].push_back(T);
    }
    
    int cnt = 0;
    for(auto [A,B] : HS) {
        sort(B.begin(),B.end());
        auto it = lower_bound(B.begin(),B.end(),E);
        if(B[0] <= S && it != B.end() && *it <= Q) cnt++;
    }
    cout << cnt;
    exit(0);
}