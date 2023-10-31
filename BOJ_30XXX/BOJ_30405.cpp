#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    vector<int> ans;
    for(int i=0; i<N; i++) {
        int K;
        cin >> K;
        vector<int> sorter;
        for(int j=0; j<K; j++) {
            int temp;
            cin >> temp;
            sorter.push_back(temp);
        }
        ans.push_back(sorter[0]);
        ans.push_back(sorter[K-1]);
    }
    sort(ans.begin(),ans.end());
    cout << ans[N-1];
}