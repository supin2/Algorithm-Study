// 백준 2750번 : 수 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i : v) {
        cout << i << '\n';
    }
    return 0;
}