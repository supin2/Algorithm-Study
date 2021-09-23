#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(string s) {
    map<string, int> m;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    
    string ans = "";
    string str = "";
    for (auto c : s) {
        if (isdigit(c) == false) {
            str += c;
            if (m.find(str) != m.end()) {
                ans += to_string(m[str]);
                str = "";
            }
        } else {
            ans += c;
        }
    }
    
    int answer = stoi(ans);
    return answer;
}


#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string words[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string ret = "";
    
    for (int i = 0; i < s.length(); ) {
        if (s[i] >= '0' && s[i] <= '9') {
            ret += s[i];
            i++;
        } else {
            for (int j = 0; j < 10; j++) {
                if (s.find(words[j], i) == i) {
                    ret += '0' + j;
                    i += words[j].length();
                    break;
                }
            }
        }
    }
    int answer = stoi(ret);
    return answer;
}