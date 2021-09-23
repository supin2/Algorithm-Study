// 백준 11000번 : 강의실 배정
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N, ans = 0;
    cin >> N;
    pair<int, int> p[N];
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + N);

    pq.push(p[0].second);

    for (int i = 1; i < N; i++) {
        if (pq.top() <= p[i].first) {
            pq.pop();
            pq.push(p[i].second);
        } else {
            pq.push(p[i].second);
        }
    }
    cout << pq.size() << endl;
    return 0;
}