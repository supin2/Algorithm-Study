// 백준 1159번 : 농구 경기
#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    string ret = "";
    map<char, int> m;

    cin >> N;

    while (N--) {
        string name;
        cin >> name;

        m[name[0]]++;
    }
    for (auto it : m) {
        if (it.second >= 5) {
            ret += it.first;
        }
    }
    if (ret.length() == 0) {
        cout << "PREDAJA";
    } else {
        cout << ret;
    }
    return 0;
}