// 백준 15904번 : UCPC는 무엇의 약자일까?
#include <iostream>

using namespace std;

int arr[26];

int main()
{
    string text = "", UPCP = "UCPC";
    getline(cin, text);
    
    int cnt = 0;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isalpha(ch) && isupper(ch)) {
            if (cnt == 4) {
                break;
            } else if (UPCP[cnt] == ch) {
                cnt++;
            }
        }
    }
    
    if (cnt == 4) {
        cout << "I love UCPC";
    } else {
        cout << "I hate UCPC";
    }

    return 0;
}
