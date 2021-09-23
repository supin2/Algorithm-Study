#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}


int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int pos = 0;
    vector<pair<int, int>> food_info;
    int N = food_times.size();
    
    for (int i = 0; i < N; i++) {
        food_info.push_back(make_pair(i + 1, food_times[i]));
    }
    sort(food_info.begin(), food_info.end(), comp);
    
    int pretime = 0;
    for (int i = 0; i < food_info.size(); i++, N--) {
        long long eaten = (long long) (food_info[i].second - pretime) * N;
        
        if (eaten == 0) {
            continue;
        } else if (k >= eaten) {
            k -= eaten;
            pretime = food_info[i].second;
        } else {
            k %= N;    
            sort(food_info.begin() + i, food_info.end());
            return food_info[i + k].first;
        }
    }
    
    return -1;
}