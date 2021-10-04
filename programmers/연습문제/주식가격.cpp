#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        int now = prices[i];
        int time = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] >= now) {
                time++;
            } else {
                time++;
                break;
            }
        }
        answer.push_back(time);
    }
    return answer;
}