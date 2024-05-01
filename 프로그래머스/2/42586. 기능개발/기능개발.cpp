#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    while(index < progresses.size()) {
        for(int i = index; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        int fin = 0;
        while(1) {
            if(progresses[index] >= 100 && index < progresses.size()) { fin++; index++; }
            else break;
        }
        if(fin != 0) { answer.push_back(fin); fin = 0; }
    }
    return answer;
}