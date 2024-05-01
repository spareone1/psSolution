#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int count[41][2] = {{1, 0}, {0, 1}};
	int index = 2;
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int n; cin >> n;
		if(index <= n) {
			for(index; index <= n; index++) {
				count[index][0] = count[index - 2][0] + count[index - 1][0];
				count[index][1] = count[index - 2][1] + count[index - 1][1];
			}
		}
		cout << count[n][0] << ' ' << count[n][1] << '\n';
	}
}