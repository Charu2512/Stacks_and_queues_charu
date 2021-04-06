#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Next larger elements


class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> n_g_ele;
        n_g_ele.push_back(-1);
        stack<long long> s;
        s.push(arr[n-1]);
        for(int j=arr.size()-2;j>=0;j--)
        {
            while(s.empty()!=true && s.top()<=arr[j])
            {
                s.pop();
            }
            if(s.empty())
            {
                n_g_ele.push_back(-1);
            }
            else
            {
                n_g_ele.push_back(s.top());
            }
            s.push(arr[j]);
        }
        reverse(n_g_ele.begin(),n_g_ele.end());
        return n_g_ele;
        
        
      
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
