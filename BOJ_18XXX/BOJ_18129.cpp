#include <bits/stdc++.h>

using namespace std;

bool visited[1001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S;
    int K;
    cin >> S >> K;

    int len = S.length();
    int current = 96, cnt = -1;
    string ans = "";

    for(int i=0; i<len; i++) {
        int now = S[i];
        
        if(now >= 'a') now -= 'a';
        else now -= 'A';

        if(visited[now]) continue;

        if(current != now) {
            if(cnt >= K) ans += "1";
            else ans += "0";
            visited[current] = true;
            current = now, cnt = 1;
        } else {
            cnt++;
        }
    }
    if(cnt >= K) ans += "1";
    else ans += "0";

    cout << ans.substr(1);
}