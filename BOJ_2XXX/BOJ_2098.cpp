#include <iostream>
#include <algorithm>
#define MAX 2000000000
using namespace std;

int edge[17][17] = {};
int DP[65536][17] = {};
int N;

int completed;

int TSP(int status,int location) {
	if(status == completed) {
		if(edge[location][0] != 0) {
			return edge[location][0];
		} else {
			//cout << "wjyu\n";
			return MAX;
		}
	} else {
		if(DP[status][location] != 0) {
			//cout << "wjy\n";
			return DP[status][location];
		}
		DP[status][location] = MAX;
		for(int i=0; i<N; i++) {
			if(edge[location][i] == 0 || status & (1<<i)) {
				continue;
			}
			//cout << location << ", " << i << endl;
			int nextstat = status + (1<<i);
			//cout << nextstat << "?\n";
			int temp = TSP(nextstat,i) + edge[location][i];
			//cout << temp << endl;
			if(DP[status][location] > temp) {
				DP[status][location] = temp;
			}
			//cout << DP[status][location] << endl;
		}
		return DP[status][location];
	}
}
int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> edge[j][i];
		}
	}
	completed = (1 << N) - 1;
	cout << TSP(1,0);
}