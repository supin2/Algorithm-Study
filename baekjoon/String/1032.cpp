// 백준 1032번 : 명령 프롬프트
#include <iostream>

using namespace std;

int main() {
    string ret = "";
    int N;
    cin >> N >> ret;

    for (int i = 0; i < N - 1; i++) {
        string str;
        cin >> str;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ret[i]) {
                ret[i] = '?';
            }
        }
    }
    cout << ret;
    return 0;
}