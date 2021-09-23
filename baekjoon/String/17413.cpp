// 백준 17413번 : 단어 뒤집기 2
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    string text = "", ret = "";
    stack<char> st;
    bool forward = false;
    getline(cin, text);

    text += '\n';

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch == '<') {
            while (!st.empty()) {
                ret += st.top();
                st.pop();
            }
            ret += ch;
            forward = true;
        } else if (forward) {
            ret += ch;
        } else if (ch == '>') {
            ret += ch;
            forward = false;
        } else if (ch == ' ' || ch == '\n') {
            while (!st.empty()) {
                ret += st.top();
                st.pop();
            }
            ret += ch;
        } else {
            st.push(ch);
        }
    }

    cout << ret;
    return 0;
}