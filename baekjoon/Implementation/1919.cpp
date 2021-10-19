// 백준 1919번 : 애너그램 만들기
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans = 0;

    string str1, str2;
    int arr1[26] = { 0, }, arr2[26] = { 0, };
    cin >> str1 >> str2;

    for (int i = 0; i < str1.length(); i++) {
        arr1[str1[i] - 'a']++;
    }
    for (int i = 0; i < str2.length(); i++) {
        arr2[str2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i]) {
            ans += abs(arr1[i] - arr2[i]);
        }
    }
    cout << ans;
    return 0;
}