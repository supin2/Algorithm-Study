// 백준 1120번 : 문자열
#include <iostream>

using namespace std;

int main() {
    int ans = 987654321;
    string A, B;
    cin >> A >> B;

    int aLen = A.length(), bLen = B.length();

    for (int i = 0; i <= bLen - aLen; i++) {
        int cnt = 0;

        for (int j = 0; j < aLen; j++) {
            if (A[j] != B[j + i]) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}