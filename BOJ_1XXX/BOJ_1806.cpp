#include <iostream>
#include <algorithm>

using namespace std;

long long int arr[100001] = {};

int main() {
	int N,S;
	cin >> N >> S;
	arr[0] = 0;
	for(int i=1; i<=N; i++) {
		cin >> arr[i];
		if(arr[i] >= S) {
			cout << 1;
			return 0;
		}
		arr[i] += arr[i-1];
	}
	if(arr[N] < S) {
		cout << 0;
		return 0;
	}
	int ans = lower_bound(arr,arr+N,S) - arr;
	int right = 1;
	int left = 0;
	long long int param = 0;
	
	while(left <= right) {
		if(param < S) {
			right++;
			if(right == N+1) {
				break;
			}
			param = arr[right] - arr[left];
		} else {
			left++;
			param = arr[right] - arr[left];
			if(ans > right-left+1) {
				ans = right-left+1;
			}
		}
	}
	cout << ans;
}