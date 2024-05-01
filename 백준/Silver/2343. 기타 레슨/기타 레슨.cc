#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, sum = 0;
    vector<int> v;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) { int temp; cin >> temp; v.push_back(temp); sum += temp; }

    int lt = *max_element(v.begin(), v.end()), rt = sum, ans; 
    while(lt <= rt) {
        int mid = (lt + rt) / 2, res = 0, cnt = 1;
        for(int i : v) {
            if(res + i > mid) { res = i; cnt++; }
            else res += i;
        }
        if(m >= cnt) { ans = mid; rt = mid - 1; }
        else lt = mid + 1;
    }
    cout << ans << '\n';
}