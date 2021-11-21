// 백준 1076번 : 저항
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<string, pair<int, int>> mp;

    mp["black"] = { 0, 1 };
    mp["brown"] = { 1, 10 };
    mp["red"] = { 2, 100 };
    mp["orange"] = { 3, 1000 };
    mp["yellow"] = { 4, 10000 };
    mp["green"] = { 5, 100000 };
    mp["blue"] = { 6, 1000000 };
    mp["violet"] = { 7, 10000000 };
    mp["grey"] = { 8, 100000000 };
    mp["white"] = { 9, 1000000000 };

    string str = "", tmp = "";
    long long ans;
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        if (i < 2) {
            str += to_string(mp[tmp].first);
        } else {
            ans = stoll(str) * mp[tmp].second;
        }
    }
    cout << ans;
    return 0;
}