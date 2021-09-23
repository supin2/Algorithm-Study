// 백준 5430번 : AC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    string p, arr;

    cin >> T;

    while (T--) {
        cin >> p >> n >> arr;
        vector<int> v;

        string tmp = "";
        for (int i = 0; i < arr.length(); i++) {
            char ch = arr[i];

            if (isdigit(ch)) {
                tmp += ch;
            } else {
                if (tmp.length() != 0) {
                    v.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        bool reversed = false;
        bool errFlag = false;
        for (char ch : p) {
            if (ch == 'R') {
                reversed = !reversed;
            } else if (ch == 'D') {
                if (!v.empty()) {
                    if (reversed) {
                        v.pop_back();
                    } else {
                        v.erase(v.begin());
                    }
                } else {
                    cout << "error" << '\n';
                    errFlag = true;
                    break;
                }
            }
        }
        if (!errFlag) {
            cout << "[";
            if (v.size() > 0) {
                if (reversed) {
                    while (v.size() > 1) {
                        cout << v.back() << ",";
                        v.pop_back();
                    }
                    cout << v.back();
                } else {
                    while (v.size() > 1) {
                        cout << v.front() << ",";
                        v.erase(v.begin());
                    }
                    cout << v.front();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}