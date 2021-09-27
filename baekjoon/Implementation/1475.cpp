// 백준 1475번 : 방 번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str = "";
    cin >> str;

    vector<int> cnt(9);
    for (char ch : str) {
        if (ch == '6' || ch == '9') {
            cnt[6]++;
        } else {
            cnt[ch - '0']++;
        }
    }

    if (cnt[6] > 0) {
        if (cnt[6] % 2 == 1) {
            cnt[6] /= 2;
            cnt[6]++;
        } else {
            cnt[6] /= 2;
        }
    }

    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}