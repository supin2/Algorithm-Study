#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    
    string ret = "";
    for (int i = 0; i < s.length(); ) {
        char ch = s[i];
        if (isdigit(ch)) {
            ret += ch;
            i++;
        } else {
            for (int j = 0; j < 10; j++) {
                if (s.find(arr[j], i) == i) {
                    ret += '0' + j;
                    i += arr[j].length();
                    break;
                }
            }
        }
    }
    answer = stoi(ret);
    return answer;
}