#include <iostream>
#include <list>

using namespace std;
list<int> code;

void solve(int idx) {
    code = list<int>();
    int N,M;

    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        code.push_back(temp);
    }
    cin >> M;

    for(int i=0; i<M; i++) {
        char c;
        
        int x,y,s;
        auto it = code.begin();
        cin >> c;
        if(c == 'I') {
            cin >> x >> y;
            for(int j=0; j<x; j++) it++;
            for(int j=0; j<y; j++) {
                cin >> s;
                code.insert(it,s);
            }
        } else if(c == 'D') {
            cin >> x >> y;
            for(int j=0; j<=x; j++) it++;
            for(int j=0; j<y; j++) {
                it = code.erase(it);
            }
        } else {
            cin >> y;
            for(int i=0; i<y; i++) {
                cin >> s;
                code.push_back(s);
            }
        }
    }
    cout << "#" << idx << " ";
    auto it = code.begin();
    for(int i=0; i<10; i++) cout << *(it++) << " ";
    cout << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i=1; i<=10; i++) solve(i);
}