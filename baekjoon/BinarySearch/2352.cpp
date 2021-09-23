// 백준 2352번 : 반도체 설계
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (vec.empty() || vec.back() < num) {
            vec.push_back(num);
        } else {
            auto iter = lower_bound(vec.begin(), vec.end(), num);
            *iter = num;
        }
    }
    cout << vec.size() << '\n';
    return 0;
}