for _ in range(int(input())):
    k, s = int(input()), input()

    v, stk = [], []

    for i in range(len(s)):
        if s[i] == '(':
            stk.append(i)
        else:
            v.append((i - stk.pop()) // 2)

    v.sort(reverse=True)

    for i in range(min(k, len(v))):
        v[i] = 0

    print(sum(v))
