#include <bits/stdc++.h>

using namespace std;

typedef __int128 bint;
typedef long long ll;

vector<ll> V;
vector<int> tests = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37};

ll power(bint base,bint ex,bint mod) {
    bint ret = 1;

    base %= mod;
    while(ex > 0) {
        if(ex&1) ret = ret * base % mod;
        base = base * base % mod;
        ex >>= 1LL;
    }
    return static_cast<ll>(ret);
}

bool MRTest(ll N,ll a) {
    if(N%a == 0) return true;
    ll param = N-1;
    while(true) {
        ll temp = power(a,param,N);
        if(param&1LL) return temp == 1 || temp == N-1;
        if(temp == N-1) return true;
        param >>= 1LL;
    }
}

bool isprime(ll N) {
    if(N%2 == 0 & N != 2) return false;
    for(int test : tests) {
        if(N == test) return true;
        if(!MRTest(N,test)) return false;
    }
    return true;
}

void Pollard_Rho(ll num) {
    while(num % 2 == 0) V.push_back(2), num >>= 1LL; //first, get 2.
    if(num == 1) return;
    if(isprime(num) == true) { V.push_back(num); return; }

    ll x = rand()%(num-2) + 2, y = x;
    ll c = rand()%(num-2) + 1;
    ll d = 1;

    while(true) {
        x = static_cast<ll>(((bint)x*x+c)%num);
        y = static_cast<ll>(((bint)y*y+c)%num);
        y = static_cast<ll>(((bint)y*y+c)%num);
        d = __gcd(abs(x-y),num);
        
        if(d != 1) break;
    }
    if(d == num) Pollard_Rho(num);
    else Pollard_Rho(d), Pollard_Rho(num/d);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));

    ll N;
    cin >> N;

    Pollard_Rho(N);
    sort(V.begin(),V.end());
    
    ll prev_1 = -1, prev_2 = -1;
    int cnt_1 = 0, cnt_2 = 0;
    bool flag_1 = true, flag_2 = true, flag_4 = false;

    for(auto num : V) {
        if(prev_1 != num) prev_1 = num, flag_1 &= cnt_1%2 == 0, cnt_1 = 1;
        else cnt_1++;

        if(num%4 != 3) continue;
        
        if(prev_2 != num) prev_2 = num, flag_2 &= cnt_2%2 == 0, cnt_2 = 1;
        else cnt_2++;
    }
    flag_1 &= cnt_1%2 == 0;
    flag_2 &= cnt_2%2 == 0;

    cnt_2 = 0;
    for(auto num : V) {
        if(num == 2) cnt_2++;
        else break;
    }
    flag_4 = (cnt_2%2 == 0) && (((bint)N>>cnt_2)%8 == 7);

    if(flag_1) cout << 1;
    else if(flag_2) cout << 2;
    else if(flag_4) cout << 4;
    else cout << 3;

    exit(0);
}