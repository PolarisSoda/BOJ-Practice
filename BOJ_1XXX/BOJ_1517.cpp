#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<pii> numzip;
vector<ll> tree;
ll sum(ll node,ll start,ll end,ll left,ll right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    ll mid = (start+end)/2;
    return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}

void update(ll node,ll start,ll end,ll index,ll diff) {
    if(index < start || index > end) {
        return;
    }
    tree[node] = tree[node] + diff;
    if(start != end) {
        ll mid = (start+end)/2;
        update(node*2,start,mid,index,diff);
        update(node*2+1,mid+1,end,index,diff);
    }
}


bool compare(pii a,pii b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    tree.reserve(4*N);
    numzip.push_back({-0x7FFFFFFF,0});
    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        numzip.push_back({num,i});
    }
    sort(numzip.begin(),numzip.end(),compare);
    
    ll ans = 0;
    for(int i=1; i<=N; i++) {
        update(1,1,N,numzip[i].second,1);
        ans += sum(1,1,N,numzip[i].second+1,N);
    }
    cout << ans;
}
