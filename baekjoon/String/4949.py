# 백준 4949번 : 균형잡힌 세상
if __name__ == "__main__":
    while True:
        sen = input()
        if sen == '.':
            break
        
        st = []

        for ch in sen:
            if ch == '(' or ch == '[':
                st.append(ch)
            elif ch == ')':
                if len(st) != 0 and st[-1] == '(':
                    st.pop()
                else:
                    st.append(ch)
                    break
            elif ch == ']':
                if len(st) != 0 and st[-1] == '[':
                    st.pop()
                else:
                    st.append(ch)
                    break
        
        if len(st) == 0:
            print('yes')
        else:
            print('no')