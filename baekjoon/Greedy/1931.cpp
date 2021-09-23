// 백준 1931번 : 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    int N, start, end, ans = 1;
    vector<pair<int, int>> mr;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        mr.push_back(make_pair(start, end));
    }
    sort(mr.begin(), mr.end(), compare); // 회의가 끝나는 시간기준 오름차순 정렬

    int now = mr[0].second; // 가장 빨리 끝나는 회의

    for (int i = 1; i < mr.size(); i++) {
        if (mr[i].first < now) continue; // 회의시작 시간이 이전의 회의 끝나는 시간보다 빠른 경우
        now = mr[i].second;
        ans++;
    }
    cout << ans << '\n';
    return 0;    
}