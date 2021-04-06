#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int price[], int n)
{
   vector<int> res;
   res.push_back(1);
   stack<int> s;
   s.push(0);
   for(int i=1;i<n;i++)
   {
       while(s.empty()==false && price[s.top()]<=price[i])
       {
           s.pop();
       }
      
       if(s.empty()==true)
       {
          res.push_back(i+1);
       }
       else
       {
           res.push_back(i-s.top());
       }
      
       s.push(i);
       
       
   }
   return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
