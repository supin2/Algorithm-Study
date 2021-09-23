// 백준 2470번 : 두 용액
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[100001];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int start = 0, end = N - 1;
    int lp = arr[start], rp = arr[end];
    int sum = lp + rp;

    while (start < end) {
        int mid = arr[start] + arr[end];
        if (abs(sum) > abs(mid)) {
            sum = mid;
            lp = arr[start];
            rp = arr[end];
        }
        if (mid <= 0) {
            start++;
        } else {
            end--;
        }
    }
    cout << lp << " " << rp << '\n';
    return 0;
}