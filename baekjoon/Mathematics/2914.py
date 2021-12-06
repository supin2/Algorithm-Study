# 백준 2914번 : 저작권
def calc(A, I) :
    B = A * (I - 1) + 1
    print(B)

if __name__ == "__main__" :
    A, I = map(int, input().split())
    calc(A, I)