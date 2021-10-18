// 백준 18883번 : N M 찍기
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            cout << num << ' ';
            num++;
        }
        cout << num++ << '\n';
    }
    return 0;
}