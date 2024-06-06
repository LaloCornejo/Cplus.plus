#include <iostream>
#include <algorithm>
#include <vector>

  using namespace std;

  int main()
  {
    vector<int> a;
    vector<int> c;

    int atotal = 0;
    int csuma = 0;

    int num;
    while (cin >> num)
    {
      a.push_back(num);
    }

    while (cin >> num)
    {
      c.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < a.size(); i++)
    {
      atotal = atotal + a[i];
    }

    for (int i = 0; i < c.size(); i++)
    {
      csuma = csuma + c[i];
      if (csuma >= atotal)
      {
        cout << i;
        return 0;
      }
    }
  }