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
    for(int i=1; i<=N; i++) diff.push_back(arr[i]-arr[i-1]);

    int ans = arr[N];
    ans -= (diff[0]-1);
    diff.erase(diff.begin());
    sort(diff.begin(),diff.end(),greater<int>());
    for(int i=0; i<K-1; i++) ans -= (diff[i]-1);
    cout << ans;
    return 0;
}