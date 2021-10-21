// 백준 2161번 : 카드1
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        cout << q.front() << ' ';
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}