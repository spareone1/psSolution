#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l;
	int fruits[10000];
	
	cin >> n >> l;
	for(int i = 0; i < n; i++) {
		cin >> fruits[i];
	}
	
	sort(fruits, fruits + n);
	
	for(int i = 0; i < n; i++) {
		if(fruits[i] <= l) {
			l++;
		};
	}
	cout << l << '\n';
}