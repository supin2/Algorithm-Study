// 백준 1543번 : 문서 검색
#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    string text = "", word = "";

    getline(cin, text);
    getline(cin, word);

    for (int i = 0; i < text.length(); ) {
        auto it = text.find(word, i);
        if (it == i) {
            ans++;
            i += word.length();
        } else {
            i++;
        }
    }

    cout << ans;
    return 0;
}