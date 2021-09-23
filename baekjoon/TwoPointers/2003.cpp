// 백준 2003번 : 수들의 합 2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, ans = 0;
    cin >> N >> M;

    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int first = 0, end = 0;
    int partial_sum = 0;
    while (end <= N) {
        if (partial_sum < M) {
            partial_sum += arr[end++];
        } else if (partial_sum >= M) {
            partial_sum -= arr[first++];
        }
        if (partial_sum == M) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}