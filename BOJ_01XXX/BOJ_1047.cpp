#include <bits/stdc++.h>

using namespace std;

int X[40],Y[40],L[40];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> X[i] >> Y[i] >> L[i];

    int ans = N;
    for(int fi=0; fi<N; fi++) {
        for(int se=0; se<N; se++) {
            for(int th=0; th<N; th++) {
                for(int fo=0; fo<N; fo++) {
                    //fi 동 se 서 th 북 fo 남
                    bool cond_fi = X[fi] == max({X[fi],X[se],X[th],X[fo]});
                    bool cond_se = X[se] == min({X[fi],X[se],X[th],X[fo]});
                    bool cond_th = Y[th] == max({Y[fi],Y[se],Y[th],Y[fo]});
                    bool cond_fo = Y[fo] == min({Y[fi],Y[se],Y[th],Y[fo]});

                    if(!cond_fi || !cond_se || !cond_th || !cond_fo) continue;

                    int len = (X[fi]-X[se])*2 + (Y[th]-Y[fo])*2;
                    int ocnt = 0, olen = 0;
                    vector<int> inside;

                    for(int i=0; i<N; i++) {
                        bool cond_x = X[i] <= X[fi] && X[i] >= X[se];
                        bool cond_y = Y[i] <= Y[th] && Y[i] >= Y[fo];

                        if(cond_x && cond_y) inside.push_back(L[i]);
                        else ocnt++, olen += L[i];
                    }

                    sort(inside.begin(),inside.end(),greater<int>());
                    for(int now : inside) {
                        if(len <= olen) break;
                        ocnt++, olen += now;
                    }
                    if(len <= olen) ans = min(ans,ocnt);
                }
            }
        }
    }
    cout << ans;
    exit(0);
}