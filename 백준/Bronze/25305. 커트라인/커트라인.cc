#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	vector<int> v;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.rbegin(), v.rend());
	cout << v[k - 1] << '\n';
}