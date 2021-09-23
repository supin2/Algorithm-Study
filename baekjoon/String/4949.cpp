// 백준 4949번 : 균형잡힌 세상
#include <iostream>
#include <stack>

using namespace std;

int main() {

    while (true) {
        string text = "";
        getline(cin, text);

        if (text == ".") {
            break;
        }

        stack<char> st;
        bool flag = true;
        for (int i = 0; i < text.length(); i++) {
            char ch = text[i];
            if (ch == '(' || ch == '[') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.empty() || st.top() != '(') {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            } else if (ch == ']') {
                if (st.empty() || st.top() != '[') {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (flag && st.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}