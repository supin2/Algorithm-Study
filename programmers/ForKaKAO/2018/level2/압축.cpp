#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> alphabet;
    
    for (int i = 0; i < 26; i++) {
        string str = "";
        str += ('A' + i);
        alphabet.push_back(str);
    }
    
    for (int i = 0; i < msg.length(); ) {
        string tmp = "";
        while (true) {
            int pos;
            tmp += msg[i];
            auto iter = find(alphabet.begin(), alphabet.end(), tmp);
            if (iter != alphabet.end()) {
                pos = iter - alphabet.begin();
                i++;
            } else {
                alphabet.push_back(tmp);
                answer.push_back(pos + 1);
                break;
            }
        }
    }
    return answer;
}