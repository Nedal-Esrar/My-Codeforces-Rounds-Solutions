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

ll calc_mex(vector<ll>& v) {
  set<ll> st;

  for (ll e:  v) {
    st.insert(e);
  }

  vector<ll> gg(st.begin(), st.end());

  if (gg[0] != 0) {
    return 0;
  }

  for (ll i = 1; i < sz(gg); ++i) {
    if (gg[i] != gg[i - 1] + 1) {
      return gg[i - 1] + 1;
    }
  }

  return sz(gg);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    ll n;

    cin >> n;

    vector<ll> v(n);

    for (ll& e : v) {
      cin >> e;
    }

    ll mex = calc_mex(v);

    if (mex == n) {
      cout << "NO\n";
      nxt;
    }

    if (find(v.begin(), v.end(), mex + 1) == v.end()) {
      cout << "YES\n";
      nxt;
    }

    ll st = -1, en = -1;

    for (ll i = 0; i < n; ++i) {
      if (v[i] == mex + 1) {
        if (st == -1) {
          st = i;
        }

        en = i;
      }
    }

    for (ll i = st; i <= en; ++i) {
      v[i] = mex;
    }

    if (calc_mex(v) == mex + 1) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  };

  return 0;
}
