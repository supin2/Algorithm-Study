#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool compare(pair<int, float> p1, pair<int, float> p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    map<int, float> fail, pass;
    
    for (int i = 0; i < stages.size(); i++) {
        fail[stages[i]]++;
        while (stages[i] > 0) {
            pass[stages[i]--]++;
        }
    }
    vector<pair<int, float>> v;
    for (int i = 1; i <= N; i++) {
        if (pass[i] == 0) {
            v.push_back(make_pair(i, 0));
        } else {
            v.push_back(make_pair(i, fail[i]/pass[i]));
        }
    }
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].first);
    }
    return answer;
}




#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<float, int> p1, pair<float, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> failpair;
    int total = stages.size();
    
    int users[501] = { 0, };
    for (auto it = stages.begin(); it != stages.end(); ++it) {
        users[*it - 1]++;
    }

    for (int i = 0; i < N; ++i) {
        if (users[i] == 0) {
            failpair.push_back(make_pair(0, i+1));
        } else {
            failpair.push_back(make_pair((float)users[i]/total, i+1));
            total -= users[i];
        }
    }
    sort(failpair.begin(), failpair.end(), comp);
    
    for (auto it = failpair.begin(); it != failpair.end(); ++it) {
        answer.push_back(it->second);
    }
    return answer;
}