#include <bits/stdc++.h>

using namespace std;

int FCT[8] = {1,1,2,6,24,120,720,5040};
int DP[10001]; //i를 만드는 1의 최소 개수

int Dynamic(int num) {
    if(DP[num] != -1) return DP[num];
    int ret = num;
    for(int i=2; i*i<=num; i++) {
        if(num%i) continue;
        ret = min(ret,Dynamic(i)+Dynamic(num/i));
    }
    for(int i=1; i<num/2; i++) {
        ret = min(ret,Dynamic(i)+Dynamic(num-i));
    }
    return DP[num] = ret;
}

int main() {
    int N;
    cin >> N;

    memset(DP,-1,sizeof(DP));
    DP[1] = 1, DP[2] = 2, DP[3] = 3;
    for(int i=1; i<=7; i++) DP[FCT[i]] = i;
    DP[720] = 3;
    DP[5040] = 4;
    cout << Dynamic(N);
    exit(0);
}