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
    ll n, m;

    cin >> n >> m;

    set<ld> st;

    for (ll i = 0; i < n; ++i) {
      ll x;


      cin >> x;

      st.insert(x);
    }

    vector<ld> v(st.begin(), st.end());

    for (ll i = 0; i < m; ++i) {
      ll a, b, c;

      cin >> a >> b >> c;

      ll gg= 4 * a * c;

      if (gg < 0) {
        cout << "NO\n";
        nxt;
      }

      long double sq = sqrtl(gg);

      auto it = upper_bound(v.begin(), v.end(), b - sq) - v.begin();
      auto it1 = lower_bound(v.begin(), v.end(), b + sq) - v.begin();

      if (it1 - 1 < it) {
        cout << "NO\n";
      }
      else {
        cout << "YES\n" << (ll) v[it] << el;
      }
    };
  };

  return 0;
}
