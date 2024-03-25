#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

string rev(string a) {
    string ret = "";
    int len = a.length();
    for(int i=len-1; i>=0; i--) {
        if(a[i] == '6') ret.push_back('9');
        else if(a[i] == '9') ret.push_back('6');
        else ret.push_back(a[i]);
    }
    return ret;
}

bool compare(string a,string b) {
    return a+b < b+a;
}

string max(string a,string b) {
    if(a.length() > b.length()) return a;
    else if(a.length() == b.length()) return stoi(a) > stoi(b) ? a : b;
    else return b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    string maxv = "0";
    for(int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        temp = rev(temp);
        arr.push_back(temp);
        maxv = max(maxv,temp);
    }
    arr.push_back(maxv);
    sort(arr.begin(),arr.end(),compare);
    for(int i=0; i<=N; i++) cout << rev(arr[i]);
    exit(0);
}