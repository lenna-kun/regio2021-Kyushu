#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

struct UnionFind {
  ll groups;
  vector<ll> parents;

  UnionFind(ll n) {
    groups = n;
    parents = vector<ll>(n, -1);
  }

  ll find(ll x) {
    if (parents.at(x) < 0) {
      return x;
    } else {
      parents[x] = find(parents[x]);
      return parents[x];
    }
  }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);

    // already united
    if (x == y)
      return;
    
    groups--;

    if (parents[x] > parents[y])
      swap(x, y);
    
    parents[x] += parents[y];
    parents[y] = x;
  }

  ll size(ll x) {
    return -parents[find(x)];
  }

  bool issame(ll x, ll y) {
    return find(x) == find(y);
  }

  vector<ll> roots() {
    vector<ll> ret;
    for (ll i = 0; i < parents.size(); i++)
      if (parents[i] < 0)
        ret.push_back(i);
    return ret;
  }

  ll group_count() {
    return groups;
  }
};