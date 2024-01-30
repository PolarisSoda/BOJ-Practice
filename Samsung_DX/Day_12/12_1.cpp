#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 304;
deque<char> text[LEN];
int prefix[LEN][27];
int H,W; //Height,Width
int h_cur,w_cur; //height cursor, width cursor
int str_len; // total str's length

void init(int h,int w,char str[]) {
	H = h, W = w, str_len = strlen(str), h_cur = 0, w_cur = 0;
	memset(prefix,0,sizeof(prefix));

	int cur = 0;
	for(int i=0; i<LEN; i++) text[i].clear();
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(cur >= str_len) return;
			prefix[i][str[cur]-'a']++;
			text[i].push_back(str[cur]);
			cur++;
		}
	}
}

void insert(char mChar) {
	text[h_cur].insert(text[h_cur].begin()+w_cur,mChar);
	prefix[h_cur][mChar-'a']++;
	int row = h_cur;
	str_len++,w_cur++;
	while(text[row].size() > W) {
		char c = text[row].back();

		prefix[row][c-'a']--;
		text[row].pop_back();

		prefix[++row][c-'a']++;
		text[row].push_front(c);
	}
	if(w_cur == W) h_cur++,w_cur = 0;
}

char moveCursor(int mRow, int mCol) {
	mRow--, mCol--;
	if(mRow*W + mCol >= str_len) {
		h_cur = str_len / W;
		w_cur = str_len % W;
		return '$';
	}
	h_cur = mRow, w_cur = mCol;
	return text[h_cur][w_cur];
}

int countCharacter(char mChar) {
	int ret = 0;
	for(int i=w_cur; i<text[h_cur].size(); i++) ret += text[h_cur][i] == mChar;
	for(int i=h_cur+1; i<H; i++) ret += prefix[i][mChar-'a'];
	return ret;
}
