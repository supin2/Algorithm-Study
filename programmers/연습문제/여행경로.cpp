#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> Tickets;
vector<string> answer;
vector<bool> visited;

bool dfs(string now, int used) {
    answer.push_back(now);
    
    if (used == Tickets.size()) {
        return true;
    }
    
    for (int i = 0; i < Tickets.size(); i++) {
        if (now == Tickets[i][0] && visited[i] == false) {
            visited[i] = true;
            if (dfs(Tickets[i][1], used + 1) == true) {
                return true;
            }
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    visited.resize(tickets.size(), false);
    Tickets = tickets;
    
    dfs("ICN", 0);
    return answer;
}