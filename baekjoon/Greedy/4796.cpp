// 백준 4796번 : 캠핑
#include <iostream>

using namespace std;

int main() {
    int L, P, V, i = 1;

    while (true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;
        int day = (V / P) * L;

        if (V % P > L) {
            day += L;
        } else {
            day += V % P;
        }
        cout << "Case " << i++ << ": " << day << '\n';
    }
    return 0;
}