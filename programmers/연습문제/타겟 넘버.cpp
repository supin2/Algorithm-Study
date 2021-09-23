// #include <string>
// #include <vector>

// using namespace std;

// vector<int> Numbers;
// int Target, answer;

// void dfs(int cnt, int sum) {
//     if (cnt == Numbers.size() - 1) {
//         if (sum == Target) {
//             answer++;
//         }
//         return;
//     }
//     dfs(cnt + 1, sum + Numbers[cnt + 1]);
//     dfs(cnt + 1, sum - Numbers[cnt + 1]);
// }

// int solution(vector<int> numbers, int target) {
//     answer = 0;
//     Numbers = numbers, Target = target;
//     dfs(0, numbers[0]);
//     dfs(0, -numbers[0]);
//     return answer;
// }












#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int cnt, sum;
};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    bool visited[21] = { false };
    
    queue<Point> q;
    q.push({ 0, numbers[0] });
    q.push({ 0, -numbers[0] });
    
    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        
        if (now.cnt == numbers.size() - 1) {
            if (now.sum == target) {
                answer++;
            }
            continue;
        }
        q.push({ now.cnt + 1, now.sum + numbers[now.cnt + 1] });
        q.push({ now.cnt + 1, now.sum - numbers[now.cnt + 1] });
    }
    return answer;
}