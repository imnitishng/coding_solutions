#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* random;
    Node(int x){
        data = x;
        left  = NULL;
        right  = NULL;
        random  = NULL;
    }
};

int print_inorder(Node* node){
    if(node == NULL)
        return 0;
    print_inorder(node->left);
    cout<<node->data<<" ";
    print_inorder(node->right);
    return 0;
}

int main()
{
    int t = 1, n = 1;
    cout<<"Number of trees to create: "<<endl;
    cin>>t;
    
    while(t--){
        cout<<"Number of Queries?: "<<endl;
        cin>>n;

        int p, c;
        char o;
        map<int, Node*> m1;
        struct Node* child; 
        struct Node* root = NULL;
        
        while(n--){
            cout<<"Enter Query (parent,child,order): "<<endl;
            cin>>p>>c>>o;

            struct Node* parent;
            if(m1.find(p) == m1.end()){
                parent = new Node(p);
                m1[p] = parent;
                if(root == NULL)
                    root = parent;
            }
            else
                parent = m1[p];
            
            child = new Node(c);
            if(o == 'L'){
                parent->left = child;
                m1[c] = child;
            }
            else if(o == 'R'){
                parent->right = child;
                m1[c] = child;
            }
            else
                parent->random = m1[c];
        }
    cout<<"Tree is: "<<endl;
    print_inorder(root);
    delete root;
    }
}