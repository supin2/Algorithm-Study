// 백준 11328번 : Strfry
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string a, b;
        int arr1[26] = { 0, }, arr2[26] = { 0, };
        cin >> a >> b;

        for (char ch : a) {
            arr1[ch - 'a']++;
        }
        for (char ch : b) {
            arr2[ch - 'a']++;
        }

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}