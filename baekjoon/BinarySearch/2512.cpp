// 백준 2512번 : 예산
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> budget;

int BinarySearch() {
    int ans = 0;
    int low = 0, high = budget[N - 1];
    while (low <= high) {
        int mid = (low + high)/2;

        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (budget[i] < mid) {
                sum += budget[i];
            } else {
                sum += mid;
            }
        }
        if (sum <= M) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        budget.push_back(b);
    }
    sort(budget.begin(), budget.end());
    cin >> M;

    cout << BinarySearch() << '\n';
    return 0;
}