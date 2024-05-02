#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		vector<vector<int>> v(2);
		for(int j = 0; j < 2; j++) {
			int temp; cin >> temp;
			for(int k = 0; k < temp; k++) {
				int temp2; cin >> temp2;
				v[j].push_back(temp2);
			}
		}
		sort(v[0].begin(), v[0].end(), greater<>());
		sort(v[1].begin(), v[1].end(), greater<>());
		if(v[0] == v[1]) { cout << "D" << '\n'; continue; }
		int index = min(v[0].size(), v[1].size());
		
		bool found = false;
		for(int j = 0; j < index; j++) {
			if(v[0][j] > v[1][j]) { cout << "A" << '\n'; found = true; break; }
			if(v[0][j] < v[1][j]) { cout << "B" << '\n'; found = true; break; }
		}
		if (!found) {
			if (v[0].size() > v[1].size()) cout << "A" << '\n';
			else cout << "B" << '\n';
		}
	}
	cout << '\n';
}