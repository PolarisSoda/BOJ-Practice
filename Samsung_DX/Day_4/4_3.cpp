#include <bits/stdc++.h>

using namespace std;

constexpr int DIV = 20171109;
int solve() {
    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;

    int N,A;
    cin >> N >> A;

    int sum = 0;
    maxq.push(A);
    for(int i=0; i<N; i++) {
        int X,Y;
        cin >> X >> Y;
        int cur = maxq.top();
        maxq.pop();
        int sorter[3] = {X,Y,cur};
        sort(sorter,sorter+3,less<int>());
        if(!minq.empty() && sorter[2] > minq.top()) {
            int temp = minq.top();
            minq.pop();
            minq.push(sorter[2]);
            sorter[2] = temp;
            sort(sorter,sorter+3,less<int>());
        }
        maxq.push(sorter[0]);
        maxq.push(sorter[1]);
        minq.push(sorter[2]);
        sum = (sum+maxq.top())%DIV;
    }
    return sum;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}