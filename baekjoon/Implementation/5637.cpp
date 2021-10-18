// 백준 5637번 : 가장 긴 단어
#include <bits/stdc++.h>

using namespace std;

bool isValid(char ch) {
    if (isalpha(ch) || ch == '-') {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string text = "", ret = "";
    int maxLen = -1;
    string tmp = "";

    while (true) {
        getline(cin, text);

        for (int i = 0; i < text.length(); i++) {
            char ch = text[i];
            if (isValid(ch)) {
                tmp += ch;

                if (tmp == "E-N-D") {
                    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
                    cout << ret;
                    return 0;
                }
            } else {
                if (tmp.length() != 0) {
                    if (maxLen < (int) tmp.length()) {
                        ret = tmp;
                        maxLen = tmp.length();
                    }
                }
                tmp = "";
            }
        }
    }
    return 0;
}