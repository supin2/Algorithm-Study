// 백준 1701번 : Cubeditor
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int makeTable(string str) {
    vector<int> table(str.size(), 0);

    for (int i = 1, j = 0; i < str.size(); i++) {
        while (j > 0 && str[i] != str[j]) {
            j = table[j - 1];
        }
        if (str[i] == str[j]) {
            table[i] = ++j;
        }
    }
    sort(table.begin(), table.end());
    return table.back();
}

int main() {
    string str = "";
    cin >> str;
    int maxNum = -1;

    for (int i = 0; i < str.size(); i++) {
        maxNum = max(maxNum, makeTable(str.substr(i)));
    }
    cout << maxNum;
    return 0;
}