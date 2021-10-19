// 백준 10807번 : 개수 세기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, v, arr[101] = { 0, };
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> v;

    cout << count(arr, arr + N, v);
    return 0;
}