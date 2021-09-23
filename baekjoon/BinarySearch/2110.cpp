// 백준 2110번 : 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int check(int base) {
    int cnt = 1;
    int prev = house[0];
    for (int i = 1; i < N; i++) {
        if (house[i] - prev >= base) {
            cnt++;
            prev = house[i];
        }
    }
    return cnt;
}

int BinarySearch() {
    int ans = 0;
    int first = 1, last = house[N - 1];
    while (first <= last) {
        int mid = (first + last)/2;

        if (check(mid) >= C) {
            ans = max(ans, mid);
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        house.push_back(h);
    }
    sort(house.begin(), house.end());

    cout << BinarySearch() << '\n';
    return 0;
}