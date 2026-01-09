# Reference Notes

## Segment Tree

- 범위는 0부터 len-1까지의 범위(길이 len)
- Query는 [left, right)

```cpp
vector<int> ST = vector<int>(len<<1,0);

void Init() {
    for(int i=len-1; i>0; i--)
        ST[i] = ST[i<<1] + ST[i<<1|1];
}
int Query(int left,int right) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans += ST[left++];
        if(right&1) ans += ST[--right];
    }
    return ans;
}
void Update(int lo,int value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1)
        ST[lo>>1] = ST[lo] + ST[lo^1];
}
```

## Lazy Segment
ll Init(int node)
## Kitamasa

## Union Find & MST Kruskal
- Index는 1부터 시작
```cpp
struct info {int s,e,x;};

vector<info> edge;
int pt[LEN];

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}
void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

int main() {
    for(int i=1; i<=N; i++) pt[i] = i;
    sort(edge.begin(),edge.end(),compare);

    int sum = 0, ecnt = 0;
    for(info now : edge) {
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            sum += now.x;
            if(++ecnt == N-1) //Kruskal Done!
        }
    }
}
```

## Parametric Search
```cpp
while(left+1<right) {
    int mid = (left+right) >> 1;
    if(check(mid)) right = mid;
    else left = mid;
}
```

## Knapsack
- `W`는 무게, `P`는 가격
- `DP[i][j]`는 지금 i번째까지 확인했고, 무게가 `j`일때의 최대 가치
- 배열 2개 Swap으로도 가능
```cpp
int W,P;
for(int i=1; i<=N; i++) {
    for(int j=1; j<=K; j++) {
        if(W > j) DP[i][j] = DP[i-1][j];
        else DP[i][j] = max(DP[i-1][j-W]+P,DP[i-1][j]);
    }
}
```

## EGCD
```cpp
int Euclidean(int a,int b) {
    int r = a % b;
    while(r == 0)
        r = a % b, a = b, b = r;
    return a;
}
```

## Floyd Warshall
- 반드시 거쳐가는 정점(intermediate)가 Outer loop일 것
- 음수 사이클은 `dist[v][v]` 확인
```cpp
for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int k=1; k<=N; k++)
    dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
```

## Matrix Power
```cpp
typedef vector<vector<ll>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
    int sz = a.size();
    matrix ret(sz,vector<ll>(sz));

    for(int i=0; i<sz; i++) {
        for(int j=0; j<sz; j++) {
            for(int k=0; k<sz; k++) {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= DIV;
            }
        }
    }
    return ret;
}

matrix power(matrix X,ll P) {
    int sz = X.size();
    matrix ret(sz,vector<ll>(sz));
    for(int i=0; i<sz; i++) ret[i][i] = 1;
    while(P) {
        if(P&1LL) ret = ret * X;
        X = X * X;
        P >>= 1LL;
    }
    retun ret;
}
```

## KMP
- 앞부분은 실패함수
- 매칭 부분에서 `j`는 현재까지 연속으로 매칭된 문자열의 길이
```cpp
int main() {
    string T,P;
    vector<int> FF(P.length());
    vector<int> ans;

    int j = 0;
    for(int i=1; i<P.length(); i++) {
        while(j > 0 && P[i] != P[j]) j = FF[j-1];
        if(P[i] == P[j]) FF[i] = j + 1, j++;
    }

    j = 0;
    for(int i=0; i<T.length(); i++) {
        while(j > 0 && T[i] != P[j]) j = FF[j-1];
        if(T[i] == P[j]) {
            if(j == P.length() - 1) {
                ans.push_back(i - P.length() + 1);
                j = FF[j];
            } else j++;
        }
    }
}
```

## Dijkstra
```cpp
while(!pq.empty()) {
    int now = pq.front().first;
    int total = pq.front().second;
    pq.pop();

    if(total > dist[now]) continue;

    int sz = edge[now].size();
    for(int i=0; i<sz; i++) {
        int next = edge[now][i].first;
        int w = edge[now][i].second;

        if(dist[next] > total + w) pq.push({next,dist[next]=total+w});
    }
}
```

