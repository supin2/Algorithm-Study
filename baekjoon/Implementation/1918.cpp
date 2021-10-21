// 백준 1918번 : 후위 표기식
#include <bits/stdc++.h>

using namespace std;

bool priority(char ch) {
    switch (ch) {
        case '-' :
        case '+' :
            return 0;
        case '*' :
        case '/' :
            return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    string ans = "";
    stack<char> optr;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            cout << ch;
        } else {
            if (ch == '(') {
                optr.push('(');
            } else if (ch == ')') {
                while (!optr.empty() && optr.top() != '(') {
                    cout << optr.top();
                    optr.pop();
                }
                optr.pop();
            } else {
                if (ch == '+' || ch == '-') {
                    while (!optr.empty() && optr.top() != '(') {
                        cout << optr.top();
                        optr.pop();
                    }
                    optr.push(ch);
                } else if (ch == '*' || ch == '/') {
                    while (!optr.empty() && (optr.top() == '*' || optr.top() == '/')) {
                        cout << optr.top();
                        optr.pop();
                    }
                    optr.push(ch);
                }
            }
        }
    }
    while (!optr.empty()) {
        cout << optr.top();
        optr.pop();
    }

    return 0;
}