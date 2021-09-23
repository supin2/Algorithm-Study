// 백준 2467번 : 용액
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

    int low = 0, high = N - 1;
    int lp = arr[low], rp = arr[high];
    int ret = lp + rp;    

    while (low < high) {
        int mid = arr[low] + arr[high];
        if (abs(ret) > abs(mid)) {
            ret = mid;
            lp = arr[low];
            rp = arr[high];
        }

        if (mid > 0) {
            high--;
        } else {
            low++;
        }
    }
    cout << lp << " " << rp << '\n';
    return 0;
}