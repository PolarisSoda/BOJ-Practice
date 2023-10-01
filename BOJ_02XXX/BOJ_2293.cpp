#include <iostream>
#include <vector>

using namespace std;

int DP[100001] = {};
int main() {
	int N,K;
	cin >> N >> K;
	
	vector<int> coin(N);
	
	for(int i=0; i<N; i++) {
		cin >> coin[i];
	}
	
	DP[0] = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<=K; j++) {
			if(j-coin[i] >= 0) {
				DP[j] += DP[j-coin[i]];
			}
		}
	}
	cout << DP[K];
	return 0;
}