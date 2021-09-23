// 백준 5052번 : 전화번호 목록
#include <iostream>
#include <vector>

using namespace std;

class Trie {
    private :
        int count;
        Trie *number[10];

    public :
        Trie() : count(0), number() {}

        void Insert(string str) {
            Trie *curr = this;
            curr->count++;

            for (char ch : str) {
                if (curr->number[ch - '0'] == nullptr) {
                    curr->number[ch - '0'] = new Trie();
                }
                curr = curr->number[ch - '0'];
                curr->count++;
            }
        }
        bool Search(string str) {
            Trie *curr = this;

            int ret = curr->count;
            for (char ch : str) {
                curr = curr->number[ch - '0'];
                ret = curr->count;
            }
            if (ret == 1) {
                return true;
            } else {
                return false;
            }
        }
};


int main() {
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;
        string number = "";
        vector<string> v;
        Trie *tri = new Trie();
        
        while (n--) {
            cin >> number;
            v.push_back(number);
            tri->Insert(number);
        }
        bool flag = true;
        for (string str : v) {
            if (!tri->Search(str)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}