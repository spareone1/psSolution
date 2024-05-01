#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long lt = 1, rt = *max_element(times.begin(), times.end()) * n, ans = *max_element(times.begin(), times.end()) * n;
    while(lt <= rt) {
        long long mid = (lt + rt) / 2, sum = 0;
        for(long long i = 0; i < times.size(); i++) sum += mid / times[i];
        if(sum >= n) { ans = mid; rt = mid - 1; }
        else lt = mid + 1;
    }
    return ans;
}