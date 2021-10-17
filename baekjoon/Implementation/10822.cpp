// 백준 10822번 : 더하기
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string str;
    cin >> str;

    stringstream ss(str);
    cin.ignore();
    string tmp;
    int sum = 0;
    while (getline(ss, tmp, ',')) {
        sum += stoi(tmp);
    }
    cout << sum;

    return 0;
}