// 백준 15659번 : 연산자 끼워넣기 (3)
#include <bits/stdc++.h>

using namespace std;

int N, maxNum = -1000000000, minNum = 1000000000;
vector<int> opnd;
vector<string> optr;
int arr[4];

// int calculate(int a, int b, string c) {
//     if (c == "+") {
//         return a + b;
//     } else if (c == "-") {
//         return a - b;
//     } else if (c == "*") {
//         return a * b;
//     } else if (c == "/") {
//         return a / b;
//     }
// }

// void dfs(int cnt) {
//     if (cnt == N - 1) {
//         vector<string> expr;
//         for (int i = 0; i < optr.size(); i++) {
//             string ch = optr[i];

//             if (ch == "+" || ch == "-") {
//                 if (expr.size() > 0) {
//                     expr.push_back(ch);
//                     expr.push_back(to_string(opnd[i + 1]));
//                 } else {
//                     expr.push_back(to_string(opnd[i]));
//                     expr.push_back(ch);
//                     expr.push_back(to_string(opnd[i + 1]));
//                 }
//             } else if (ch == "*" || ch == "/") {
//                 if (expr.size() > 0) {
//                     int a = stoi(expr.back());
//                     int b = calculate(a, opnd[i + 1], ch);
//                     expr.pop_back();
//                     expr.push_back(to_string(b));
//                 } else {
//                     int b = calculate(opnd[i], opnd[i + 1], ch);
//                     expr.push_back(to_string(b));
//                 }
//             } 
//         }
//         int ret = stoi(expr.front());

//         for (int i = 1; i < expr.size(); i += 2) {
//             int b = stoi(expr[i + 1]);
//             ret = calculate(ret, b, expr[i]);
//         }
//         maxNum = max(ret, maxNum);
//         minNum = min(ret, minNum);
//         return;
//     }
//     for (int i = 0; i < 4; i++) {
//         if (arr[i] >= 1) {
//             arr[i]--;
//             if (i == 0) {
//                 optr.push_back("+");
//             } else if (i == 1) {
//                 optr.push_back("-");
//             } else if (i == 2) {
//                 optr.push_back("*");
//             } else if (i == 3) {
//                 optr.push_back("/");
//             }
//             dfs(cnt + 1);
//             optr.pop_back();
//             arr[i]++;
//         }
//     }
// }

void dfs(int cnt) {
    if (cnt == N - 1) {
        int ans = 0;
        for (int i = 0; i < opnd.size(); i++) {
            ans += opnd[i];
        }
        maxNum = max(ans, maxNum);
        minNum = min(ans, minNum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 0) {
            continue;
        }
        arr[i]--;
        int a = opnd[cnt];
        int b = opnd[cnt + 1];

        if (i == 1) {
            opnd[cnt + 1] *= -1;
        } else if (i == 2) {
            opnd[cnt + 1] *= opnd[cnt];
            opnd[cnt] = 0;
        } else if (i == 3) {
            opnd[cnt + 1] = opnd[cnt] / opnd[cnt + 1];
            opnd[cnt] = 0;
        }
        dfs(cnt + 1);
        arr[i]++;
        opnd[cnt] = a;
        opnd[cnt + 1] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    opnd.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> opnd[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    dfs(0);
    
    cout << maxNum << '\n' << minNum << '\n';
    return 0;
}
