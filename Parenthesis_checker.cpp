#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
            {
                s.push(x[i]);
            }
            else if( x[i]==']' || x[i]=='}' || x[i]==')')
            {
                if(s.empty())
                {
                    return false;
                }
                else 
                {
                    char c=s.top();
                    s.pop();
                    if(c=='[' && x[i]==']')
                    continue;
                    else if(c=='(' && x[i]==')')
                    continue;
                    else if(c=='{' && x[i]=='}')
                    continue;
                    else 
                    return false;
                }
            }
            
        }
        return s.empty()==true;
    }
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
