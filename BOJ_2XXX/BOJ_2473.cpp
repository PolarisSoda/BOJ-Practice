#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long int sol[5000];

int main() {
	
	int N;
	cin >> N;
	
	int minus = 0;
	int plus = 0;
	
	for(int i=0; i<N; i++) {
		cin >> sol[i];
		if(sol[i] < 0) {
			minus = 1;
		} else if(sol[i] > 0) {
			plus = 1;
		}
	}
	sort(sol,sol+N);
	
	if(plus == 2) {
 		if(plus > 0) {
			printf("%lld %lld %lld",sol[0],sol[1],sol[2]);
		} else {
			printf("%lld %lld %lld",sol[N-1],sol[N-2],sol[N-3]);
		}
	} else if(true) {
		long long int ph = 3000000001;
		int a1,a2,a3;
		int fixed,left,right;
		for(fixed=0; fixed<N-2; fixed++) {
			left = fixed+1;
			right = N-1;
			while(true) {
				long long int temp = static_cast<long long int>(sol[fixed]) + (long long int)sol[left] + (long long int)sol[right];
				//cout << ph << "!!!!\n";
				//cout << abs(temp) << endl;
				if(ph > (long long int)abs(temp)) {
					ph = abs(temp);
					a1 = fixed;
					a2 = left;
					a3 = right;
				}
				if(temp > 0) {
					right--;
				} else if(temp < 0) {
					left++;
				} else {
					break;
				}
				if(left == right) {
					break;
				}
			}
		}
		printf("%lld %lld %lld",sol[a1],sol[a2],sol[a3]);
	} else {
		printf("0 0 0");
	}
	return 0;
}