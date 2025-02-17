#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int P;
	cin >> P;
	
	if(P <= 2) cout << 1;
	else {
		P = P/2 - 1;
		int Q = P/3, R = P%3;
		cout << Q*4 + 1 + (R == 0 ? 0 : 2);
	}
}