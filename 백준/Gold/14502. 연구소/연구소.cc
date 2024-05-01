#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int lab[8][8], temp[8][8], temp2[8][8];
int n, m;
int cols[] = {1, 0, -1, 0};
int rows[] = {0, 1, 0, -1};
int safe = 0;
vector<pair<int, int> > v;

void copy() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			temp[i][j] = lab[i][j];
		}
	}
}

void copy2() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			temp2[i][j] = temp[i][j];
		}
	}
}

bool isRange(int x, int y) {
	return ((0 <= x) && (x < n)) && ((0 <= y) && (y < m));
}

void bfs() {
	copy2();
	queue<pair<int, int> > q;
	for(int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int dx = x + cols[i], dy = y + rows[i];
			if(isRange(dx, dy) && temp2[dx][dy] == 0) {
				temp2[dx][dy] = 2;
				q.push(make_pair(dx, dy));
			}
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(temp2[i][j] == 0) count++;
		}
	}
	safe = max(safe, count);
}

void wall(int count) {
	if(count == 3) {
		bfs();
		return;
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(temp[i][j] == 0) {
					temp[i][j] = 1;
					wall(count + 1);
					temp[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if(lab[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(lab[i][j] == 0) {
				copy();
				temp[i][j] = 1;
				wall(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << safe << '\n';
}