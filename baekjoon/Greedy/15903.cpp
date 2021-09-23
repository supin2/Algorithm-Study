// 백준 15903번 : 카드 합체 놀이
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long card;
    for (int i = 0; i < n; i++) {
        cin >> card;
        pq.push(card);
    }
    for (int i = 0; i < m; i++) {
        long long sum;
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}