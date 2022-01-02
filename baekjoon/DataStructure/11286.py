# 백준 11286번 : 절댓값 힙
import sys, heapq
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    heap = []

    for _ in range(N):
        num = int(input())

        if num == 0:
            if heap:
                print(heapq.heappop(heap)[1])
            else:
                print(0)
        else:
            if num < 0:
                heapq.heappush(heap, [-num, num])
            else:
                heapq.heappush(heap, [num, num])