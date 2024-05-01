#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long lt = 1, rt = k, mid, cnt;
    while(lt < rt) {
        mid = (lt + rt) / 2;
        cnt = 0;
        for(long long i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }
        if(cnt < k) {
            lt = mid + 1;
        } else {
            rt = mid;
        }
    }
    cout << lt << '\n';
}