// 백준 13163번 : 닉네임에 갓 붙이기
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cin.ignore();
    
    while (N--) {
        string text = "", ret = "god";
        int first = -1;
        getline(cin, text);

        for (int i = 0; i < text.length(); i++) {
            if (first == -1 && text[i] == ' ') {
                first = 1;
            } else if (first == 1 && text[i] != ' ') {
                ret += text[i];
            }
        }
        cout << ret << '\n';
    }
    return 0;
}