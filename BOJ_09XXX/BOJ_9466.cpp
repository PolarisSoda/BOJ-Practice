#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int wanted[100001] = {};
bool visited[100001] = {};

int DFS(int num) {
	int start = num;
	int index = num;
	deque<int> ring;
	
	while(true) {
		ring.push_back(index);
		if(visited[index] == true) {
			break;
		}
		visited[index] = true;
		index = wanted[index];
	}
	for(int i=0; i<ring.size(); i++) {
		cout << ring[i] << " ";
	}
	int last = ring[ring.size()-1];
	auto it = lower_bound(ring.begin(),ring.end(),ring.back());
	it++;
	cout << *it << endl;
	if(it == ring.end()) {
		cout << "jey!";
	}
}

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		int N;
		cin >> N;
		for(int j=1; j<=N; j++) {
			cin >> wanted[j];
		}
		int cnt = N;
		for(int j=1; j<=N; j++) {
			if(visited[j] == false) {
				cnt -= DFS(j);
			}
		}
		cout << cnt << "\n";
	}
}