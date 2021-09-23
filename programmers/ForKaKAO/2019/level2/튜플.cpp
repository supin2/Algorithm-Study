#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    
    string tmp = "";
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] >= '0' && s[i] <= '9') { 
            tmp += s[i];
        } else {
            if (tmp != "") {
                m[stoi(tmp)]++;
                tmp = "";
            }
        }
    }
    answer.resize(m.size());
    for (auto &a : m) {
        answer[int(m.size()) - a.second] = a.first;
    } 
    return answer;
}

// vector<int> solution(string s) {
//     vector<int> answer;
//     vector<string> vec[]
    
//     for (int i = 1; i < s.length() - 1; i++) {
//         if (s[i] == '{') {
//             int j = i + 1;
//             while (true) {
//                 if (s[j] == '}') break;
//                 else if (s[j] == ',') {
                    
//                 }
//             }
//         }
        
//     }
//     return answer;
// }