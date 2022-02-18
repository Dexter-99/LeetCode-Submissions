void printCorner(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int  size=q.size();
        for(int i=0;i<size;i++)
        {
            Node *curr=q.front();
            q.pop();
            
            if(i==0||i==size-1)
            {
                
                cout<<curr->data<<" ";
            }
            if(curr->left)
            q.push(curr->left);
                if(curr->right)
            q.push(curr->right);
        }
    }
// Your code goes here

}