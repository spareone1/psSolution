#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int ans[101] = {0, };
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int lt, rt, ball;
        cin >> lt >> rt >> ball;
        for(int j = lt - 1; j < rt; j++) ans[j] = ball;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}