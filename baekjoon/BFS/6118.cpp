// 백준 6118번 : 숨바꼭질
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v[200001];
int cache[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    cache[1] = 1;

    while (!q.empty()) {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (auto next : v[now]) {
            if (!cache[next]) {
                cache[next] = dist + 1;
                q.push(make_pair(next, dist + 1));
            }
        }
    }
    int maxNum = *max_element(cache + 1, cache + N + 1);
    int idx = -1, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (cache[i] == maxNum) {
            cnt++;
            if (idx == -1) {
                idx = i;
            } else {
                idx = min(idx, i);
            }
        }
    }
    cout << idx << ' ' << maxNum - 1 << ' ' << cnt;
    return 0;
}