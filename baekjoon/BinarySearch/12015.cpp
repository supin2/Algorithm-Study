// 백준 12015번 : 가장 긴 증가하는 부분 수열 2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if (A.empty() || A.back() < num) {
            A.push_back(num);
        } else {
            auto iter = lower_bound(A.begin(), A.end(), num);
            *iter = num;
        }
    }
    cout << A.size() << '\n';
    return 0;
}