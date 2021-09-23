// 백준 2812번 : 크게 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string str;

    cin >> N >> K >> str;
    vector<char> v;

    for (int i = 0; i < str.length(); i++) {
        while (!v.empty() && K > 0 && (v.back() < str[i])) {
            v.pop_back();
            K--;
        } 
        v.push_back(str[i]);
    }
    for (int i = 0; i < K; i++) {
        v.pop_back();
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}