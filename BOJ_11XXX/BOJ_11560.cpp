#include <cstdio>

typedef long long ll;

ll DP[21][211];

int main() {
    DP[0][0] = 1;
    for(int i=1; i<=20; i++) {
        int len = i*(i-1)/2;
        for(int j=0; j<=i; j++) for(int k=0; k<=len; k++) DP[i][j+k] += DP[i-1][k];
    }
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        int K,N;
        scanf("%d %d",&K,&N);
        printf("%ld\n",DP[K][N]);
    }
    return 0;
}