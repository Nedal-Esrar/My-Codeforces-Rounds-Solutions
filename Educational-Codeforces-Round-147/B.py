for _ in range(int(input())):
    n = int(input())

    v = list(map(int, input().split()))

    w = list(map(int, input().split()))

    l, r = 2 * [-1]

    for i in range(n):
        if v[i] != w[i]:
            if l == -1:
                l = i

            r = i

    while l > 0 and v[l - 1] == w[l - 1] and w[l - 1] <= w[l]:
        l -= 1

    while r < n - 1 and v[r + 1] == w[r + 1] and w[r + 1] >= w[r]:
        r += 1

    print(l + 1, r + 1)
