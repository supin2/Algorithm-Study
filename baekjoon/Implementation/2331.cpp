// 백준 2331번 : 반복수열
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int convert(int num, int p) {
    int ret = 0;
    while (num) {
        int tmp = num % 10;
        ret += pow(tmp, p);
        num /= 10;
    }
    return ret;
}

int main() {
    int A, P, ret = 0;
    vector<int> v;
    cin >> A >> P;
    
    v.push_back(A);
    
    while (true) {
        int num = convert(v.back(), P);
        auto it = find(v.begin(), v.end(), num);
        
        if (it != v.end()) {
            ret = it - v.begin();
            break;
        } else {
            v.push_back(num);
        }
    }
    cout << ret;
    return 0;
}