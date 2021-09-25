// 백준 10820번 : 문자열 분석
#include <iostream>

using namespace std;

int main() {
    string text = "";

    while (getline(cin, text)) {
        int lower = 0, upper = 0, num = 0, blank = 0;

        for (char ch : text) {
            if (isalpha(ch)) {
                if (islower(ch)) {
                    lower++;
                } else {
                    upper++;
                }
            } else if (isdigit(ch)) {
                num++;
            } else {
                blank++;
            }
        }
        cout << lower << " " << upper << " " << num << " " << blank << '\n';
    }
    return 0;
}