// 백준 21921번 : 블로그
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
int arr[250001];

int main() {
    cin >> N >> X;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (i >= X) {
            sum -= arr[i - X];
        }
        sum += arr[i];
        v.push_back(sum);
    }
    int maxNum = *max_element(v.begin(), v.end());
    auto cnt = count(v.begin(), v.end(), maxNum);

    if (maxNum == 0) {
        cout << "SAD";
    } else {
        cout << maxNum << '\n' << cnt;
    }
}