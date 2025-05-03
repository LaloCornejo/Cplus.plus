/*#include <bits/stdc++.h>*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <numeric>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <iterator>
#include <array>
#include <tuple>
#include <random>
#include <new>
#include <chrono>
#include <future>
#include <atomic>

/*#pragma GCC optimize("Ofast")*/
/*#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")*/
/*#pragma GCC optimize("unroll-loops")*/

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

  ll t;
  cin >> t;
  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}

void solve() {
  /*1400. Construct K Palindrome Strings*/
  /***🗓️ Date**: 2025-01-11 **🧠 Difficulty**: Medium | **👍 Likes**: 1689 | **👎 Dislikes**: 152*/
  /*Given a string `s` and an integer `k`, return `true` _if you can use all the characters in_ `s` _to construct_ `k` _palindrome strings or_ `false` _otherwise_.*/
  /***Example 1:***/
  /*```*/
  /*Input: s = "annabelle", k = 2*/
  /*Output: true*/
  /*Explanation: You can construct two palindromes using all characters in s.*/
  /*Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"*/
  /*```*/
  /***Example 2:***/
  /*```*/
  /*Input: s = "leetcode", k = 3*/
  /*Output: false*/
  /*Explanation: It is impossible to construct 3 palindromes using all the characters of s.*/
  /*```*/
  /***Example 3:***/
  /*```*/
  /*Input: s = "true", k = 4*/
  /*Output: true*/
  /*Explanation: The only possible solution is to put each character in a separate string.*/
  /*```*/
  /***Constraints:***/
  /** `1 <= s.length <= 105`*/
  /** `s` consists of lowercase English letters.*/
  /** `1 <= k <= 105`*/
  int k;
  string s;
  cin >> s >> k;
  int n = s.size();
  if (n < k)
  {
    cout << "false";
    return;
  }
  if (n == k)
  {
    cout << "true";
    return;
  }

  int freq[26] = {0};

  for (int i = 0; i < n; i++)
  {
    freq[s[i] - 'a']++;
  }

  int odd = 0;
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] % 2)
    {
      odd++;
    }
  }

  if (odd > k)
  {
    cout << "false";
    return;
  }

  cout << "true";
  return;
}
