#include <iostream>
using namespace std;

int find(int* arr, int n) {
    if(arr[n] == n) return n;
    else return arr[n] = find(arr, arr[n]);
}

int uni(int* arr, int n1, int n2) {
    int a = find(arr, n1);
    int b = find(arr, n2);
    if(a != b) { arr[a] = b; return 1; }
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, arr[1001];
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m, ans = 0;
        cin >> n >> m;
        for(int j = 0; j < n + 1; j++) arr[j] = j;
        for(int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            if(uni(arr, a, b)) ans++;
        }
        cout << ans << '\n';
    }
}