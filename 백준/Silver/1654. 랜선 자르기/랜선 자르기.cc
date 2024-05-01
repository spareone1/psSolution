#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, n, lt = 1, rt = -2147000000, ans;
    vector<long long> lan;

    cin >> k >> n;
    for(long long i = 0; i < k; i++) {
        long long temp; cin >> temp; lan.push_back(temp);
        if(rt < temp) rt = temp;
    }

    while(lt <= rt) {
        long long mid = (lt + rt) / 2, count = 0;
        for(long long i : lan) count += (i / mid);

        if(count >= n) { ans = mid; lt = mid + 1; }
        else rt = mid - 1;
    }
    cout << ans << '\n';
}