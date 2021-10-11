// 백준 6588번 : 골드바흐의 추측
#include <iostream>
#include <vector>

using namespace std;

vector<bool> check(1000001, true);
vector<int> prime;

void eratos() {
    for (int i = 2; i * i <= 1000000; i++) {
        if (check[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                check[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1000000; i++) {
        if (check[i]) {
            prime.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    eratos();

    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < prime.size(); i++) {
            if (check[n - prime[i]]) {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
    return 0;
}