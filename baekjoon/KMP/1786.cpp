// 백준 1786번 : 찾기
#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;

    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

vector<int> KMP(string text, string pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();
    vector<int> table = makeTable(pattern);
    vector<int> ret;
    int j = 0;

    for (int i = 0; i < textSize; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == patternSize - 1) {
                ret.push_back(i - patternSize + 2);
                j = table[j];
            } else {
                j++;
            }
        }
    }
    return ret;
}

int main() {
    string text = "", pattern = "";
    getline(cin, text);
    getline(cin, pattern);

    vector<int> ret = KMP(text, pattern);

    cout << ret.size() << '\n';
    for (int i : ret) {
        cout << i << ' ';
    }
}