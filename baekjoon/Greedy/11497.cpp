// 백준 11497번 : 통나무 건너뛰기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> wood(N);

        for (int i = 0; i < N; i++) {
            cin >> wood[i];
        }
        sort(wood.begin(), wood.end());
        int ret = 0;
        for (int i = 2; i < N; i++) {
            ret = max(ret, abs(wood[i] - wood[i - 2]));
        }
        cout << ret << '\n';
    }
    return 0;
}