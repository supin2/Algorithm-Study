#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for (int i = 1; i <= s.length()/2; i++) {
        int idx = 0;
        int len = s.length();
        
        while (true) {
            int cnt = 0;
            string str = s.substr(idx, i);
            idx += i;
            
            if (idx >= s.length()) {
                break;
            }
            
            while (true) {
                if (str.compare(s.substr(idx, i)) == 0) {
                    cnt++;
                    idx += i;
                } else {
                    break;
                }
            }
            if (cnt > 0) {
                len -= i * cnt;
                
                if (cnt < 9) {
                    len += 1;
                } else if (cnt < 99) {
                    len += 2;
                } else if (cnt < 999) {
                    len += 3;
                } else {
                    len += 4;
                }
            }
            answer = min(answer, len);
        }
    }
    return answer;
}