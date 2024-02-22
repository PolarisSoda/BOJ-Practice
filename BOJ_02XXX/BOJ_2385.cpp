#include <bits/stdc++.h>

using namespace std;

deque<string> nz,z;
string zeros;

bool compare (string a,string b) {
    return a+b < b+a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        string str;
        cin >> str;
        if(str[0] == '0') z.push_back(str);
        else nz.push_back(str);
    }
    sort(z.begin(),z.end(),compare);
    sort(nz.begin(),nz.end(),compare);
    for(auto now : z) zeros += now;

    int idx = 0, nsz = nz.size();
    if(nsz == 0) cout << "INVALID", exit(0);
    string maxv = nz[0];
    for(int i=0; i<nsz; i++) {
        string now = nz[i];
        if(now+zeros+maxv < maxv+zeros+now) maxv = now, idx = i;
    }
    cout << maxv << zeros;
    for(int i=0; i<nsz; i++) if(i != idx) cout << nz[i];
    exit(0);
}