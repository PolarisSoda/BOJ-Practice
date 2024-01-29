#include <bits/stdc++.h>

using namespace std;

struct pii {
    int first,second;
};

bool operator < (const pii &a,const pii &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

set<pii> student[4][3];
unordered_map<int,tuple<int,int,int>> dict;

void init() {
    for(int i=0; i<4; i++) for(int j=0; j<3; j++) student[i][j].clear();
    dict.clear();
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int sex = mGender[0] == 'm' ? 1 : 2;
    student[mGrade][sex].insert({mId,mScore});
    dict[mId] = {mGrade,sex,mScore};
    int ret = (*student[mGrade][sex].rbegin()).first;
    return ret;
}

int remove(int mId) {
    if(dict.count(mId) == 0) return 0;
    int grade,sex,score;
    tie(grade,sex,score) = dict[mId];
    student[grade][sex].erase({mId,score});
    dict.erase(mId);
    if(student[grade][sex].size() == 0) return 0;
    return (*student[grade][sex].begin()).first;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    pii ret = {0,0x7FFFFFF};
    for(int i=0; i<mGradeCnt; i++) {
        for(int j=0; j<mGenderCnt; j++) {
            int sex = mGender[j][0] == 'm' ? 1 : 2;
            auto it = student[mGrade[i]][sex].upper_bound({123,mScore});
            if(it != student[mGrade[i]][sex].end() &&*it < ret) ret = {(*it).first,(*it).second};
        }
    }
    return ret.first;
}