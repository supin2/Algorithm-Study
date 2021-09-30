// 백준 2693번 : N번째 큰 수
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        vector<int> v(10);
        for (int i = 0; i < 10; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        
        cout << v[2] << '\n';
    }
    return 0;
}