// 백준 1715번 : 카드 정렬하기
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int N, num, sum = 0;

    cin >> N;

    while (N--) {
        cin >> num;
        pq.push(num);
    }

    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += (a + b);
        pq.push(a + b);
    }

    cout << sum << '\n';
    return 0;
}