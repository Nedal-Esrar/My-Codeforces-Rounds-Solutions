for _ in range(int(input())):
    s = input()

    if s[0] == '0':
        print(0)
    else:
        ans = 1

        for c in s:
            if c == '?':
                ans *= 10

        if s[0] == '?':
            ans = ans * 9 // 10

        print(ans)
