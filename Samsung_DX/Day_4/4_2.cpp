#include <iostream>

using namespace std;

constexpr int LEN = 100005;
int heap[LEN];
int hsz = 0;

void Insert(int num) {
    heap[++hsz] = num;
    int cur = hsz;
    while(cur > 1) {
        if(heap[cur] <= heap[cur>>1]) break;
        swap(heap[cur],heap[cur>>1]); 
        cur >>= 1;
    }
}

void Remove() {
    cout << heap[1] << " ";
    heap[1] = heap[hsz--];
    int cur = 1;
    while(true) {
        if(hsz > cur<<1) {
            int left = heap[cur<<1];
            int right = heap[cur<<1|1];
            if(heap[cur] >= max(left,right)) break;
            int idx = left >= right ? cur<<1 : cur<<1|1;
            swap(heap[cur],heap[idx]);
            cur = idx;
        } else if(cur<<1 == hsz && heap[cur] < heap[cur<<1]) {
            swap(heap[cur],heap[cur<<1]);
            cur <<= 1;
            break;
        } else break;
    }
}

void solve() {
    hsz = 0;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int C;
        cin >> C;
        if(C == 1) {
            int X;
            cin >> X;
            Insert(X);
        } else {
            if(hsz == 0) cout << -1 << " ";
            else Remove();
        }
    }
    cout << "\n";
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
    return 0;
}   