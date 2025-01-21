#include <bits/stdc++.h>

using namespace std;

int S;
string horizon(int num,int types) {
    string ret = "";
    if(types == 0) {
        if(num == 1 || num == 4) {
            ret += " ";
            for(int i=0; i<S; i++) ret += " ";
            ret += " ";
        } else {
            ret += " ";
            for(int i=0; i<S; i++) ret += "-";
            ret += " ";
        }
    } else if(types == 1) {
        if(num == 1 || num == 0 || num == 7) {
            ret += " ";
            for(int i=0; i<S; i++) ret += " ";
            ret += " ";
        } else {
            ret += " ";
            for(int i=0; i<S; i++) ret += "-";
            ret += " ";
        }
    } else if(types == 2) {
        if(num == 1 || num == 4 || num == 7) {
            ret += " ";
            for(int i=0; i<S; i++) ret += " ";
            ret += " ";
        } else {
            ret += " ";
            for(int i=0; i<S; i++) ret += "-";
            ret += " ";
        }
    }
    return ret;
}
string vertical(int num,int types) {
    string ret = "";
    if(types == 0) {
        if(num == 1 || num == 2 || num == 3 || num == 7) {
            ret += " ";
            for(int i=0; i<S; i++) ret += " ";
            ret += "|";
        } else if(num == 5 || num == 6) {
            ret += "|";
            for(int i=0; i<S; i++) ret += " ";
            ret += " ";
        } else {
            ret += "|";
            for(int i=0; i<S; i++) ret += " ";
            ret += "|";
        }
    } else {
        if(num == 2) {
            ret += "|";
            for(int i=0; i<S; i++) ret += " ";
            ret += " ";
        } else if(num == 8 || num == 6 || num == 0) {
            ret += "|";
            for(int i=0; i<S; i++) ret += " ";
            ret += "|";
        } else {
            ret += " ";
            for(int i=0; i<S; i++) ret += " ";
            ret += "|";
        }
    }
    return ret;
}

int main() {
    
    string str;
    cin >> S >> str;

    for(char C : str) cout << horizon(C-'0',0) << " ";
    cout << "\n";

    for(int i=0; i<S; i++) {
        for(char C : str) cout << vertical(C-'0',0) << " ";
        cout << "\n";
    }
    
    for(char C : str) cout << horizon(C-'0',1) << " ";
    cout << "\n";

    for(int i=0; i<S; i++) {
        for(char C : str) cout << vertical(C-'0',1) << " ";
        cout << "\n";
    }
    
    for(char C : str) cout << horizon(C-'0',2) << " ";
}