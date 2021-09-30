// 백준 2504번 : 괄호의 값
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str = "";
    stack<char> st;
    cin >> str;

    int temp = 1, sum = 0;
    bool flag = true;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '(') {
            temp *= 2;
            st.push('(');
        } else if (ch == '[') {
            temp *= 3;
            st.push('[');
        } else {
            if (st.empty()) {
                flag = false;
                break;
            } else {
                if (ch == ']') {
                    if (st.top() != '[') {
                        flag = false;
                        break;
                    } else {
                        if (str[i - 1] == '[') {
                            sum += temp;
                            temp /= 3;
                            st.pop();
                        } else {
                            st.pop();
                            temp /= 3;
                        }
                    }
                } else if (ch == ')') {
                    if (st.top() != '(') {
                        flag = false;
                        break;
                    } else {
                        if (str[i - 1] == '(') {
                            sum += temp;
                            temp /= 2;
                            st.pop();
                        } else {
                            st.pop();
                            temp /= 2;
                        }
                    }
                }
            }
        }
    }
    if (!flag) {
        cout << 0;
    } else {
        if (!st.empty()) {
            cout << 0;
        } else {
            cout << sum;
        }
    }
    return 0;
}