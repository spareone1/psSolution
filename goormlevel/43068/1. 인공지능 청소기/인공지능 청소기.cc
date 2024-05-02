#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int x, y, n;
		cin >> x >> y >> n;
		x = x > 0 ? x : -x;
		y = y > 0 ? y : -y;
		if(x + y <= n && (n - (x + y)) % 2 == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}