#include <bits/stdc++.h>

using namespace std;

vector<int> FF;

void EL_FAIL(string str) {
    FF = vector<int>(str.length());
    FF[0] = 0;

    int len = str.length();
    for(int i=1, j=0; i<len; i++) {
        while(j>0 && str[i] != str[j]) j = FF[j-1];
        if(str[i] == str[j]) FF[i] = ++j;
    }
}

int solve() {
    string B,S;
    cin >> B >> S;
    
    EL_FAIL(S);
    int ret = 0;
    int len = B.length();
    for(int i=0, j=0; i<len; i++) {
        while(j>0 && B[i] != S[j]) j = FF[j-1];
        if(B[i] == S[j]) {
            if(j == S.length()-1) ret++, j = FF[j];
            else j++;
        }
    }
    return ret;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}