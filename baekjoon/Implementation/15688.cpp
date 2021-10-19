// 백준 15688번 : 수 정렬하기 5
#include <bits/stdc++.h>

using namespace std;

int arr[2000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0, num; i < N; i++) {
        cin >> num;
        arr[num + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i - 1000000 << '\n';
        }
    }
    return 0;
}