// 백준 2910번 : 빈도 정렬
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, C;
    cin >> N >> C;

    map<int, int> m;
    vector<int> v;
    int maxCnt = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (m[num] == 0) {
            v.push_back(num);
        }
        m[num]++;
    }
    return 0;
}