#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S,T;
    cin >> S >> T;

    queue<string> task;
    task.push(T);

    while(!task.empty()) {
        string now = task.front();
        task.pop();
        if(now == S) cout << 1, exit(0);

        if(now.back() == 'A') task.push(now.substr(0,now.length()-1));
        if(now.front() == 'B') {
            string temp = now.substr(1,now.length()-1);
            reverse(temp.begin(),temp.end());
            task.push(temp);
        }
    }
    cout << 0;
    exit(0);
}