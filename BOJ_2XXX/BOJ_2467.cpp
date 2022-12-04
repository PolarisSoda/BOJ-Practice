#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int sol[100001] = {};
int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> sol[i];
	}
	sort(sol,sol+N);
	int a1,a2;
	int left = 0;
	int right = N-1;
	int ph = 0x7FFFFFFF;
	while(true) {
		if(left == right) {
			break;
		}
		int mixture = sol[left] + sol[right];
		//cout << mixture << " ";
		if(abs(mixture) < ph) {
			//cout << "ehllo>? ";
			ph = abs(mixture);
			a1 = left;
			a2 = right;
		}
		if(mixture > 0) {
			right--;
		} else if(mixture < 0) {
			left++;
		} else {
			break;
		}
	}
	cout << endl << sol[a1] << " " << sol[a2];
}