#include <iostream>
using namespace std;

int n;
int a, b;
char cake[200001];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> cake[i];
	}
	
	for(int i = 1; i <= (n/2); i++) {
		if(cake[i] == 's') a++;
		else b++;
	}
	
	if(a == b) {
		cout << 1 << '\n';
		cout << n/2;
	} else {
		for(int i = n/2 + 1; i <= n; i++) {
			if(cake[i] == 's') a++;
			else b++;
			if(cake[i - n/2] == 's') a--;
			else b--;
			if(a == b) {
				cout << 2 << '\n';
				cout << i - n/2 << ' ' << i;
				break;
			}
		}
	}
}