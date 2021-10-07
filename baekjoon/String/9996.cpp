// 백준 9996번 : 한국이 그리울 땐 서버에 접속하지
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    vector<string> ret;
    string temp;
    
    while (getline(ss, temp, delimiter)) {
        ret.push_back(temp);
    }
    return ret;
}

int main() {
    int N;
    string pattern;
    cin >> N >> pattern;
    
    vector<string> p = split(pattern, '*');
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        vector<bool> visited(str.length() + 1, false);
        bool isSame = true;
        
        for (int j = 0; j < p[0].length(); j++) {
            if (str[j] == p[0][j]) {
                visited[j] = true;
            } else {
                isSame = false;
                break;
            }
        }
        if (!isSame) {
            cout << "NE" << '\n';
            continue;
        }
        int idx = str.length() - 1;
        for (int j = p[1].length() - 1; j >= 0; j--) {
            if (visited[idx] || str[idx] != p[1][j]) {
                isSame = false;
                break;
            }
            idx--;
        }
        if (!isSame) {
            cout << "NE" << '\n';
        } else {
            cout << "DA" << '\n';
        }
    }
    return 0;
}