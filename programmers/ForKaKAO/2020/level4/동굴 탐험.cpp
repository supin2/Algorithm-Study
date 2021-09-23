#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<vector<int>> cave;
    map<int, int> before;
    map<int, int> reserve;
    bool visited[200001] = { false };
    cave.resize(n);
    
    for (vector<int> p : path) {
        cave[p[0]].push_back(p[1]);
        cave[p[1]].push_back(p[0]);
    }
    
    for (vector<int> o : order) {
        before[o[1]] = o[0];
    }
    
    if (before[0] != 0) {
        return false;
    }
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < cave[now].size(); i++) {
            int next = cave[now][i];
            if (visited[next] == true) {
                continue;
            }
            if (visited[before[next]] == false) {
                reserve[before[next]] = next;
                continue;
            }
            
            q.push(next);
            visited[next] = true;
            
            if (reserve.find(next) != reserve.end()) {
                q.push(reserve[next]);
                visited[reserve[next]] = true;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            return false;
        }
    }
    return answer;
}