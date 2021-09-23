#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private : 
    Trie *child[26];
    int count;

public :
    Trie() : child(), count(0) {}
    void Insert(string str) {
        Trie *curr = this;
        for (auto ch : str) {
            curr->count++;
            if (curr->child[ch - 'a'] == nullptr) {
                curr->child[ch - 'a'] = new Trie();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->count++;
    }
    int Search(string str) {
        Trie *curr = this;
        for (auto ch : str) {
            if (ch == '?') {
                return curr->count;
            }
            curr = curr->child[ch - 'a'];
            if (curr == nullptr) {
                return 0;
            }
        }
        return curr->count;
    }
};

Trie tri[100001];
Trie re_tri[100001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (auto str : words) {
        tri[str.length()].Insert(str);
        reverse(str.begin(), str.end());
        re_tri[str.length()].Insert(str);
    }
    for (auto str : queries) {
        if (str[0] != '?') {
            answer.push_back(tri[str.length()].Search(str));
        } else {
            reverse(str.begin(), str.end());
            answer.push_back(re_tri[str.length()].Search(str));
        }
    }
    return answer;
}