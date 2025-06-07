#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef __int128 bint;
typedef long long ll;

vector<ull> V;
vector<int> tests = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31};

ull power(bint base,bint ex,bint mod) {
    bint ret = 1;

    base %= mod;
    while(ex > 0) {
        if(ex&1) ret = ret * base % mod;
        base = base * base % mod;
        ex >>= 1LL;
    }
    return static_cast<ull>(ret);
}

bool MRTest(ull N,ull a) {
    if(N%a == 0) return true;
    ull param = N-1;
    while(true) {
        ull temp = power(a,param,N);
        if(param&1LL) return temp == 1 || temp == N-1;
        if(temp == N-1) return true;
        param >>= 1LL;
    }
}

bool isprime(ull N) {
    if(N%2 == 0 & N != 2) return false;
    for(int test : tests) {
        if(N == test) return true;
        if(!MRTest(N,test)) return false;
    }
    return true;
}

void Pollard_Rho(ull num) {
    while(num % 2 == 0) V.push_back(2), num >>= 1LL; //first, get 2.
    if(num == 1) return;
    if(isprime(num) == true) { V.push_back(num); return; }

    ull x = rand()%(num-2) + 2, y = x;
    ull c = rand()%(num-2) + 1;
    ull d = 1;

    while(true) {
        x = static_cast<ull>(((bint)x*x+c)%num);
        y = static_cast<ull>(((bint)y*y+c)%num);
        y = static_cast<ull>(((bint)y*y+c)%num);

        ull diff = x > y ? x-y : y-x;
        d = __gcd(diff,num);
        
        if(d != 1) break;
    }
    if(d == num) Pollard_Rho(num);
    else Pollard_Rho(d), Pollard_Rho(num/d);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));

    ull N;
    cin >> N;

    Pollard_Rho(N);
    sort(V.begin(),V.end());

    for(auto num : V) cout << num << "\n";
    exit(0);
}