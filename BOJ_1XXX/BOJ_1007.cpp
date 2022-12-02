#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define MAX 0x7fffffff
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int N;
        double ans = MAX;
        vector<pair<int,int>> pos;
        for(int j=0; j<N; j++) {
            int tx,ty;
            cin >> tx >> ty;
            pos.push_back({tx,ty});
        }

        vector<bool> com(N,false);

        for(int j=N-1; j>=N/2; j--) {
            com[j] = true;
        }

        do {
            int x = 0, y = 0;
            for(int j=0; j<N; j++) {
                if(com[j]) {
                    x += pos[j].first;
                    y += pos[j].second;
                } else {
                    x -= pos[j].first;
                    y -= pos[j].second;
                }
            }
            long long int temp = x*x + y*y;
            double trial = sqrt(temp);
            if(ans > trial) {
                ans = trial;
            }
        } while(next_permutation(com.begin(),com.end()));

        printf("%.7lf\n",ans);
    }
}