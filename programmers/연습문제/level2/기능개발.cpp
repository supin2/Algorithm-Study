#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int totalWork = progresses.size();
    
    vector<int> days;
    for (int i = 0; i < totalWork; i++) {
        days.push_back(ceil((float) (100 - progresses[i])/speeds[i]));
    }
    
    stack<int> st;
    int first;
    for (int d : days) {
        if (st.empty()) {
            first = d;
            st.push(d);
        } else {
            if (first >= d) {
                st.push(d);
            } else {
                answer.push_back(st.size());
                while (!st.empty()) {
                    st.pop();
                }
                first = d;
                st.push(d);
            }
        }
    }
    answer.push_back(st.size());
    return answer;
}