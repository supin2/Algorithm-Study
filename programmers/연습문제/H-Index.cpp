#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int i = 0; i < *max_element(citations.begin(), citations.end()); i++) {
        int count = citations.end() - lower_bound(citations.begin(), citations.end(), i);
        
        if (count >= i) {
            answer = max(answer, i);
        }
    }
    
    return answer;
}