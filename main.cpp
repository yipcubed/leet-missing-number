#include <cstring>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[";
  for (int i : v) {
    os << i << " ";
  }
  os << "]";
  return os;
}

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int largest = nums.size();
        bool largestFound = false;

        for (int i = 0; i < nums.size(); ++i) {
          // cout << "i: " << i << ", " << nums << endl;
          if (nums[i] == i)
            continue;
          while (nums[i] != i && nums[i] != largest) {
              swap(nums[i], nums[nums[i]]);
          }
        }
        // cout << "at end nums: " << nums << endl;
        for (int i = 0; i < nums.size(); ++i) {
          if (i != nums[i])
            return i;
        }
        return largest;
    }
};

void test1() {
  Solution S;
  vector<int> v1{3,0,1};
  cout << "2? " << S.missingNumber(v1) << endl;

  vector<int> v2{9,6,4,2,3,5,7,0,1};
  cout << "8? " << S.missingNumber(v2) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

