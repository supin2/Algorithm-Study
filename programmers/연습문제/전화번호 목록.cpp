#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> m;
    
    for (string pb : phone_book) {
        m[pb]++;
    }
    for (int i = 0; i < phone_book.size(); i++) {
        string pb = phone_book[i];
        string tmp = "";
        for (int j = 0; j < pb.length(); j++) {
            tmp += pb[j];
            if (m[tmp] && tmp != pb) {
                return false;
            }
        }
    }
    return answer;
}