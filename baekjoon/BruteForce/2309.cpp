// 백준 2309번 : 일곱 난쟁이

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX INT_MIN

int arr[9];
int sum = 0;

void input() {
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
}

void solution() {
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (sum - (arr[i] + arr[j]) == 100) {
                arr[i] = MAX;
                arr[j] = MAX;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();

    sort(arr, arr + 9);

    for (int i = 2; i < 9; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}