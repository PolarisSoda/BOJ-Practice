#include <bits/stdc++.h>

using namespace std;

struct info {
    int A,B,C;
};

int N,A,B;

bool Approx(int num) {
    return num >= 1 && num <= N;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> A >> B;
    if(A > B) swap(A,B);


    if((B-A)&1) cout << -1, exit(0);

    queue<info> task;
    task.push({A,B,0});

    int ret = -1;
    while(!task.empty()) {
        int NA = task.front().A, NB = task.front().B, NC = task.front().C;
        task.pop();

        if(NA == NB) { ret = NC; break; }

        int diff = B - A, bias = 1 << NC;
        if(diff>>(NC+1)&1) task.push({NA+bias,NB-bias,NC+1});
        else {
            if(Approx(NA+bias) && Approx(NB+bias)) task.push({NA+bias,NB+bias,NC+1});
            if(Approx(NA-bias) && Approx(NB-bias)) task.push({NA-bias,NB-bias,NC+1});
        }
    }
    cout << ret;
    exit(0);
}