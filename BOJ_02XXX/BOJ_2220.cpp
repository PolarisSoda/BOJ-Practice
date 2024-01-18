#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
int heap[LEN];
int main() {
    int N;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        heap[i] = i;
        for(int j=i-1; j>1; j>>=1) swap(heap[j],heap[j>>1]);
        swap(heap[i],heap[1]);
    }
    for(int i=1; i<=N; i++) printf("%d ",heap[i]);
    exit(0);
}