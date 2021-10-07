// 백준 1769번 : 3의 배수
#include <iostream>

using namespace std;

int main()
{
    int ans = 0;
    string num;
    cin >> num;
    
    while (num.length() > 1) {
        int sum = 0;
        for (int i = 0; i < num.length(); i++) {
            sum += num[i] - '0';
        }
        num = to_string(sum);
        ans++;
    }
    
    cout << ans << '\n';
    if (stoi(num) % 3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
