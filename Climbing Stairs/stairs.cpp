/**
 *You are climbing a stair case. It takes n steps to reach to the top.Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
 * 
 * Idea 1:
 1 : 1; 
 2 : 2; 
 3 : 3;
 4 : 5;
 
 To reach to the nth step, you have only two choices:

    Advance one step from the n-1th step.
    Advance two steps from the n-2th step.

Therefore, f(n) = f(n-1) + f(n-2), which is the exact same recurrence formula defined by the Fibonacci sequence (with different base cases, though).
	
 * Idea 2:
 For example, let's assume n = 6.

Let:

x = number of 1's,
y = number of 2's.

We could reach the top using one of the four combinations below:

+=======+
| x | y |
+===+===+
| 6 | 0 |    => 1) Six single steps.
| 4 | 1 |    => 2) Four single steps and one double step.
| 2 | 2 |    => 3) Two single steps and two double steps.
| 0 | 3 |    => 4) Three double steps.
+===+===+

For the first combination pair (x,y) = (6,0), there's obviously only one way of arranging six single steps.

For the second combination pair (4,1), there's five ways of arranging (think of it as slotting the double step between the single steps).

Similarly, there are six ways C(4,2) and one way C(3,3) of arranging the third and fourth combination pairs respectively.

Generally, for pair(x, y), there are a total of C(x+y,y) = (x+y)! / (x!*y!) ways of arranging the 1's and 2's.

The total number of possible ways is the sum of all individual terms,

f(6) = 1 + 5 + 6 + 1 = 13.

Generalizing for all n's (including odd n),

f(n) = C(n,0) + C(n-1,1) + C(n-2,2) + ... + C(ceiling(n/2), floor(n/2))
 

 *Author: Yuchao Zhou
 **/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

// solution 1 (DP)
/**
class Solution
{
public:
	int climbStairs(int n)
	{
		// vector should be init with n+1, but we ignore the 0 one.
		vector<int> d(n + 1, 0);
		d[1] = 1;
		d[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			d[i] = d[i-1] + d[i-2];
		}
		return d[n];
	}
};
**/

// solution 2
int nchoosek(int n, int k) {
  if(k==0 || n==k)
    return 1;
  if(2*k>n)
    k = n-k;

  double retf = 1;
  for(int i=0;i<k;++i) {
    retf *= n-i;
    retf /= i+1;
  }

  int ret = retf;
  return ret;
}

class Solution {
public:
  int climbStairs(int n) {
    int ret = 0;

    // i*2+j*1 = n
    for(int i=0;i*2<=n;++i) {
      int j = n-2*i;
      // for current pair of i,j
      // there are j+i places to hold j 1's and i 2's
      ret += nchoosek(i+j,i);
    }

    return ret;
    }
};

int main(int argc, char* argv[])
{
	int step;
	cout<<"Please input the step: "<<endl;
	cin>>step;
	Solution sol;
	int result = 0;
	result = sol.climbStairs(step);
	cout<<result<<endl;
}


