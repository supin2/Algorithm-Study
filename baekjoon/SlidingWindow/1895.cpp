// 백준 1895번 : 필터
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int R, C, T;
int arr[41][41];

int check(int y, int x) {
    vector<int> v;
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            v.push_back(arr[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[4];
}


int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> T;

    vector<int> filter;
    for (int i = 0; i < R - 2; i++) {
        for (int j = 0; j < C - 2; j++) {
            filter.push_back(check(i, j));
        }
    }

    sort(filter.begin(), filter.end());
    cout << filter.end() - lower_bound(filter.begin(), filter.end(), T);
    return 0;
}