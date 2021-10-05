#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int idx = -1;
    int move = name.length() - 1;
    for (int i = 0; i < name.length(); i++) {
        char ch = name[i];
        if (ch == 'A') {
            idx = i;
            while (name[idx] == 'A' && idx < name.length()) {
                idx++;
            }
            int fromLeft = max(0, i - 1);
            int fromRight = name.length() - idx;
            move = min(move, fromLeft + fromRight + min(fromLeft, fromRight));
        }
    }
    answer += move;
    
    for (int i = 0; i < name.length(); i++) {
        answer += min(name[i] - 'A', 'A' + 26 - name[i]);
    }
    return answer;
}