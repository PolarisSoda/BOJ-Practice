#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

vector<pil> card;
ll price[10],cnt[10];
ll N,M;

bool compare(pil a,pil b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

void PR() {
    ll sum = 0;
    bool zero_only = true;
    for(int i=0; i<N; i++) {
        sum += cnt[i];
        if(i != 0 && cnt[i] != 0) zero_only = false;
    }
    if(zero_only) cout << "1\n0\n0\n";
    else {
        cout << sum << "\n";
        ll bias = min(sum,50LL);
        for(int i=N-1; i>=0; i--) {
            if(bias == 0) break;
            ll count = min(bias,cnt[i]);
            for(int j=0; j<count; j++) cout << i;
            bias -= count;
        }
        cout << "\n";

        bias = min(sum,50LL);
        vector<int> r_ans;
        for(int i=0; i<N; i++) {
            if(bias == 0) break;
            ll count = min(bias,cnt[i]);
            for(int j=0; j<count; j++) r_ans.push_back(i);
            bias -= count;
        }
        for(auto it=r_ans.rbegin(); it!=r_ans.rend(); it++) cout << *it;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> price[i];
        card.push_back({i,price[i]});
    }
    sort(card.begin(),card.end(),compare);
    cin >> M;

    int minv = card[0].first;
    ll max_radix = cnt[minv] = M/card[0].second;
    M %= card[0].second;
    if(max_radix == 0) cout << 0,exit(0);

    for(int i=N-1; i>minv; i--) {
        ll diff = price[i] - card[0].second;
        if(diff == 0) {
            swap(cnt[minv],cnt[max(minv,i)]);
            break;
        }
        ll inc = min(M/diff,cnt[minv]);
        cnt[i] += inc, cnt[minv] -= inc;
        M -= inc*diff;
    }
    if(cnt[0] == max_radix) {
        int s_idx = -1;
        ll reduced = max_radix+1;
        for(int i=N-1; i>=1; i--) {
            ll val = (price[i] - M)/price[0];
            if((price[i]-M)%price[0] != 0) val++;
            if(val < reduced) s_idx = i, reduced = val;
        }
        if(s_idx != -1) cnt[0] -= reduced, cnt[s_idx]++;
    }
    PR();
    exit(0);
}