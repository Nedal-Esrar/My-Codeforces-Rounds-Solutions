for _ in range(int(input())):
    n, k = map(int, input().split())

    l = list(map(int, input().split()))

    r = list(map(int, input().split()))

    c, one, ans = 0, 0, 1 << 63

    for i in range(n):
        one += r[i] == l[i]

        c += r[i] - l[i] + 1

        if c < k:
            continue

        rem = c - k

        ans = min(ans, 2 * (i + 1) + r[i] - rem - min(rem, one))

    print(ans if ans != 1 << 63 else -1)
