#include <bits/stdc++.h>

using namespace std;

bool a[300001];

void print(int num) {
    string str = "";
    while(num > 0) {
        str.push_back('0'+(num&1));
        num >>= 1;
    }
    reverse(str.begin(), str.end());
    cout << str;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    string str;
    cin >> N >> str;

    int limit;
    for(int i=1; i<=N; i++) {
        int expr = N - i + 1; //표현가능한 최대 개수
        int total = 1<<i;
        if(expr < total) {
            limit = i;
            break;
        }
    }

    for(int i=1; i<=limit; i++) {
        for(int j=0; j<N; j++) {
            if(str[j] == '0') continue;
            a[stoi(str.substr(j,i),NULL,2)] = true;
        }
    }
    for(int i=1; i<=300000; i++) if(!a[i]) print(i), exit(0);
}