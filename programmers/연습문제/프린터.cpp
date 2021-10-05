#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++) {
        int priority = priorities[i];
        q.push(make_pair(priority, i));
        pq.push(priority);
    }
    while (!q.empty()) {
        if (q.front().first == pq.top()) {
            answer++;
            if (q.front().second == location) {
                break;
            }
            pq.pop();
            q.pop();
        } else {
            pair<int, int> tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    return answer;
}