#include <bits/stdc++.h>
#define LEN 3010
#define BIAS 1502
using namespace std;

int LUX[LEN][LEN];
int SRC[LEN][LEN];
int EDGE[100000][2];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,P;
    cin >> N;
    for(int i=0; i<N; i++) {
        int X,Y;
        cin >> X >> Y;
        SRC[X+BIAS][Y+BIAS]++; 
    }
    for(int i=1; i<LEN; i++) {
        for(int j=0; j<LEN; j++) {
            LUX[j][i] = LUX[j][i-1] + SRC[j][i] + EDGE[i-j+LEN][0] + EDGE[i+j][1];
            EDGE[i-j+LEN][0] += SRC[j][i];
            EDGE[i+j][1] += SRC[j][i];
        }
    }
    cin >> P;
    for(int i=0; i<P; i++) {
        int X,Y;
        cin >> X >> Y;
        cout << LUX[X+BIAS][Y+BIAS] << "\n";
    }
    return 0;       
}