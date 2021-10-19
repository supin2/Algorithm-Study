// 백준 4458번 : 첫 글자를 대문자로
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string text;
        getline(cin, text);
        text[0] = toupper(text[0]);
        cout << text << '\n';
    }
    return 0;
}