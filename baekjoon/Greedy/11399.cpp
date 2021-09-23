// 백준 11399번 : ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ret = 0;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());
    
    for (int i = v.size() - 1; i >= 0; i--) {
        int sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += v[j];
        }
        ret += sum;
    }
    cout << ret << '\n';
    return 0;
}