## Bellman-Ford

## Power
```cpp
ll power(ll X,ll P) {
    ll ret = 1;
    while(P) {
        if(P&1) ret = (ret*X)%DIV;
        X = (X*X)%DIV;
        P >>= 1;
    }
    return ret;
}
```

## Bipartite Matching
- 1부터 N까지의 이분매칭
```cpp
bool DFS(int num) {
    for(int next: edge[num]) {
        if(visited[next]) continue;
        visited[next] = true;
        if(!indicator[next] || DFS(indicator[next])) {
            indicator[next] = num;
            return true;
        }
    }
    return false;
}

int main() {
    for(int i=1; i<=N; i++) {
        memset(visited,false,sizeof(visited));
        if(DFS(i)) count++;
    }
}
```

## Convex Hull
```cpp
typedef long long ll;
typedef long double ld;
struct Linear {
    ld ix;
    ll ratio, y;
};

constexpr int MAX = 100001;
ll DP[MAX],A[MAX],B[MAX];
vector<Linear> EQ;

ld getinterx(Linear a,Linear b) {
    return (ld)(a.y-b.y)/(b.ratio-a.ratio);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    
    for(int i=1; i<=N; i++) {
        Linear now = {0,B[i-1],DP[i-1]};
        while(EQ.size() >= 1) {
            now.ix = getinterx(now,EQ.back());
            if(now.ix < EQ.back().ix) EQ.pop_back();
            else break;
        }
        
        EQ.push_back(now);
        ll left = -1;
        ll right = EQ.size();
        ll pivot = 0;
        while(left+1<right) {
            ll mid = (left+right)/2;
            if(EQ[mid].ix < A[i]) pivot = left = mid;
            else right = mid;
        }
        DP[i] = EQ[pivot].ratio*A[i] + EQ[pivot].y;
    }
    cout << DP[N];
}
```

## LCA
- Sparse table의 index에 주의
```cpp
constexpr int LEN = 100001;
int DP[LEN][1<<5],H[LEN];
vector<int> edge[LEN];

void DFS(int now,int prev,int height) {
	H[now] = height;
	for(int i=1; (1<<i)<=height; i++) DP[now][i] = DP[DP[now][i-1]][i-1]; 
		
	for(int next : edge[now]) {
		if(next == prev) continue;
        DP[next][0] = now;
		DFS(next,now,height+1);
	}
}

int LCA(int A,int B) {
	if(H[A] > H[B]) swap(A,B);
	int diff = H[B] - H[A], cur = 31;
	while(diff) {
		if((diff>>cur)&1) B = DP[B][cur], diff = H[B] - H[A];
		else cur--;
	}
	while(A != B) {
		int PA = DP[A][0], PB = DP[B][0];
		for(int j=0; (1<<j)<=H[A]; j++) {
			if(DP[A][j] != DP[B][j]) PA = DP[A][j], PB = DP[B][j];
			else break;
		}
		A = PA, B = PB;
	}
	return A;
}

int main() {
	memset(DP,-1,sizeof(DP));
	DFS(1,-1,0);
	cout << LCA(A,B);
	exit(0);
}
```

## SCC
- 코사라주 알고리즘
```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 10001;
vector<int> edge[2][LEN];
bool visited[LEN];
stack<int> order;
vector<vector<int>> SCC;

void DFS(int now) {
    visited[now] = true;
    for(int next : edge[0][now]) if(!visited[next]) DFS(next);
    order.push(now);
}
void DFS_R(int now) {
    visited[now] = true;
    SCC.back().push_back(now);
    for(int next : edge[1][now]) if(!visited[next]) DFS_R(next);
}

int main() {
    memset(visited,false,sizeof(visited));
    for(int i=1; i<=V; i++) if(!visited[i]) DFS(i);

    memset(visited,false,sizeof(visited));
    while(!order.empty()) {
        int now = order.top();
        order.pop();
        if(!visited[now]) {
            SCC.push_back(vector<int>());
            DFS_R(now);
        }
    }
}
```