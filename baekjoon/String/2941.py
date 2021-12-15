# 백준 2941번 : 크로아티아 알파벳
if __name__ == "__main__":
    croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
    alphaStr = str(input())

    for ch in croatia:
        alphaStr = alphaStr.replace(ch, '*')
    
    print(len(alphaStr))
