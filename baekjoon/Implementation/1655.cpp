#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    scanf("%d", &N);
    
    while (N--) {
        int num;
        scanf("%d", &num);
        
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(num);
            } else if (maxHeap.size() == minHeap.size()) {
                maxHeap.push(num);
            }
            if (maxHeap.top() > minHeap.top()) {
                int a = maxHeap.top();
                int b = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(b);
                minHeap.push(a);
            }
        } 
        
        printf("%d\n", maxHeap.top());
    }
    return 0;
}
