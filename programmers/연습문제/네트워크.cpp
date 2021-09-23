#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v[201];
bool visited[201] = { false };

void dfs(int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < v[vertex].size(); i++) {
        if (visited[v[vertex][i]] == true) {
            continue;
        }
        dfs(v[vertex][i]);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (computers[i][j] == 1) {
                v[i + 1].push_back(j + 1);
                v[j + 1].push_back(i + 1);
            }
        }
    }
        
    for (int i = 1; i <= n; i++) {
        if (visited[i] == true) {
            continue;
        } else {
            dfs(i);
            answer++;
        }
    }
    return answer;
}