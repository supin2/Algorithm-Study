# 백준 1927번 : 최소 힙
import sys, heapq
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    heap = []

    for _ in range(N):
        num = int(input())

        if num == 0:
            if heap:
                print(heapq.heappop(heap))
            else:
                print(0)
        else:
            heapq.heappush(heap, num)