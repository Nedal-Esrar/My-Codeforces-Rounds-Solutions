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
    pair<ll, ll> p1, p2;

    cin >> n;

    cin >> p1.fr >> p1.sc;

    cin >> p2.fr >> p2.sc;

    if (p1.fr > n >> 1)
      p1.fr -= n >> 1;
    else
      p1.fr = (n >> 1) - p1.fr + 1;

    if (p1.sc > n >> 1)
      p1.sc -= n >> 1;
    else
      p1.sc = (n >> 1) - p1.sc + 1;

    if (p2.fr > n >> 1) 
      p2.fr -= n >> 1;
    else 
      p2.fr = (n >> 1) - p2.fr + 1;

    if (p2.sc > n >> 1)
      p2.sc -= n >> 1;
    else
      p2.sc = (n >> 1) - p2.sc + 1;

    cout << abs(max(p1.fr, p1.sc) - max(p2.fr, p2.sc)) << el;
  };

  return 0;
}
