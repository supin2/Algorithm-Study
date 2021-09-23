#include <string>
#include <vector>

using namespace std;

class Trie {
private :
    Trie *alphabet[26];
    int count;
    
public :
    Trie() : alphabet(), count(0) {}
    void Insert(string str) {
        Trie* curr = this;
        curr->count++;
        for (char ch : str) {
            if (curr->alphabet[ch - 'a'] == nullptr) {
                curr->alphabet[ch - 'a'] = new Trie();
            }
            curr = curr->alphabet[ch - 'a'];
            curr->count++;
        }
    }
    int Search(string str) {
        Trie* curr = this;
        int ret = 0;
        
        for (char ch : str) {
            ret++;
            curr = curr->alphabet[ch - 'a'];
            if (curr->count == 1) {
                return ret;
            }
        }
        return ret;
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie *t = new Trie();
    
    for (string w : words) {
        t->Insert(w);
    }
    for (string w : words) {
        answer += t->Search(w);
    }
    return answer;
}

















// #include <string>
// #include <vector>

// using namespace std;

// class Trie {
// private : 
//     Trie *child[26];
//     int count;
    
// public :
//     Trie() : child(), count(0) {}
//     void Insert(string str) {
//         Trie *curr = this;
//         for (char c : str) {
//             curr->count++;
//             if (curr->child[c - 'a'] == nullptr) {
//                 curr->child[c - 'a'] = new Trie();
//             }
//             curr = curr->child[c - 'a'];
//         }
//         curr->count++;
//     }
//     int Search(string str) {
//         Trie *curr = this;
//         int cnt = 0;
//         for (char c : str) {
//             cnt++;
//             curr = curr->child[c - 'a'];
//             if (curr->count == 1) {
//                 return cnt;
//             }
//             if (curr == nullptr) {
//                 return cnt;
//             }
//         }
//     }
// };

// int solution(vector<string> words) {
//     int answer = 0;
//     Trie *t = new Trie();
    
//     for (string str : words) {
//         t->Insert(str);
//     }
//     for (string str : words) {
//         answer += t->Search(str);
//     }
//     return answer;
// }