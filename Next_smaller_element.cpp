// A Stack based C++ program to find next
// smaller element for all array elements.
#include <bits/stdc++.h>

using namespace std;

/* prints element and NSE pair for all
elements of arr[] of size n */
vector<int> printNSE(int arr[], int n)
{
	vector<int> res;
  res.push_back(-1);
  stack<int> s;
  s.push(arr[n-1]);
  for(int j=n-2;j>=0;j--)
  {
    while(s.empty()!=true && s.top()>=arr[j])
    {
      s.pop();
    }
    if(s.empty()==true)
    {
      res.push_back(-1);
    }
    else
    {
            res.push_back(s.top());

    }
    s.push(arr[j]);
   }
  reverse(res.begin(),res.end());
  return res;
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 10,1,2,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> res=printNSE(arr, n);
  for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
	return 0;
}
