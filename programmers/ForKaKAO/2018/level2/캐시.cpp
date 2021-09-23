#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
        return 5 * cities.size();
    }
    
    int answer = 0;
    vector<string> cache;
    for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if (cache.empty()) {
            cache.push_back(city);
            answer += 5;
        } else if (cache.size() <= cacheSize) {
            auto iter = find(cache.begin(), cache.end(), city);
            if (iter != cache.end()) {
                cache.erase(iter);
                cache.push_back(city);
                answer++;
            } else {
                if (cache.size() == cacheSize) {
                    cache.erase(cache.begin());
                    cache.push_back(city);
                    answer += 5;
                } else if (cache.size() < cacheSize) {
                    cache.push_back(city);
                    answer += 5;
                }
            }
        }
    }
    return answer;
}