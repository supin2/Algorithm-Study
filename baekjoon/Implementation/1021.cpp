// 백준 1021번 : 회전하는 큐
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> dq;
    int N, M, ans = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        int cnt;
        bool flag;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == num) {
                if (j <= dq.size()/2) {
                    cnt = j;
                    flag = true;
                } else {
                    cnt = (int)dq.size() - j;
                    flag = false;
                }
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < cnt; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        } else {
            for (int i = 0; i < cnt; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }
    cout << ans;
    return 0;
}