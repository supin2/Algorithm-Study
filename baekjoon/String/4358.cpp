// 백준 4358번 : 생태학
#include <iostream>
#include <map>

using namespace std;

int main() {
    string title = "";
    int total = 0;
    map<string, int> m;

    while (getline(cin, title)) {
        total++;
        m[title]++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto it : m) {
        double d = (double) it.second / total;
        cout << it.first << ' ' << d * 100 << '\n';
    }

    return 0;
}