// 백준 11650번 : 좌표 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), cmp);
    
    for (auto a : v) {
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}