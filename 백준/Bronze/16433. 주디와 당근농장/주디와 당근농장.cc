#include <iostream>
using namespace std;

int state(int r, int c) {
	if(r % 2 == 0) {
		if(c % 2 == 0) return 1;
		else return 2;
	} else {
		if(c % 2 == 0) return 2;
		else return 1;
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	int st = state(r, c);
	
	if(st == 1) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i % 2) {
					if(j % 2) cout << 'v';
					else cout << '.';
				} else {
					if(j % 2 == 0) cout << 'v';
					else cout << '.';
				}
			}
			cout << '\n';
		}
	} else {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i % 2) {
					if(j % 2 == 0) cout << 'v';
					else cout << '.';
				} else {
					if(j % 2) cout << 'v';
					else cout << '.';
				}
			}
			cout << '\n';
		}
	}
}