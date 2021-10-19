// 백준 11931번 : 수 정렬하기 4
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int> pq;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        pq.push(num);
    }

    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}