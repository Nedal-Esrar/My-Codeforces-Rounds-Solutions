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

bool check(multiset<pair<ll, ll>>& s1, multiset<pair<ll, ll>>& s2, ll h, ll w) {
  bool nobrk = 1;

  while (nobrk) {
    nobrk = 0;

    while (!s1.empty() && s1.rbegin()->fr == h) {
      pair<ll, ll> x = *s1.rbegin();
      s1.erase(s1.find(x));

      w -= x.sc;

      swap(x.fr, x.sc);
      s2.erase(s2.find(x));

      nobrk = 1;
    }

    while (!s2.empty() && s2.rbegin()->fr == w) {
      pair<ll, ll> x = *s2.rbegin();
      s2.erase(s2.find(x));

      h -= x.sc;

      swap(x.fr, x.sc);
      s1.erase(s1.find(x));

      nobrk = 1;
    }
  }

  return sz(s1) == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  tc {
    ll n, area = 0;

    cin >> n;

    multiset<pair<ll, ll>> st1, st2;

    for (ll i = 0; i < n; ++i) {
      pair<ll, ll> p;
      cin >> p.fr >> p.sc;

      st1.insert(p);

      swap(p.fr, p.sc);

      st2.insert(p);

      area += p.fr * p.sc;
    }

    vector<pair<ll, ll>> ans;

    ll h = st1.rbegin()->fr;

    if (area % h == 0 && check(st1, st2, h, area / h)) {
      ans.emplace_back(h, area / h);
    }

    ll w = st2.rbegin()->fr;

    if (h * w != area) {
      if (area % w == 0 && check(st1, st2, area / w, w)) {
        ans.emplace_back(area / w, w);
      }
    }

    cout << sz(ans) << el;

    for (auto [f, s] : ans) {
      cout << f << ' ' << s << el;
    }
  };

  return 0;
}
