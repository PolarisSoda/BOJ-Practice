#include <iostream>
#include <vector>

using namespace std;

bool visited[1000001] = {};

vector<int> prime;

int main() {
    for(int i=2; i<=1000000; i++) {
        if(visited[i] == false) {
            prime.push_back(i);
            for(int j=i; j<=1000000; j+=i) {
                visited[j] = true;
            }
        }
    }
    
    long long int N;
    cin >> N;
    
    long long int ans = N;
    
    for(int i=0; i<prime.size(); i++) {
        if(N%prime[i] == 0) {
            while(N%prime[i] == 0) {
                N /= prime[i];
            }
            ans -= ans/prime[i];
        }
    }
    if(N > 1) {
        ans -= ans/N;
    }
    cout << ans;
}