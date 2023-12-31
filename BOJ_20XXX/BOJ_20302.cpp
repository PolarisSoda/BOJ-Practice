#include <bits/stdc++.h>

using namespace std;

vector<int> prime;

int cnt[100001];

void num_control(int num,bool plus) {
    if(num == 0) {
        cout << "mint chocolate";
        exit(0);
    }
    int sz = num;
    for(int i=2; i*i<=sz; i++) {
        while(num%i == 0) {
            if(plus) cnt[i] ++;
            else cnt[i] --;
            num /= i;
        }
    }
    if(num > 1) {
        if(plus) cnt[num] ++;
        else cnt[num]--;
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        char c = '*';
        int num;
        if(i != 0) cin >> c;
        cin >> num;
        if(num < 0) num *= -1;
        if(c == '*') num_control(num,true);
        else num_control(num,false);
    }

    for(int i=2; i<=100000; i++) if(cnt[i] < 0) goto FAIL;

    cout << "mint chocolate";
    return 0;
    FAIL:
    cout << "toothpaste";
    return 0;
}