/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


Analysis:

1. The easiest way of this problem is search every 3 element pairs, after sorting the input array.
It has the complexity O(n^3).

The key point is as follows:

The problem requires output that are unique pairs. We can use a flag to test if the current element is the same as the one in previous iteration, if so, go to the next one and check again. But remember do not check the element in the first round of its own iteration.(which allows the possibility that 3 elements are equal.)
e.g. 0, 0, 0, 0,
In the first round:
1st  = [0];
2nd = 1st+1 = 0;
3rd = 2nd+1 = 0;
1st+2nd+3rd = 0, find one answer;
here 3rd goes to next element in the array, which is 0, equal to the previous one, so go to the next(which is the end of the vector), or there will be a duplicate answer.

2. The more efficient way.  O(n^2)

After sorting the input array, 3 three pointers are initialized.
The first pointer goes from index 1 to index end-2.
The 2nd pointers goes from the current element(1st pointer) index + 1
The 3rd pointers goes from the last element in a reverse order.

Two iterations:
1. 1st pointer from 1 to index end-2
2. while (2nd<3rd)

Conditions:
1. if (array[1st]+array[2nd]+array[3rd]==0), get one result
2. if (array[1st]+array[2nd]+array[3rd]>0), 3rd -1
3. if (array[1st]+array[2nd]+array[3rd]<0), 2nd +1


Code Misc:
1. vector constructor:
     int myint[] = {1,2,3,4,5};
     vector<int> vec(myint, myint + sizeof(myint)/sizeof(int));

2. vector.at()
    This is basically the same as the [] operator, but .at() check the bounds of valid element and through a  exception if it is not.

3. vector.end().   This is the post-last-element, is not the last element, conceptually is the element that follow      the last element.

4. iterator.  * is used to get the value of the iterator. e.g. if(*it1 + *it2 + *it3  == 0)

**/

// O(n^3) method:
// class Solution 
// {
// public:
//   vector<vector<int> > threeSum(vector<int> &num) 
//   {
//     vector<int> res_m(3);
//     vector<vector<int> > res;
//     vector<int>::iterator it1, it2, it3, iend;

//     sort(num.begin(), num.end());
//     if (num.size() >= 3)
//     {
//       iend = num.end();
//       it1 = num.begin();
//       bool f1 = false;
//       // for ( ; it1 != iend; it1++) is same
//       for( ; it1 != iend; it1++)
//       {
//         // test if the current element is the same as the one in previous iteration
//         // but need not to check the element in the first round
//         // so use f1, f2, f3 flags and iteration compare
//         if (f1 && (*it1 == *(it1 - 1))) {continue;}
//         f1 = true;
//         bool f2 = false;
//         for (it2 = it1 + 1; it2 != iend; it2++)
//         {
//           if (f2 && (*it2 == *(it2 - 1))) {continue;}
//           f2 = true;
//           bool f3 = false;
//           for (it3 = it2 + 1; it3 != iend; it3++)
//           {
//             if (f3 && (*it3 == *(it3 - 1))) {continue;}
//             f3 = true;
//             if (*it1 + *it2 + *it3 == 0)
//             {
//               res_m.at(0) = *it1;
//               res_m.at(1) = *it2;
//               res_m.at(2) = *it3;
//               res.push_back(res_m);
//               break;
//             }
//           }
//         }
//       }
//     }
//     return res;
//   }
// };

// O(n^2) method:
class Solution 
{
public:
  vector<vector<int> > threeSum(vector<int> &num) 
  {
    vector<int> res_m(3);
    vector<vector<int> > res;
    vector<int>::iterator it1, it2, it3, iend;

    sort(num.begin(), num.end());
    if (num.size() >= 3)
    {
      iend = num.end();
      it1 = num.begin();
      bool f1 = false;
      for ( ; it1 != iend - 2; it1++)
      {
        if (f1 && *it1 == *(it1 - 1)) {continue;}
        f1 = true;
        bool f2 = false;
        bool f3 = false;
        it3 = iend - 1;
        it2 = it1 + 1;
        while (it2 != it3)
        {
          
          if (f3 && *it3 == *(it3 + 1)) { it3 = it3 - 1; continue;}
          if (f2 && *it2 == *(it2 - 1)) { it2 = it2 + 1; continue;}
          
          // 3 sum
          if (*it1 + *it2 + *it3 == 0)
          {
            res_m.at(0) = *it1;
            res_m.at(1) = *it2;
            res_m.at(2) = *it3;
            res.push_back(res_m);
          }
          if (*it1 + *it2 + *it3 > 0)
          {
            it3--;
            f3 = true;
          }
          // use if (*it1 + *it2 + *it3 < 0) is wrong. said limit space 
          else
          {
            it2++;
            f2 = true;
          }
        }
      }
    }
    return res;
  }
};