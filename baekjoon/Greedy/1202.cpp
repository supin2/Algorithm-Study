// 백준 1202번 : 보석 도둑
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    long long N, K, M, V, C;

    cin >> N >> K;
    vector<pair<long long, long long>> jewelry;
    vector<long long> bag;
    priority_queue<long long> pq;

    while (N--) {
        cin >> M >> V;
        jewelry.push_back(make_pair(M, V));
    }
    sort(jewelry.begin(), jewelry.end()); // 보석은 무게 기준 오름차순 정렬

    while (K--) {
        cin >> C;
        bag.push_back(C);
    }
    sort(bag.begin(), bag.end()); // 가방 무게 오름차순 정렬

    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < K; i++) {
        while (idx < N && jewelry[idx].first <= bag[i]) { 
            pq.push(jewelry[idx].second); // 가방 무게보다 작은 보석들의 가격을 넣어줌
            idx++;
        }
        if (!pq.empty()) {
            ans += pq.top(); // 가장 비싼 가격이 정렬됨
            pq.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}