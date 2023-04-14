// EIEN

#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ll long long
#define fr first
#define sc second
#define pb(x) push_back(x)
#define nxt continue
#define sz(container) ((ll) container.size())
#define umap unordered_map
#define uset unordered_set
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define mkpr(f, s) make_pair(f, s)
#define el '\n'
#define mxpq priority_queue
#define tc int T; cin >> T; while (T--)
#define ld long double

template <class T>
using mnpq = mxpq<T, vector<T>, greater<T>>;

template <class T, class S>
using oset = tree<T, null_type, S, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9 + 7, OO = 1e12;
const double PI = 4 * atan(1), EPS = 1e-7;

ll dp[105][105][105], v[100], vis[105][105][105];

ll n, k, m;

ll id;

void mx(ll i, ll c, ll cnt) {
  if (i == n) {
    if (cnt % k == 0) {
      m = max(m, cnt);
    }
    return;
  }
  if (vis[i][c][cnt] == id) {
    return;
  }

  vis[i][c][cnt] = id;

  if (cnt % k == 0) {
    mx(i + 1, v[i], cnt + 1);
    mx(i + 1, 0, cnt);
  }
  else {
    mx(i + 1, c, cnt);

    if (v[i] == c)
      mx(i + 1, c, cnt + 1);
  }
}

ll solve(ll i, ll c, ll cnt) {
  if (i == n) {
    return cnt == m;
  }

  ll& ret = dp[i][c][cnt];

  if (vis[i][c][cnt] == id) {
    return ret;
  }

  vis[i][c][cnt] = id;

  ret = 0;

  if (cnt % k == 0) {
    ret = (ret + solve(i + 1, v[i], cnt + 1)) % MOD;
    ret=  (ret + solve(i + 1, 0, cnt)) % MOD;
  }
  else {
    ret = (ret + solve(i + 1, c, cnt)) % MOD;
    if (v[i] == c)
      ret = (ret + solve(i + 1, c, cnt + 1)) % MOD;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    ++id;
    cin >> n >> k;

    for (ll i = 0; i < n; ++i) {
      cin >> v[i];
    }

    m = 0;

    mx(0, 0, 0);

    ++id;

    cout << solve(0, 0, 0) << el;
  };

  return 0;
}
