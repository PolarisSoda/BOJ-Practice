#include <bits/stdc++.h>

using namespace std;

vector<int> one;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        if(temp == 1) one.push_back(i);
    }

    int minv = 0x7FFFFFFF;
    pair<int,int> LR;
    bool switched = false;
    
    if(one.back() < N+1-one.front()) minv = one.back(), LR = {minv,0};
    else minv = N+1-one.front(), LR = {0,minv};

    int sz = one.size();
    for(int i=0; i<sz-1; i++) {
        int left = one[i], right = N+1-one[i+1];
        int local_left = left*2 + right;
        int local_right = right*2 + left;

        if(local_left < minv) {
            minv = local_left;
            LR = {left,local_left - left};
            switched = false;
        }
        if(local_right < minv) {
            minv = local_right;
            LR = {local_right-right,right};
            switched = true;
        }
    }
    cout << minv << "\n";
    if(switched) {
        for(int i=0; i<LR.second; i++) cout << 'R';
        for(int i=0; i<LR.first; i++) cout << 'L';
    } else {
        for(int i=0; i<LR.first; i++) cout << 'L';
        for(int i=0; i<LR.second; i++) cout << 'R';
    }
    
    exit(0);
}