// 백준 11286번 : 절댓값 힙
#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    int N;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        } else {
            pq.push(make_pair(abs(x), x));
        }
    }
    return 0;
}