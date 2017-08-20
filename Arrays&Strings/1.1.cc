#include <string>
#include <iostream>

using namespace std;

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


int main()
{
    string s = "aab";
    bool t = is_unique(s);
    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
