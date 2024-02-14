#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 2000001;
vector<int> arr,prime;
int cnt[LEN];
bool visited[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    prime.push_back(2);
    for(int i=3; i<=1000000; i+=2) {
        if(visited[i] == false) {
            prime.push_back(i);
            int bias = i<<1;
            for(int j=i*3; j<=1000000; j+=bias) visited[j] = true;
        }
    }

    int N;
    cin >> N;
    if(N <= 2) cout << N, exit(0);
    
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    int ans = 0;
    for(int p : prime) {
        for(int i=0; i<N; i++) {
            int temp = arr[i]%p;
            ans = max(ans,++cnt[temp]);
        }
        for(int i=0; i<N; i++) cnt[arr[i]%p] = 0;
    }
    cout << ans;
    exit(0);
}