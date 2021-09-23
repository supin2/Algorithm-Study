// 백준 2217번 : 로프
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, tmp;
    vector<int> V1, V2;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        V1.push_back(tmp);
    }
    sort(V1.begin(), V1.end());

    for (int i = N; i > 0; i--) {
        V2.push_back(V1[N - i] * i);
    }

    cout << *max_element(V2.begin(), V2.end()) << '\n';
    return 0;
}