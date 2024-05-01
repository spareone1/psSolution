#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int ans[101] = {0, };
    for(int i = 0; i < 101; i++) ans[i] = i + 1;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int lt, rt;
        cin >> lt >> rt;
        int tmp = ans[rt - 1];
        ans[rt - 1] = ans[lt - 1];
        ans[lt - 1] = tmp;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}