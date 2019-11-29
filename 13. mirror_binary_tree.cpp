#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
int goright(Node* node, Node* mirror);
int goleft(Node* node, Node* mirror);
void mirror(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     mirror(root);
     inOrder(root);
     cout << endl;
  }
  return 0;

}


Node * treemirror(Node *P)
{
    Node *tmp=nullptr;
    if(!P || (!P->left && !P->right)) return P;
    else
    {
        tmp=P->right;
        P->right=treemirror(P->left);
        P->left=treemirror(tmp);
    }
    return P;
}

void mirror(Node* node)
{
    node=treemirror(node);
}

// void mirror(Node* node) 
// {
//     Node* mirror = new Node(node->data);
//     goleft(node->left, mirror);
//     goright(node->right, mirror);
//     node = mirror;
// }

// int goleft(Node* node, Node* mirror){
//     if(node==NULL)
//         return 0;
//     Node* temp = new Node(node->data);
//     mirror->right = temp;
//     return goleft(node->left, mirror);
// }

// int goright(Node* node, Node* mirror){
//     if(node==NULL)
//         return 0;
//     Node* temp = new Node(node->data);
//     mirror->left = temp;
//     return goright(node->right, mirror);
// }


