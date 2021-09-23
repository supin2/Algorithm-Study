// 백준 2805번 : 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long M;
vector<long long> wood;

long long check(long long base) {
    long long sum = 0;
    for (int i = 0; i < wood.size(); i++) {
        if (wood[i] - base <= 0) {
            continue;
        } else {
            sum += wood[i] - base;
        }
    }
    return sum;
}

long long BinarySearch() {
    long long ans = 0;
    long long first = 1, last = wood[N - 1];
    
    while (first <= last) {
        long long mid = (first + last)/2;

        if (check(mid) >= M) {
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
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        long long height;
        cin >> height;
        wood.push_back(height);
    }
    sort(wood.begin(), wood.end());

    cout << BinarySearch() << '\n';
    return 0;
}