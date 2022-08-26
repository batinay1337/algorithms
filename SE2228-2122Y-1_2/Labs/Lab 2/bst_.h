#include <iostream>
using namespace std;

struct node
{
int data;
node *left;
node *right;
};

class BST
{

public:
	BST();
	void insert(int data);
	node *search(int data);
	node *min();
	node *max();
	void printInorder(node *node);
	node *root;
private:
	node *createNode(int data);
};

BST::BST()
{
	root = NULL;
}

node *BST::createNode(int data)
{
	node *n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::insert(int data)
{
	if(root == NULL)
	{
		root = createNode(data);
		return;
	}
	
	node *pre = NULL;
	node *cur = root;
	while(cur != NULL)
	{
		pre = cur;
		if(data > cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}
	
	if(data > pre->data)
		pre->right = createNode(data);
	else
		pre->left = createNode(data);
}

node *BST::search(int data)
{

	node *cur = root;
	
	while(cur !=NULL && cur->data != data)
	{
		if(data > cur->data)
			cur = cur->right;
		else
			cur = cur->left;
	}

	return cur;
}

node *BST::min()
{

	node *cur = root;
	
	if (cur == NULL)
		return NULL;

	while(cur->left != NULL)
	{
			cur = cur->left;
	}

	return cur;
}

node *BST::max()
{

	node *cur = root;
	
	if (cur == NULL)
		return NULL;

	while(cur->right !=NULL)
	{
			cur = cur->right;
	}

	return cur;
}


void BST::printInorder(node *node) 
{
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout<< node->data << " "; 
    printInorder(node->right); 
} 
