// 백준 1713번 : 후보 추천하기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, rec;
    cin >> N >> rec;

    vector<int> v;
    map<int, int> m;
    int maxCnt = -1;
    for (int i = 0; i < rec; i++) {
        int student;
        cin >> student;

        auto it = find(v.begin(), v.end(), student);

        if (it != v.end()) {
            m[student]++;
        } else {
            if (v.size() < N) {
                v.push_back(student);
                m[student]++;
            } else {
                int idx = -1;
                int minCnt = 1002;
                for (int i = 0; i < v.size(); i++) {
                    int temp = v[i];
                    if (m[temp] < minCnt) {
                        idx = i;
                        minCnt = m[temp];
                    }
                }
                m[v[idx]] = 0;
                v.erase(v.begin() + idx);
                v.push_back(student);
                m[student]++;
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << ' ';
    }
    return 0;
}