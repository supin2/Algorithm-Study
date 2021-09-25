// 백준 10808번 : 알파벳 개수
#include <iostream>

using namespace std;

int main() {
    string str = "";
    int alpha[26] = { 0, };
    cin >> str;

    for (char ch : str) {
        alpha[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << ' ';
    }
    return 0;
}