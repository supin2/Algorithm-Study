// 백준 15685번 : 치킨 배달
#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int N, M, ans = INF;
int city[51][51];
vector<pair<int, int>> house, chicken;
bool visited[14] = { false, };

int calculate(pair<int, int> h, pair<int, int> c) {
    return abs(h.first - c.first) + abs(h.second - c.second);
}

void dfs(int idx, int cnt) {
    if (cnt == M) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            pair<int, int> hpos = house[i];
            int minDiff = INF;
            for (int j = 0; j < chicken.size(); j++) {
                pair<int, int> cpos = chicken[j];
                if (visited[j]) {
                    minDiff = min(minDiff, calculate(hpos, cpos));
                }
            }
            sum += minDiff;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = idx; i < chicken.size(); i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            
            if (city[i][j] == 1) {
                house.push_back(make_pair(i, j));
            } else if (city[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0);
    
    cout << ans;
    return 0;
}