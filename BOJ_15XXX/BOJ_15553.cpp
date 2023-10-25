#include <bits/stdc++.h>

using namespace std;

int arr[100001];
vector<int> diff;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,K;
    cin >> N >> K;

    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=N; i++) if(i != 1) diff.push_back(arr[i]-arr[i-1]);
    sort(diff.begin(),diff.end(),greater<int>());
    
    int ans = arr[N] - arr[1] + arr[0] + 1;
    for(int i=0; i<K-1; i++) ans -= (diff[i]-1);
    cout << ans;
    return 0;
}