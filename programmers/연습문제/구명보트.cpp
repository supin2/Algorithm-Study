#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int light = 0, heavy = people.size() - 1;
    while (light <= heavy) {
        if (people[light] + people[heavy] <= limit) {
            light++;
            heavy--;
        } else {
            heavy--;
        }
        answer++;
    }
    return answer;
}