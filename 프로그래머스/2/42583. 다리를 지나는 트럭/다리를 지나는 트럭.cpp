#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_n = 0;
    queue <int> bridge;
    for(int i = 0; i < truck_weights.size(); i++) {
        while(1) {
            if(bridge.empty()) {
                bridge.push(truck_weights[i]);
                weight_n += truck_weights[i];
                answer++;
                break;
            } else if(bridge_length <= bridge.size()) {
                weight_n -= bridge.front();
                bridge.pop();
            } else {
                if(weight_n + truck_weights[i] > weight) {
                    bridge.push(0);
                    answer++;
                } else {
                    bridge.push(truck_weights[i]);
                    weight_n += truck_weights[i];
                    answer++;
                    break;
                }
            }
        }
    }
    
    return answer + bridge_length;
}