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

const ll MOD = 1e9 + 7, OO = 1e15;
const double PI = 4 * atan(1), EPS = 1e-7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    ll n;

    cin >> n;

    map<ll, ll> mp;

    for (ll i = 0; i < n; ++i) {
      ll x;

      cin >> x;

      ++mp[x];
    }

    ll mx = mp.rbegin()->fr, ans = 0;

    for (auto& [f, s] : mp) {
      ans += s * (s - 1) * (s - 2);

      vector<ll> to_check;

      if (f < (ll) 1e6) {
        for (ll i = 1; i * i <= f; ++i) {
          if (f % i == 0) {
            to_check.pb(i);

            if (i * i != f) {
              to_check.pb(f / i);
            }
          }
        }
      }
      else {
        for (ll i = 2; i <= mx / f; ++i) {
          if (f % i == 0) {
            to_check.pb(i);
          }
        }
      }

      for (ll e : to_check) {
        if (e * f > mx || e == 1) {
          nxt;
        }

        if (mp.count(f / e) && mp.count(f * e)) {
          ans += mp[f / e] * s * mp[f * e];
        }
      }
    }

    cout << ans << el;
  };

  return 0;
}
