#include <bits/stdc++.h>
#include <ranges>

using namespace std;

bool solve() {
    string S;
    cin >> S;

    int len = S.size();
    if(S.find('*') == string::npos) {
        if(len%2 == 1) return false;

        int lcnt = 0, rcnt = 0, cnt = 0;
        for(char C : S) {
            if(C == '(') lcnt++;
            if(C == ')') rcnt++;
        }

        if(lcnt > len/2 || rcnt > len/2) return false;

        for(char C : S) {
            switch(C) {
                case '?':
                    if(lcnt < len/2) lcnt++, cnt++;
                    else cnt--;
                    break;
                case '(':
                    cnt++;
                    break;
                case ')':
                    cnt--;
                    break;
            }
            if(cnt < 0) return false;
        }
    } else {
        int cnt = 0;
        for(int i=0; i<len; i++) {
            if(S[i] == '*') break;
            if(S[i] == '(' || S[i] == '?') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
        
        cnt = 0;
        for(int i=len-1; i>=0; i--) {
            if(S[i] == '*') break;
            if(S[i] == ')' || S[i] == '?') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    exit(0);
}