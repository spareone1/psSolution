#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    vector<long long> trees;

    cin >> n >> m;
    for(long long i = 0; i < n; i++) { long long temp; cin >> temp; trees.push_back(temp); }

    long long lt = 0, rt = *max_element(trees.begin(), trees.end());
    while(lt + 1 < rt) {
        long long mid = (lt + rt) / 2, cut = 0;
        for(long long i = 0; i < n; i++) cut += trees[i] > mid ? trees[i] - mid : 0;
        if(cut >= m) { lt = mid; }
        else rt = mid;
    }
    cout << lt << '\n';
}