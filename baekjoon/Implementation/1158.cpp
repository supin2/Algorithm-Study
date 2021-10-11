// 백준 1158번 : 요세푸스 문제
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    vector<int> ret;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        ret.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for (int i = 0; i < ret.size() - 1; i++) {
        cout << ret[i] << ", ";
    }
    cout << ret.back() << '>';
    return 0;
}