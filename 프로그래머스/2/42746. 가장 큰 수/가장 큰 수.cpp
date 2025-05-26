#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string i, string j) {
    return i + j > j + i;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    for(int i : numbers) {
        v.push_back(to_string(i));
    }
    
    sort(v.begin(), v.end(), compare);
    if(v[0] == "0") return "0";
    for(string i : v) {
        answer.append(i);
    }
    
    return answer;
}