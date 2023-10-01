#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll DP[16][100001] = {};
vector<int> DDR;

int main() {
	while(true) {
		int temp;
		cin >> temp;
		if(!temp) {
			break;
		}
		DDR.push_back(temp);
	}
}