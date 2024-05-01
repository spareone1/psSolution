#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n[4];    // a, b, c, d
	long long sum[2];  // a + b, c + d
	
	for(int i = 0; i < 4; i++) cin >> n[i];
	
	for(int i = 1; i < 4; i += 2) {
		long long digit = 10;
		long long temp = n[i];
		while(temp / 10 > 0) {
			digit *= 10;
			temp /= 10;
		}
		sum[i / 3] = n[i - 1] * digit + n[i];
	}
	cout << sum[0] + sum[1] << '\n';
}