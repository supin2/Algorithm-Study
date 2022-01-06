#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getDist(pair<int, int> h, pair<int, int> n) {
    return abs(n.first - h.first) + abs(n.second - h.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> v[10];
    
    v[0].push_back(make_pair(3, 1));
    int dial = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[dial++].push_back(make_pair(i, j));
        }
    }

    pair<int, int> lpos = { 3, 0 };
    pair<int, int> rpos = { 3, 2 };
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        pair<int, int> npos = make_pair(v[num].front().first, v[num].front().second);
        
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            lpos = npos;
        } else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            rpos = npos;
        } else {
            int ldiff = getDist(lpos, npos);
            int rdiff = getDist(rpos, npos);
            if (ldiff < rdiff) {
                answer += "L";
                lpos = npos;
            } else if (ldiff > rdiff) {
                answer += "R";
                rpos = npos;
            } else {
                if (hand.compare("right") == 0) {
                    answer += "R";
                    rpos = npos;
                } else {
                    answer += "L";
                    lpos = npos;
                }
            }
        }
    }
    
    return answer;
}