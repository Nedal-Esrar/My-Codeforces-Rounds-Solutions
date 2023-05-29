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
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    int n;

    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i) {
      cin >> v[i].fr;
    }

    for (int i = 0; i < n; ++i) {
      cin >> v[i].sc;
    }

    sort(v.begin(), v.end());

    ll ans= 0 ;

    for (int i = 1; i * i <= 2 * n; ++i) {
      vector<int> mp(n + 1);

      for (auto& [f, s] : v) {
        int val = i * f - s;

        if (val > 0 && val <= n) {
          ans += mp[val];
        }

        if (i == f) {
          ++mp[s];
        }
      }
    }

    cout << ans << el;
  }

  return 0;
}
