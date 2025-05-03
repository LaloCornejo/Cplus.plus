#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define rforn(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define READGRID(arr, l, r, t, b)  \
  for (int i = (l); i <= (r); i++) \
    for (int j = (t); j <= (b); j++)
#define READGRID2(arr, l, r, t, b) \
  for (int i = (l); i <= (r); i++) \
    for (int j = (t); j >= (b); j--)
#define fast_cin()         \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define min(a, b) a = a < b ? a : b
#define max(a, b) a = a > b ? a : b
#define ln "\n"
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define pi 3.1415926535897932384626433832795
#define sq(x) ((x) * (x))
#define pb push_back
#define mp make_pair

void solve();

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
#endif

  fast_cin();

// ll t;
//  cin >> t;
//  while (t--)
  //  {
    cout << "A";
    solve();
    cout << "\n";
  //  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  float Va, Vb, Vc;
  Va = (float)a / 2;
  Vb = (float)b / 2;
  Vc = (float)c / 2;
  string s;

  int max = a > b ? a : b;
  max = max > c ? max : c;
  
  while(max > 0 )  {
    if (Va > .5 ) {
      s += "aa";
      Va -= 1;
    }else if (Vb > .5 ) {
      s += "bb";
      Vb -= 1;
    }else if (Vc > .5 ) {
      s += "cc";
      Vc -= 1;
    } else if (Va > 0 ) {
      s += "a";
      Va -= .5;
    } else if (Vb > 0 ) {
      s += "b";
      Vb -= .5;
    } else if (Vc > 0 ) {
      s += "c";
      Vc -= .5;
    }
  }

cout << s;
}
