#include <bits/stdc++.h>
using namespace std;

struct manacher
{
      vector<int> p;

      // p[i] = defines how many length of palindrome we have at index i.
      // Actual length of palindrome at p[i] is p[i] - 1, as We initially assigned 1 value to every p[i], So '#' characters also got length 1, which is why we have to subtract 1.
      void run_manacher(string s)
      {
            // modified string "s"
            cout << s << endl;
            int l = 1, r = 1;
            int n = s.length();

            p.assign(n, 1);
            for (int i = 1; i < n; i++)
            {
              if(l+r-i>=0) p[i] = max(0, min(r - i, p[l + r - i]));

                  // expanding outside
                  while (i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]])
                        p[i]++;

                  // new bounding box or new longer palindrome
                  if (i + p[i] > r)
                  {
                        l = i - p[i];
                        r = i + p[i];
                  }
            }

            for (auto v : p)
            {
                  cout << v << " ";
            }
            cout << endl;
      }

      // Building the manacher
      void build(string s)
      {
            string t;
            for (auto v : s)
            {
                  t += string("#") + v;
            }
            t += string("#");

            run_manacher(t);
      }

      /*
      eg: s = abbabba
          t = #a#b#b#a#b#b#a#
          if odd centred palindrome in s is 3
          then pos in t is 2*3+1 = 7

          if even centred palindrome in s is 1 and 2
          then pos in t is 2*1+1+1 = 4
      */
      int getLongest(int cen, bool odd)
      {
            int pos = 2 * cen + 1 + !(odd);
            return p[pos] - 1;
      }

      // (r - l + 1) is the size of the current window, if current window size comes under its center's biggest palindrome, then it means it's also palindrome, as part of palindrome is also palindrome.
      bool checkPalin(int l, int r)
      {
            if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2))
                  return 1;
            else
                  return 0;
      }
} m;

int main()
{
      string s = "babbabbabc";
      m.build(s);
      return 0;
}

/*
Output:

#b#a#b#b#a#b#b#a#b#c#
1 2 1 4 1 2 7 2 1 10 1 2 7 2 1 4 1 2 1 2 1


*/

