#include <string>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for(char i : s) {
        if(st.empty() && i == ')') { answer = false; break; }
        if(i == '(') st.push('(');
        else st.pop();
    }
    
    if(!st.empty()) answer = false;

    return answer;
}