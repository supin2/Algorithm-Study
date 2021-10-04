#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool blank = false;
    for (char ch : s) {
        if (ch == ' ') {
            answer += ' ';
            blank = true;
        } else if (isdigit(ch)) {
            answer += ch;
            blank = false;
        } else if (isalpha(ch)) {
            if (blank || answer.length() == 0) {
                answer += toupper(ch);
            } else {
                answer += tolower(ch);
            }
            blank = false;
        }
    }
    return answer;
}