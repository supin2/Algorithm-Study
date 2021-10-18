// 백준 12605번 : 단어순서 뒤집기
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string text = "";
        stack<string> st;

        getline(cin, text);
        string temp;
        stringstream ss(text);
        while (getline(ss, temp, ' ')) {
            st.push(temp);
        }
        cout << "Case #" << i + 1 << ": ";
        while (!st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    }
    return 0;
}