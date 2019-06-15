#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    map<Node*, int> m;
    map<int, Node*> n;
    void getLevel(Node *root, int l){
        if(!root)
            return;
        getLevel(root->left, l - 1);
        m[root] = l;
        getLevel(root->right, l + 1);
    }
    void topView(Node *root) {
        // getLevel(root, 0);
        // queue<Node*> q;
        // q.push(root);
        // Node *t;
        // while(!q.empty()){
        //     t = q.front();
        //     q.pop();
        //     n[m[t]] = t;
        //     if(t->left)
        //         q.push(t->left);
        //     if(t->right)
        //         q.push(t->right);
        // }
        // for(auto i=n.begin(); i !=n.end(); i++)
        //     cout<<i->second->data<<" ";

        getLevel(root, 0);
        queue<Node *> q;
        q.push(root);
        Node *t;
        while (!q.empty()) {
          t = q.front();
          q.pop();
          if(n[m[t]] == 0)
            n[m[t]] = t;
          if (t->left)
            q.push(t->left);
          if (t->right)
            q.push(t->right);
        }
        for (auto i = n.begin(); i != n.end(); i++)
          cout << i->second->data << " ";
    }

}; //End of Solution
