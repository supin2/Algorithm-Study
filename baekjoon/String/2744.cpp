// 백준 2744번 : 대소문자 바꾸기
#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    for (char ch : str) {
        char temp;
        if (islower(ch)) {
            temp = toupper(ch);
        } else {
            temp = tolower(ch);
        }
        cout << temp;
    }
    return 0;
}