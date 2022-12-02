#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cable {
    int left;
    int right;
    int distance;
};

struct comp {
    bool operator() (const cable &a, const cable &b) {
        return a.distance > b.distance;
    }
};

bool connected[100001] = {};
priority_queue<cable,vector<cable>,comp> pq;
vector<cable> company;

int main() {
    int N,K,previous;
    cin >> N >> K;
    cin >> previous;

    company.push_back({0,0,0});

    for(int i=1; i<N; i++) {
        int temp;
        cin >> temp;
        pq.push({i,i+1,temp-previous});
        company.push_back({i-1,i+1,temp-previous});
        previous = temp;
    }
    company.push_back({N-1,N+1,0x7FFFFFFF});

    long long int ans = 0;

    while(!pq.empty()) {
        if(K==0) {
            break;
        }
        int sindex = pq.top().left;
        int eindex = pq.top().right;
        int dist = pq.top().distance;
        pq.pop();

        if(sindex >= 1 && eindex <= N) {
            if(company[sindex].right == eindex && company[eindex].left == sindex) {
                ans += static_cast<long long int>(dist);

                int leftlimit = company[sindex].left;
                int rightlimit = company[sindex].right;

                dist = company[leftlimit].distance + company[eindex].distance - dist;
                company[leftlimit].distance = dist;
                pq.push({leftlimit,rightlimit,dist});

                company[leftlimit].right = rightlimit;
                company[rightlimit].left = leftlimit;
                K--;
            }
        }
    }
    cout << ans;
}