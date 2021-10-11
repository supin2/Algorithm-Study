// 백준 1037번 : 약수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0, num; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cout << v.front() * v.back();
    return 0;
}