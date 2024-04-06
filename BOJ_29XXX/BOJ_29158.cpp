#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> fi,se;

bool compare(string a,string b) {
    return a+b > b+a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll temp = N;
    for(ll i=2; i*i<=N; i++)
        while(temp%i == 0) temp /= i, fi.push_back(to_string(i));
    if(temp != 1) fi.push_back(to_string(temp));
    N--;
    while(N >= 4) N>>=1, se.push_back("2");
    se.push_back(to_string(N));

    sort(fi.begin(),fi.end(),compare), sort(se.begin(),se.end(),compare);
    string t1,t2;
    for(string now : fi) t1 += now;
    for(string now : se) t2 += now;

    string ans;
    if(t2.length() > t1.length()) swap(t1,t2);
    int carry = 0;
    for(int i=0; i<t1.length(); i++) {
        int ff = t1[t1.length()-1-i] - '0';
        int ss = (t2.length() >= i+1) ? t2[t2.length()-1-i] -'0' : 0;
        int temp = ff + ss + carry;
        if(temp >= 10) temp -= 10, carry = 1;
        else carry = 0;
        ans += to_string(temp);
    }
    if(carry) ans += "1";
    for(auto it=ans.rbegin(); it!=ans.rend(); it++) cout << *it;
    exit(0);
}