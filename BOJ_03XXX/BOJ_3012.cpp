#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int DIV = 100000;
constexpr int LEN = 201;

ll DP[LEN][LEN]; 
int N;
bool OF;
string str;

int Bias(int L,int R) {
    char l = str[L], r = str[R];
    if(l == r) {
        if(l == '?') return 3;
    } else {
        if(l == '?') {
            if(r == ')' || r == '}' || r == ']') return 1;
        } else if(r == '?') {
            if(l == '(' || l == '{' || l == '[') return 1;
        } else {
            if(r-l == 2 || r-l == 1) return 1;
        }
    }
    return 0;
}

ll Dynamic(int L,int R) {
    if(DP[L][R] != -1) return DP[L][R];
    if(L > R) return DP[L][R] = 1;
    if(L == R) return DP[L][R] = 0;

    ll ret = 0;
    for(int i=L+1; i<=R; i++) ret += Dynamic(L+1,i-1)*Dynamic(i+1,R)*Bias(L,i);
    if(ret >= DIV) OF = true;
    ret %= DIV;
    return DP[L][R] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> str;
    if(N%2) {
        cout << 0;
        exit(0);
    }
    memset(DP,-1,sizeof(DP));
    ll ans = Dynamic(0,N-1);
    if(OF) {
        if(ans == 0) cout << 0;
        else {
            string str_ans = to_string(ans);
            for(int i=0; i<5-str_ans.length(); i++) cout << "0";
            cout << str_ans;
        }
    } else cout << ans;
    exit(0);
}