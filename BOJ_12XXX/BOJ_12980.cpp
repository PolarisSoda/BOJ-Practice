#include <bits/stdc++.h>

using namespace std;

bool used[101];
int arr[101];
vector<int> IDX;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,S;
    cin >> N >> S;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        if(arr[i] == 0) IDX.push_back(i);
        used[arr[i]] = true;    
    }
    
    int ret = 0;
    vector<int> nums;
    for(int i=1; i<=N; i++) if(!used[i]) nums.push_back(i);

    do {
        for(int i=0; i<nums.size(); i++) arr[IDX[i]] = nums[i];

        int local = 0;
        for(int i=0; i<N-1; i++) for(int j=i+1; j<N; j++) local += arr[i] < arr[j];
        ret += local == S;
    } while(next_permutation(nums.begin(),nums.end()));

    cout << ret;
    exit(0);
}