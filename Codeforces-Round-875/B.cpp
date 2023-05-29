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
    ll n;

    cin >> n;

    vector<ll> a(n), b(n);

    map<ll, ll> mp1, mp2;

    for (ll& e: a) {
      cin >> e;
    }

    for (ll& e : b) {
      cin >> e;
    }

    ll m = 0, c= 1;

    for (ll i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) {++c;}
      else {
        mp1[a[i - 1]] = max(mp1[a[i - 1]], c);
        c = 1;
      }
    }

    mp1[a[n - 1]] = max(mp1[a[n - 1]], c);

    c = 1;

    for (ll i=  1; i < n; ++i) {
      if (b[i] == b[i - 1]) {++c;}
      else {
        mp2[b[i - 1]] = max(mp2[b[i - 1]], c);
        c = 1;
      }
    }

    mp2[b[n - 1]] = max(mp2[b[n - 1]], c);

    ll mx= 0 ;

    for (auto& [f, s] : mp1) {
      mx =max(mx, s + mp2[f]);
    }

    for (auto& [f, s] : mp2) {
      mx = max(mx, s+ mp1[f]);
    }

    cout << mx << el;
  }

  return 0;
}
