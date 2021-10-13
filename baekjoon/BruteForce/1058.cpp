// 백준 1058번 : 친구
#include <iostream>
#define INF 987654321

using namespace std;

int N;
int arr[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                if (str[j] == 'N') {
                    arr[i][j] = INF;
                    
                } else {
                    arr[i][j] = 1;
                }
            }
        }
    }
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            } else {
                if (arr[i][j] <= 2) {
                    cnt++;
                }
            }
        }
        if (maxNum < cnt) {
            maxNum = cnt;
        }
    }
    cout << maxNum;
    return 0;
}
