# 백준 4949번 : 균형잡힌 세상
if __name__ == "__main__":
    while True:
        text = input()

        if text == '.':
            break

        st = []
        flag = True
        for ch in text:
            if ch == '(' or ch == '[':
                st.append(ch)
            elif ch == ')':
                if st and st[-1] == '(':
                    st.pop()
                else:
                    flag = False
                    break
            elif ch == ']':
                if st and st[-1] == '[':
                    st.pop()
                else:
                    flag = False
                    break

        if flag and not st:
            print("yes")
        else:
            print("no")