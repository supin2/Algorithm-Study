#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<int> &stones, int mid, int k) {
    int count = 0;
    for (int i = 0; i < stones.size(); i++) { // mid번째 사람이 건넌다고 가정할 때
        if (stones[i] - mid <= 0) { // 연속으로 0이하가 나오는 횟수 count
            count++; 
        } else { // 연속으로 0이하가 안나오면 다시 count를 위해 초기화
            count = 0;
        }
        if (count >= k) return true; 
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int first = 1, last = *max_element(stones.begin(), stones.end()); 
    
    while (first <= last) {
        int mid = (first + last)/2; // 처음 기준 (1 ~ 징검다리 최고값)의 중간값
        if (binary_search(stones, mid, k)) { // 0이 k개 이상 연속으로 나올 경우 
            last = mid - 1; // (first ~ mid - 1) 로 탐색 범위 변경
        } else { // 0이 k개 연속으로 나오지 않은 경우
            first = mid + 1; // (mid + 1 ~ last) 로 탐색 범위 변경
        }
    }
    return first;
}