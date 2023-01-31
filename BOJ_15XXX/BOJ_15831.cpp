#include <iostream>
#include <string>

using namespace std;

string cs;
int bcnt = 0;
int wcnt = 0;

void counter(int num) {
    if(cs[num] == 'B') {
        bcnt++;
    } else {
        wcnt++;
    }
}

int main() {
    int N,B,W;
    cin >> N >> B >> W;
    cin >> cs;
    int ans = 0;
    int left = 0, right = 0;
    counter(0);
    while(right <= N-1) {
        if(W <= wcnt && B >= bcnt) {
            if(ans < right-left+1) {
                ans = right-left+1;
            }
        }
        if(left == right) {
            right++;
            counter(right);
        } else {
            if(bcnt > B) {
                if(cs[left] == 'B') {
                    bcnt--;
                } else {
                    wcnt--;
                }
                left++;
            } else {
                right++;
                counter(right);
            }
        }
        
    }
    cout << ans;
}