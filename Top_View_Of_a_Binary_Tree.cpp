#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        vector<int> res = topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
    map<int,int> m;
    int hd=0;
    queue<pair<int,Node*>> q;
    q.push({hd,root});
    while(q.empty()==false)
    {   int t=q.size();
    for(int i=0;i<t;i++){
        auto temp=q.front();
        q.pop();
        hd=temp.first;
        if(m.count(hd)==0)
        {
            m[temp.first]=temp.second->data;
        }
        if(temp.second->left)
        q.push({hd-1,temp.second->left});
        
         if(temp.second->right)
        q.push({hd+1,temp.second->right});
    }
    }
    vector<int> res;
    for(auto it=m.begin();it!=m.end();it++)
    {
        res.push_back(it->second);
    }
    return res;
}


