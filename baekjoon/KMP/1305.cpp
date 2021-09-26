// 백준 1305번 : 광고
#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
    vector<int> table(pattern.size(), 0);
    
    for (int i = 1, j = 0; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

int main() {
    int L;
    string str = "";
    cin >> L >> str;

    vector<int> table = makeTable(str);

    cout << L - table[L - 1];
    return 0;
}