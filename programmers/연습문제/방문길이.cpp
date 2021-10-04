#include <string>
#include <cstring>

using namespace std;

int visited[11][11][4];

int solution(string dirs) {
    int answer = 0;
    
    int y = 5, x = 5;
    for (char ch : dirs) {
        if (ch == 'U') {
            if (y - 1 >= 0) {
                if (!visited[y][x][0]) {
                    visited[y][x][0] = true;
                    visited[y - 1][x][1] = true;
                    answer++;
                }
                y--;
            } else {
                continue;
            }
        } else if (ch == 'D') {
            if (y + 1 <= 10) {
                if (!visited[y][x][1]) {
                    visited[y][x][1] = true;
                    visited[y + 1][x][0] = true;
                    answer++;
                }
                y++;
            } else {
                continue;
            }
        } else if (ch == 'R') {
            if (x + 1 <= 10) {
                if (!visited[y][x][2]) {
                    visited[y][x][2] = true;
                    visited[y][x + 1][3] = true;
                    answer++;
                }
                x++;
            } else {
                continue;
            }
        } else if (ch == 'L') {
            if (x - 1 >= 0) {
                if (!visited[y][x][3]) {
                    visited[y][x][3] = true;
                    visited[y][x - 1][2] = true;
                    answer++;
                }
                x--;
            } else {
                continue;
            }
        }
    }    
    return answer;
}