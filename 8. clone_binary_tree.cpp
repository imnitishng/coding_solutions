// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// // Creation of tree
// struct Node{
//     int data;
//     Node* left;
//     Node* right;
//     Node* random;
//     Node(int x){
//         data = x;
//         left  = NULL;
//         right  = NULL;
//         random  = NULL;
//     }
// };

// int print_inorder(Node* node){
//     if(node == NULL)
//         return 0;
//     print_inorder(node->left);
//     cout<<node->data<<" ";
//     print_inorder(node->right);
//     return 0;
// }

// Node* create_tree(){
//     int t = 1, n = 1;
//     cout<<"Number of trees to create: "<<endl;
//     cin>>t;
    
//     while(t--){
//         cout<<"Number of Queries?: "<<endl;
//         cin>>n;

//         int p, c;
//         char o;
//         map<int, Node*> m1;
//         struct Node* child; 
//         struct Node* root = NULL;
        
//         while(n--){
//             cout<<"Enter Query (parent,child,order): "<<endl;
//             cin>>p>>c>>o;

//             struct Node* parent;
//             if(m1.find(p) == m1.end()){
//                 parent = new Node(p);
//                 m1[p] = parent;
//                 if(root == NULL)
//                     root = parent;
//             }
//             else
//                 parent = m1[p];
            
//             child = new Node(c);
//             if(o == 'L'){
//                 parent->left = child;
//                 m1[c] = child;
//             }
//             else if(o == 'R'){
//                 parent->right = child;
//                 m1[c] = child;
//             }
//             else
//                 parent->random = m1[c];
//         }
//     cout<<"Tree is: "<<endl;
//     print_inorder(root);
//     return root;
//     }
//     return 0;
// }


// // Cloning of tree
// Node* clone_node(Node* node, unordered_map<Node*, Node*> &map){
//     if(node == NULL)
//         return 0;
//     Node* cloned = new Node(node->data);
//     map[node] = cloned;
//     cloned->left = clone_node(node->left, map);
//     cloned->right = clone_node(node->right, map);
//     return cloned;
// }

// Node* clone_random(Node* node, Node* new_tree, unordered_map<Node*, Node*> &map){
//     if(node == NULL)
//         return
//     new_tree->random = map[node->random];
//     clone_random(node->left, new_tree->left, map);
//     clone_random(node->right, new_tree->right, map);
//     return 0;
// }

// Node* clone_tree(Node* node){
//     unordered_map<Node*, Node*> nn;
//     Node* new_tree = clone_node(node, nn);
//     clone_random(node, new_tree, nn);
//     return new_tree;
// }

// int main()
// {
//     Node* original_node;
//     Node* cloned_node;
//     original_node = create_tree();
//     cloned_node = clone_tree(original_node);

//     print_inorder(original_node);
//     cout<<"CLONED: "<<endl;
//     print_inorder(cloned_node);
// }



// A hashmap based C++ program to clone a binary 
// tree with random pointers 
#include<iostream> 
#include<unordered_map> 
using namespace std; 

/* A binary tree node has data, pointer to left child, 
	a pointer to right child and a pointer to 
	random node*/
struct Node 
{ 
	int key; 
	struct Node* left, *right, *random; 
}; 

/* Helper function that allocates a new Node with the 
given data and NULL left, right and random pointers. */
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->random = temp->right = temp->left = NULL; 
	return (temp); 
} 

/* Given a binary tree, print its Nodes in inorder*/
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* First recur on left sutree */
	printInorder(node->left); 

	/* then print data of Node and its random */
	cout << "[" << node->key << " "; 
	if (node->random == NULL) 
		cout << "NULL], "; 
	else
		cout << node->random->key << "], "; 

	/* now recur on right subtree */
	printInorder(node->right); 
} 

// This function creates clone by copying key and left and right pointers 
// This function also stores mapping from given tree node to clone. 
Node* copyLeftRightNode(Node* treeNode, unordered_map<Node *, Node *> &mymap) 
{ 
	if (treeNode == NULL) 
		return NULL; 
	Node* cloneNode = newNode(treeNode->key); 
	mymap[treeNode] = cloneNode; 
	cloneNode->left = copyLeftRightNode(treeNode->left, mymap); 
	cloneNode->right = copyLeftRightNode(treeNode->right, mymap); 
	return cloneNode; 
} 

// This function copies random node by using the hashmap built by 
// copyLeftRightNode() 
void copyRandom(Node* treeNode, Node* cloneNode, unordered_map<Node *, Node *> &mymap) 
{ 
	if (cloneNode == NULL) 
		return; 
	cloneNode->random = mymap[treeNode->random]; 
	copyRandom(treeNode->left, cloneNode->left, mymap); 
	copyRandom(treeNode->right, cloneNode->right, mymap); 
} 

// This function makes the clone of given tree. It mainly uses 
// copyLeftRightNode() and copyRandom() 
Node* cloneTree(Node* tree) 
{ 
	if (tree == NULL) 
		return NULL; 
	unordered_map<Node *, Node *> mymap; 
	Node* newTree = copyLeftRightNode(tree, mymap); 
	copyRandom(tree, newTree, mymap); 
	return newTree; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	//Test No 1 
	Node *tree = newNode(1); 
	tree->left = newNode(2); 
	tree->right = newNode(3); 
	tree->left->left = newNode(4); 
	tree->left->right = newNode(5); 
	tree->random = tree->left->right; 
	tree->left->left->random = tree; 
	tree->left->right->random = tree->right; 

	// Test No 2 
	// tree = NULL; 

	// Test No 3 
	// tree = newNode(1); 

	// Test No 4 
	/* tree = newNode(1); 
		tree->left = newNode(2); 
		tree->right = newNode(3); 
		tree->random = tree->right; 
		tree->left->random = tree; 
	*/

	cout << "Inorder traversal of original binary tree is: \n"; 
	printInorder(tree); 

	Node *clone = cloneTree(tree); 

	cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
	printInorder(clone); 

	return 0; 
} 
