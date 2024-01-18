using namespace std;

struct info {
    int uID;
    int inc;

};

bool operator< (info a,info b) {
    if(a.inc == b.inc) return a.uID > b.uID;
    return a.inc < b.inc;
}
bool operator<= (info a,info b) {
    if(a.inc == b.inc) return a.uID >= b.uID;
    return a.inc <= b.inc;
}
bool operator> (info a,info b) {
    if(a.inc == b.inc) return a.uID < b.uID;
    return a.inc > b.inc;
}
bool operator>= (info a,info b) {
    if(a.inc == b.inc) return a.uID <= b.uID;
    return a.inc >= b.inc;
}
info max(info a,info b) {
    if(a >= b) return a;
    return b;
}

void swap(info &a,info &b) {
    info temp = a;
    a = b;
    b = temp;
}
constexpr int LEN = 100005;
info heap[LEN];
int hsz = 0;

void init() {
    hsz = 0;
}
void addUser(int uID,int inc) {
    info new_user = {uID,inc};
    heap[++hsz] = new_user;
    int cur = hsz;
    while(cur > 1) {
        if(heap[cur] <= heap[cur>>1]) break;
        swap(heap[cur],heap[cur>>1]); 
        cur >>= 1;
    }
}
info Remove() {
    info ret = heap[1];
    heap[1] = heap[hsz--];
    int cur = 1;
    while(true) {
        if(hsz > cur<<1) {
            info left = heap[cur<<1];
            info right = heap[cur<<1|1];
            if(heap[cur] >= max(left,right)) break;
            int idx = left >= right ? cur<<1 : cur<<1|1;
            swap(heap[cur],heap[idx]);
            cur = idx;
        } else if(cur<<1 == hsz && heap[cur] < heap[cur<<1]) {
            swap(heap[cur],heap[cur<<1]);
            cur <<= 1;
            break;
        } else break;
    }
    return ret;
}
int getTop10(int result[10]) {
    info temp[10];
    int cnt = 0;
    while(cnt < 10 && hsz != 0) {
        info now = Remove();
        temp[cnt] = now;
        result[cnt++] = now.uID;
    }
    for(int i=0; i<cnt; i++) addUser(temp[i].uID,temp[i].inc);
    return cnt;
} 
