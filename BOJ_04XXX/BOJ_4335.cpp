#include <bits/stdc++.h>

using namespace std;

string ans[2] = {"Stan is dishonest\n","Stan may be honest\n"};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int left = -1, right = 11;
    while(true) {
        int N;
        cin >> N;
        if(N == 0) exit(0);

        string str;
        cin >> str >> str;
        if(str.back() == 'h') {
            right = min(right,N);
        } else if(str.back() == 'w') {
            left = max(left,N);
        } else {
            cout << ans[N>left && N<right];
            left = -1, right = 11;
        }
    }
}