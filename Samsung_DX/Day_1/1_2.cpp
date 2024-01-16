#include <iostream>
#include <list>

using namespace std;

list<int> arr;

void solve() {
    int N,M,L;
    cin >> N >> M >> L;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for(int i=0; i<M; i++) {
        char c;
        cin >> c;
        int X,Y;
        auto it = arr.begin();
        if(c == 'I') {
            cin >> X >> Y;
            while(X--) it++;
            arr.insert(it,Y);
        } else if(c == 'D') {
            cin >> X;
            while(X--) it++;
            arr.erase(it);
        } else {
            cin >> X >> Y;
            while(X--) it++;
            *it = Y;
        }
    }
    auto it = arr.begin();
    if(arr.size() <= L) cout << "-1\n";
    else {
        while(L--) it++;
        cout << *it << "\n";
    }
    
    arr = list<int>();
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
    return 0;
}