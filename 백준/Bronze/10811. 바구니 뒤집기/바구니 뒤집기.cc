#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    int arr[101] = {0, };
    for(int i = 0; i < 101; i++) arr[i] = i + 1;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int lt, rt; cin >> lt >> rt;
        for(int j = lt - 1, k = rt - 1; j < k; j++, k--) {
            int tmp = arr[j];
            arr[j] = arr[k];
            arr[k] = tmp;
        }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}