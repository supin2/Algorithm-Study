#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    
    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i] - 1;

        for (int j = 0; j < board.size(); j++) {
            int doll = board[j][move];
            if (doll != 0) {
                if (!basket.empty()) {
                    if (basket.back() == doll) {
                        answer += 2;
                        basket.pop_back();
                        board[j][move] = 0;
                        break;
                    } 
                }
                basket.push_back(doll);
            }
        }
    }
    return answer;
}