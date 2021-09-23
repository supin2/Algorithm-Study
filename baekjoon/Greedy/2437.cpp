// 백준 2437번 : 저울
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);  
    }
    sort(v.begin(), v.end());

    if (v[0] != 1) {
        cout << 1 << '\n';
    } else {
        int sum = v[0];

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > sum + 1) {
                break;
            }
            sum += v[i];
        }
        cout << sum + 1 << '\n';
    }
    return 0;
}