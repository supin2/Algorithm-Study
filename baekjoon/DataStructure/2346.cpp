// 백준 2346번 : 풍선 터뜨리기
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    deque<pair<int, int>> dq;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        dq.push_back(make_pair(i + 1, num));
    }

    int move = -1;

    while (!dq.empty()) {
        cout << dq.front().first << ' ';
        move = dq.front().second;
        dq.pop_front();
        
        if (move > 0) {
            for (int i = 0; i < move - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < abs(move); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}
