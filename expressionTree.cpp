int evalTree(node* root)
{
    //Your code here
    if(!root)
        return 0;
    if(!root->left && !root->right){
        return stoi(root->data);
    }
    int l = evalTree(root->left);
    int r = evalTree(root->right);
    
    if(root->data == "+")
        return l+r;
    else if(root->data == "-")
        return l-r;
    else if(root->data == "*")
        return l*r;
    else
        return l/r;
}
