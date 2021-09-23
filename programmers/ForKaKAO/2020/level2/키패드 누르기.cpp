#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left_pos = { 3, 0 };
    pair<int, int> right_pos = { 3, 2 };
    vector<pair<int, pair<int, int>>> dial;
    int num = 1;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            dial.push_back({ num, { i, j }});
        }
    }
    dial[10].first = 0;
    
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        int idx = num - 1;
        if (num == 0) {
            idx = 10;
        }
        int y = dial[idx].second.first;
        int x = dial[idx].second.second;
        int dist1 = abs(y - left_pos.first) + abs(x - left_pos.second);
        int dist2 = abs(y - right_pos.first) + abs(x - right_pos.second);
        
        if (num == 1 || num == 4 || num == 7) {
            left_pos = { y, x };
            answer += "L";
        } else if (num == 3 || num == 6 || num == 9) {
            right_pos = { y, x };
            answer += "R";
        } else {
            if (dist1 < dist2) {
                left_pos = { y, x };
                answer += "L";
            } else if (dist1 > dist2) {
                right_pos = { y, x };
                answer += "R";
            } else if (dist1 == dist2) {
                if (hand == "left") {
                    left_pos = { y, x };
                    answer += "L";
                } else {
                    right_pos = { y, x };
                    answer += "R";
                }
            }
        }
    }
    
    return answer;
}