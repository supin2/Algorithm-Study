// 백준 10798번 : 세로읽기
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    string ret = "";

    int maxLen = -1;
    for (int i = 0; i < 5; i++) {
        string str = "";
        cin >> str;
        maxLen = max(maxLen, (int)str.length());
        v.push_back(str);
    }
    
    for (int i = 0; i < maxLen; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < v[j].size()) {
                ret += v[j][i];
            }
        }
    }
    cout << ret;
    return 0;
}