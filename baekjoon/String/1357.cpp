// 백준 1357번 : 뒤집힌 덧셈
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string ret = to_string(stoi(num1) + stoi(num2));

    reverse(ret.begin(), ret.end());
    cout << stoi(ret);
    
    return 0;
}