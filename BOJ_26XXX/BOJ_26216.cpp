#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int loga(long long int base,long long int num) {
    int ans = 0;
    while(num%base == 0) {
        num /= base;
        ans++;
    }
    return ans;
}
long long int power(long long int num,int exponent) {
    long long int ans = 1;
    for(int i=0; i<exponent; i++) {
        ans *= num;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K,H,Q;
    cin >> K >> H >> Q;
    int factor = K+1;
    long long int limit = power(K+1,H);
    //cout << limit << endl;
    for(int i=0; i<Q; i++) {
        long long int A,B;
        cin >> A >> B;
        if(B >= limit || A >= limit) {
            cout << "-1" << "\n";
            continue;
        }
        if(A == B) {
            cout << "0" << "\n";
            continue;
        }
        int HA = loga(factor,A);
        int HB = loga(factor,B);
        int LCA = max(HA,HB) + 1;
        long long int param = power(factor,LCA);
        while(true) {
            if(A/param == B/param) {
                break;
            }
            LCA++;
            param *= factor;
        }
        cout << LCA - HA + LCA - HB << "\n";
    }
}