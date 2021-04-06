//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>=2)
        {
            int t1=s.top();
            s.pop();
            int t2=s.top();
            s.pop();
            if(M[t1][t2]==1)
            {
                s.push(t2);
            }
            else
            {
                s.push(t1);
            }
            
        }
        int pot_celeb=s.top();
        int i;
        for(i=0;i<n;i++)
        {
            if(i!=pot_celeb)
            {
                if(M[i][pot_celeb]==0 || M[pot_celeb][i]==1)
                return -1;
            }
        }
        return pot_celeb;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
