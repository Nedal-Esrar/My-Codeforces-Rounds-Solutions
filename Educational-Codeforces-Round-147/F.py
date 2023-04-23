MOD, N = 998244353, int(3e5) + 5

fct, invfct, p2 = [N * [1] for _ in range(3)]

for i in range(1, N):
    fct[i] = fct[i - 1] * i % MOD

    p2[i] = p2[i - 1] * 2 % MOD

invfct[-1] = pow(fct[-1], MOD - 2, MOD)

for i in range(N - 2, 0, -1):
    invfct[i] = invfct[i + 1] * (i + 1) % MOD


def nCr(n, r):
    return fct[n] * invfct[n - r] % MOD * invfct[r] % MOD


n, m, k = map(int, input().split())

i, ans = 2 * [0]

while i <= m <= n - k * (i + m):
    cur = 1 if i % 2 == 0 else MOD - 1

    cur = cur * nCr(n - k * (i + m), m) % MOD * nCr(m, i) % MOD * p2[m - i] % MOD

    ans = (ans + cur) % MOD

    i += 1

print(ans)
