// 백준 10814번 : 나이순 정렬
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, string>> v;
    while (N--) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}