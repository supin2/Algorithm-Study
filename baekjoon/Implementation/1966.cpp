// 백준 1966번 : 프린터 큐
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            q.push(make_pair(num, i));
            pq.push(num);
        }
        int cnt = 0;
        while (!q.empty()) {
            int val = q.front().first;
            int idx = q.front().second;
            int canPrint = pq.top();
            q.pop();

            if (val == canPrint) {
                pq.pop();
                cnt++;
                if (idx == M) {
                    cout << cnt << '\n';
                    break;
                }
            } else {
                q.push(make_pair(val, idx));
            }
        }
    }
    return 0;
}