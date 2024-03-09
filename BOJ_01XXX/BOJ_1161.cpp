#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> info;

vector<info> G;
map<int,int> in_bus;

bool compare(info a,info b) {
    if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int K,N,C;
    cin >> K >> N >> C;
    for(int i=0; i<K; i++) {
        int S,E,M;
        cin >> S >> E >> M;
        G.push_back({S,E,M});
    }
    sort(G.begin(),G.end(),compare);

    int ans = 0, car = C;
    for(auto &[S,E,M] : G) {
        auto it = in_bus.begin();
        while(it!=in_bus.end() && it->first <= S) {
            ans += it->second;
            car += it->second;
            it = in_bus.erase(it);
        }

        in_bus[E] += M, car -= M;
        it = prev(in_bus.end());
        while(car < 0) {
            if(it->second + car > 0) it->second += car, car = 0;
            else car += it->second, in_bus.erase(it--);
        }
    }
    for(auto it=in_bus.begin(); it!=in_bus.end(); it++) ans += it->second;
    cout << ans;
    exit(0);
}
