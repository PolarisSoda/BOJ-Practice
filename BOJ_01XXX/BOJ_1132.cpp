#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> V;
ll P[13];
ll bias[13];
bool first[13];
int trans[13];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    P[0] = 1;
    for(int i=1; i<=12; i++) P[i] = P[i-1]*10;

    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;

        first[temp[0] - 'A'] = true;
        int len = temp.length();
        for(int i=0; i<len; i++) bias[temp[len-1-i] - 'A'] += P[i];
        V.push_back(temp);
    }

    vector<pair<ll,char>> T;
    for(int i=0; i<=9; i++) T.push_back({bias[i],i+'A'});
    sort(T.begin(),T.end());

    bool found = false;
    int idx = 1;

    for(int i=0; i<=9; i++) {
        char now = T[i].second;
        if(!found && first[now-'A'] == false) {
            found = true; 
            trans[now-'A'] = 0;
        } else {
            trans[now-'A'] = idx++;
        }
        
    }
    
    ll ret = 0;
    for(string now : V) {
        string copied = now;
        int len = copied.length();
        for(int i=0; i<len; i++) copied[i] = trans[copied[i] - 'A'] + '0';
        ret += stoll(copied);
    }
    
    cout << ret;
    exit(0);
}