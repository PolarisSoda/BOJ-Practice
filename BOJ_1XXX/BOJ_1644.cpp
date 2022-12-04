//BOJ 1644 Practice
#include <iostream>
#include <vector>

using namespace std;

bool visited[40000001] = {};

int main() {
	int N;
	cin >> N;
	vector<int> prime;
	
	for(int i=2; i<=4000000; i++) {
		if(visited[i] == false) {
			prime.push_back(i);
			for(int j=i; j<=4000000; j+=i) {
				visited[j] = true;
			}
		}
	}
	int cnt = 0;
	int ans = prime[0];
	int left = 0;
	int right = 0;
	while(true) {
		if(right >= prime.size() || left >= prime.size()) {
			break;
		}
		if(ans == N) {
			cnt++;
			left++;
			ans -= prime[left-1];
		} else if(ans < N) {
			right++;
			ans += prime[right];
		} else {
			left++;
			ans -= prime[left-1];
		}
		if(left > right) {
			break;
		}
	}
	cout << cnt;
}