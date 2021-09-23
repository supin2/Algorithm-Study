// 백준 5525번 : IOIOI
#include <iostream>

using namespace std;

int main() {
    int N, M, ans = 0;
    string str;

    cin >> N >> M >> str;

    for (int i = 0; i < M; i++) {
        char ch = str[i];
        int cnt = 0;
        if (ch == 'I') {
            while (str[i + 1] == 'O' && str[i + 2] == 'I') {
                cnt++;
                if (cnt == N) {
                    ans++;
                    cnt--;
                }
                i += 2;
            }
        } 
    }
    cout << ans;
    return 0;
}