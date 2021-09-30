// 백준 11576번 : Base Conversion
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void convert(int num, int p) {
    vector<int> v;
    while (num) {
        v.push_back(num % p);
        num /= p;
    }
    while (!v.empty()) {
        cout << v.back() << ' ';
        v.pop_back();
    }
}

int main() {
    int A, B, m;
    cin >> A >> B >> m;

    int decimal = 0;
    for (int i = m - 1; i >= 0; i--) {
        int num;
        cin >> num;
        decimal += num * pow(A, i);
    }
    convert(decimal, B);
    return 0;
}
