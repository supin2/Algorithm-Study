// 백준 11656번 : 접미사 배열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S = "";
    vector<string> v;

    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        v.push_back(S.substr(i));
    }
    sort(v.begin(), v.end());

    for (string str : v) {
        cout << str << '\n';
    }
    return 0;
}