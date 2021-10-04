#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{ {}, {} };
    
    char last = words[0].back();
    vector<string> check{words[0]};
    
    for (int i = 1; i < words.size(); i++) {
        if (words[i].front() != last || find(check.begin(), check.end(), words[i]) != check.end()) {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        last = words[i].back();
        check.push_back(words[i]);
    }
    return answer;
}