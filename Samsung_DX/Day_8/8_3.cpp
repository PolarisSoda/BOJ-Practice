#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 26;

struct Trie {
	Trie* child[LEN];
	int cnt = 0;
};
struct info {
	Trie* now;
	int idx;
};

Trie root;

void init() {
	for(int i=0; i<LEN; i++) root.child[i] = NULL;
	root.cnt = 0;
}

int add(char str[]) {
	Trie* cur = &root;

	int len = strlen(str);
	for(int i=0; i<len; i++) {
		int idx = str[i] - 'a';
		if(cur->child[idx] == NULL) {
			Trie* newNode = (Trie*)malloc(sizeof(Trie));
			for(int i=0; i<LEN; i++) newNode->child[i] = NULL;
			newNode->cnt = 0;
			
			cur->child[idx] = newNode;
		}
		cur = cur->child[idx];
	}
	return ++cur->cnt;
}

int remove(char str[]) {
	int ret = 0;
	int len = strlen(str);
	queue<info> task;
	task.push({&root,0});
	while(!task.empty()) {
		Trie* cur = task.front().now;
		int idx = task.front().idx;
		task.pop();

		if(idx == len) {
			ret += cur->cnt;
			cur->cnt = 0;
			continue;
		}
		if(str[idx] == '?') {
			for(int i=0; i<LEN; i++) if(cur->child[i] != NULL) task.push({cur->child[i],idx+1});
		} else {
			if(cur->child[str[idx]-'a'] != NULL) task.push({cur->child[str[idx]-'a'],idx+1});
		}
	}
	return ret;
}

int search(char str[]) {
	int ret = 0;
	int len = strlen(str);

	queue<info> task;
	task.push({&root,0});
	while(!task.empty()) {
		Trie* cur = task.front().now;
		int idx = task.front().idx;
		task.pop();

		if(idx == len) {
			ret += cur->cnt;
			continue;
		}
		if(str[idx] == '?') {
			for(int i=0; i<LEN; i++) if(cur->child[i] != NULL) task.push({cur->child[i],idx+1});
		} else {
			if(cur->child[str[idx]-'a'] != NULL) task.push({cur->child[str[idx]-'a'],idx+1});
		}
	}
	return ret;
}