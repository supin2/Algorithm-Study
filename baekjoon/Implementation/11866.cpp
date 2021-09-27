// 백준 11866번 : 요세푸스 문제 0
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    vector<int> ret;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;

        if (cnt == K) {
            ret.push_back(now);
            cnt = 0;
        } else {
            q.push(now);
        }
    }
    cout << "<";
    for (int i = 0; i < ret.size() - 1; i++) {
        cout << ret[i] << ", ";
    }
    cout << ret.back() << ">";
    return 0;
}