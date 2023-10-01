#include <iostream>
#include <stack>

using namespace std;

long long plusplus(int n);

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    long long ans = 0;
    stack<int*> people;
    
    int* ver = new int[2]{arr[0],1};
    
    people.push(ver);
    
    
    for(int i=1; i<n; i++) {
        int* temp = people.top();
        if(temp[0] > arr[i]) {
            int* ltemp = new int[2]{arr[i],1};
            people.push(ltemp);
        } else if(temp[0] == arr[i]) {
            temp[1]++;
            people.pop();
            people.push(temp);
        } else {
            while(people.top()[0] < arr[i]) {
                temp = people.top();
                people.pop();
                int b = temp[1];
                if(people.empty()) {
                    ans += plusplus(b);
                    break;
                } else {
                    ans += plusplus(b+1) - 1;
                }
            }
            if(!people.empty() && people.top()[0] == arr[i]) {
                int* ltemp = new int[2]{people.top()[0],people.top()[1]+1};
                people.pop();
                people.push(ltemp);
            } else {
                int* ltemp = new int[2]{arr[i],1};
                people.push(ltemp);
            }
            
        }
    }
    if(!people.empty()) {
        while(true) {
            int* temp = people.top();
            people.pop();
            if(people.empty()) {
                ans += plusplus(temp[1]-1);
                break;
            } else {
                ans += plusplus(temp[1]);
            }
        }
    }
    cout << ans;
}

long long plusplus(int n) {
    if(n==0) {
        return 0;
    }
    if(n%2 == 0) {
        long long ans = n/2;
        ans = ans*(n+1);
        return ans;
    } else {
        long long ans = (n+1)/2;
        ans = ans*n;
        return ans;
    }
}
