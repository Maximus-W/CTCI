#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//Change to the question you want to run
#define ONE_POINT_TWO




#ifdef ONE_POINT_ONE

/*
1.1 IS UNIQUE: Implement an algorithm to determine if a string has all unique
               characters. What if you cannot use additional data structures?

Assumptions: String is in ASCII which contains 128 characters
*/

//Solution with a datastructure, O(n) runtime, O(1) space complexity
bool is_unique(string s) {
  //First check if string contains more than 128 characters
  if (s.length() > 128) return false;
  //Create a binary array that tracks all characters, initialized to false
  bool ascii_lst[128] = {0};
  //Iterate, iterate, iterate ...
  for (auto c : s) {
    int i = c;
    if (ascii_lst[i] == false) {
      ascii_lst[i] = true;
    } else {
      return false;
    }
  }
  return true;
}

//Solution without a data structure, assuming s can be modified otherwise check
//each char against all char after it in the string.
//O(nlogn) runtime, O(1) space complexity
bool is_unique_wds(string s) {
  //Sort the string
  sort(s.begin(), s.end());

  //Iterate through the array to check if there are same chars side by side
  for (int i = 1; i < s.length(); ++i) {
    if (s.at(i-1) == s.at(i)) {
      return false;
    }
  }
  return true;
}

#endif




#ifdef ONE_POINT_TWO
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

#endif



int main()
{
    #ifdef ONE_POINT_ONE
    string s = "aab";
    bool t = is_unique(s);
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    #endif

    #ifdef ONE_POINT_TWO
    string s1 = "aaab";
    string s2 = "baaa";
    bool t = check_permutation(s1, s2);
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    #endif
}
