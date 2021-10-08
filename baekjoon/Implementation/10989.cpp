// 백준 10989번 : 수 정렬하기 3
#include <iostream>

using namespace std;

int arr[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}