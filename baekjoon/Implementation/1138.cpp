// 백준 1138번 : 한 줄로 서기
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> ret(N);

    for (int i = 0; i < N; i++) {
        int higher;
        cin >> higher;
        
        for (int j = 0; j < N; j++) {
            if (higher == 0 && ret[j] == 0) {
                ret[j] = i + 1;
                break;
            } else if (ret[j] == 0) {
                higher--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ret[i] << ' ';
    }
    return 0;
}