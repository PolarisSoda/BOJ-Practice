#include <bits/stdc++.h>

using namespace std;

vector<char> V;
string S;

string DFS(int left,int right,int count) {
    if(left > right || count == 0) return "";

    int idx = -1;
    char minv = (char)100;
    for(int i=left; i<=right; i++) {
        if(S[i] < minv) minv = S[i], idx = i;
    }

    string right_str = DFS(idx+1,right,count-1);
    string left_str = DFS(left,idx-1,count-1-right_str.length());
    return left_str + minv + right_str;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> S;

    for(int i=1; i<=S.length(); i++) {
        cout << DFS(0,S.length()-1,i) << "\n";
    }
    exit(0);
}