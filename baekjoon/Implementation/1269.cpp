// 백준 1269번 : 대칭 차집합
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, ans = 0;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int a : A) {
        if (!binary_search(B.begin(), B.end(), a)) {
            ans++;
        }
    }
    for (int b : B) {
        if (!binary_search(A.begin(), A.end(), b)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}