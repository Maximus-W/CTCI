#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


/*
1.2 CHECK PERMUTATION: Given two strings, write a method to decide if one is a
                       permutation of the other.
*/

//Solution with a datastructure, O(n) runtime, O(1) space complexity
bool check_permutation(string s1, string s2) {
  //First check if strings are the same length
  if (s1.length() != s2.length()) return false;
  //Data structure for keeping track of chars
  int ascii_lst[128] = {0};
  //Iterate, iterate, iterate ...
  for (auto c : s1) {
    int i = c;
    ascii_lst[i]++;
  }
  for (auto c : s2) {
    int i = c;
    ascii_lst[i]--;
  }

  //array must all be zeros if the string are permutations
  for (int i = 0; i < 128; ++i) {
    if (ascii_lst[i] != 0) return false;
  }
  return true;
}

//Solution without a datastructure, O(nlogn) runtime, O(1) space complexity
bool check_permutation_wds(string s1, string s2) {
  //First check if strings are the same length
  if (s1.length() != s2.length()) return false;
  //Sort both strings
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  //Check both strings
  for (int i = 0; i < s1.length(); ++i) {
    if (s1.at(i) != s2.at(i)) return false;
  }
  return true;
}


int main()
{
    string s1 = "aaab";
    string s2 = "baaa";
    bool t = check_permutation(s1, s2);
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
