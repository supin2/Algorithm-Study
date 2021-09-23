// 백준 2847번 : 게임을 만든 동준이
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> score(N);

    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    int cnt = 0;
    for (int i = N - 1; i >= 1; i--) {
        if (score[i - 1] >= score[i]) {
            cnt += score[i - 1] - (score[i] - 1);
            score[i - 1] = score[i] - 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}