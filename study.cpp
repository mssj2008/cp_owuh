#include <bits/stdc++.h>

using namespace std;

const string alph = "abcdefghijklmnopqrstuvwxy";
const string Alph = "ABCDEFGHIJKLMNOPQRSTUVWXY";

signed main() {
  string s;
  cin >> s;
  auto t1 = chrono::high_resolution_clock::now();
  // build simul equations
  vector<vector<int>> eqs;
  for (int i=0; i<5; i++) {
    for (int j=0; j<5; j++) {
      vector<int> eq(26);
      int id = i*5+j;
      eq[id] = 1;
      if (i>0) eq[id-5] = 1;
      if (j>0) eq[id-1] = 1;
      if (i<4) eq[id+5] = 1;
      if (j<4) eq[id+1] = 1;
      if (s.find(alph[id]) != string::npos) eq[25] = 1;
      if (s.find(Alph[id]) != string::npos) eq[25] = 2;
      eqs.push_back(eq);
    }
  }
  // now solve it by complete search
  vector<int> sol(25);
  int ptr = 0;
  function<bool()> solve = [&]() {
    bool good = true;
    for (int i=0; i<25; i++) {
      bool usable = true;
      for (int j=ptr; j<25; j++) {
        if (eqs[i][j] != 0) usable = false;
      }
      if (usable) {
        int sum = eqs[i][25];
        for (int j=0; j<ptr; j++) {
          sum += eqs[i][j] * sol[j];
        }
        if (sum % 3 != 0) good = false;
      }
    }
    if (!good) {
      return false;
    }
    if (ptr == 25) {
      return true;
    }
    for (int i=0; i<3; i++) {
      sol[ptr++] = i;
      if (solve()) return true;
      --ptr;
    }
    return false;
  };
  bool res = solve();
  if (res) {
    for (int i=0; i<25; i++) {
      if (sol[i] == 0) continue;
      if (sol[i] == 1) cout << alph[i];
      if (sol[i] == 2) cout << Alph[i];
    }
    cout << "\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
  auto t2 = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << "ms\n";
  return 0;
}