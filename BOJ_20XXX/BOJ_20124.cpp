#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    string name = "~";
    int score = -1;

    for(int i=0; i<N; i++) {
        string t1;
        int t2;
        cin >> t1 >> t2;

        if(score == t2) name = min(name,t1);
        else if(score < t2) name = t1, score = t2;
    }
    cout << name;
    exit(0);
}