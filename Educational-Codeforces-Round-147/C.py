for _ in range(int(input())):
    s = input()

    mn = int(1e9)

    for i in range(26):
        mx = max([len(x) for x in s.split(chr(i + 97))])

        c = 0

        while mx > 0:
            c += 1
            mx >>= 1

        mn = min(mn, c)

    print(mn)
