#ifndef __TREE_H__
#define __TREE_H__

#include <queue>
using namespace std;

typedef struct _tree_ {
	int val;
	struct _tree_ *left;
	struct _tree_ *right;
	
} Tree;


class TREE 
{
	private:
	Tree *root;
	public:
		TREE()
		{
			root = NULL;
		}

		Tree *newNode(int val) 
		{
			Tree *node = new Tree;
			node->val = val;
			node->left = NULL;
			node->right = NULL;
			return node;
		}

		Tree *returnRoot()
		{
			return root;
		}

		Tree *displayInorder(Tree *root)
		{
			if(!root) {
				return NULL;
			}
			displayInorder(root->left);
			cout << root->val << endl;
			displayInorder(root->right);
		}

		Tree *displayPreorder(Tree *root)
		{
			cout << root->val << endl;
			displayInorder(root->left);
			displayInorder(root->right);
		}

		

		void insertNodes(Tree *t,int key)
		{
			if (!t) {
				t = newNode(key); 
				root = t;
				return;
			}
			
			queue<Tree *> q;
    		q.push(t);
 
    		// Do level order traversal until we find
    		// an empty place. 
    		while (!q.empty()) {
	        	Tree* temp = q.front();
	        	q.pop();
	 
	        	if (!temp->left) {
	            	temp->left = newNode(key);
	            	break;
	        	} else
	            	q.push(temp->left);
	 
	        	if (!temp->right) {
	            	temp->right = newNode(key);
	            	break;
	        	} else
	            	q.push(temp->right);
    		}
    		return;
		}

		int maxValue(Tree *root) 
		{
			int max = root->val, tempL = -1, tempR = -1;
			
			if (root->left) {
				tempL = maxValue(root->left);
			}
			if (root->right) {
				tempR = maxValue(root->right);
			}
			if (!root->left && !root->right) {
				return max;
			}
			max = ((tempL > tempR) ? tempL : tempR);
			return max;
		}

		int minValue(Tree *root) 
		{
			
			int min = root->val, tempL = 0xFFFF, tempR = 0xFFFF;
			
			if (root->left) {
				tempL = minValue(root->left);
			}
			if (root->right) {
				tempR = minValue(root->right);
			}
			if (!root->left && !root->right) {
				return min;
			}
			min = ((tempL < tempR) ? tempL : tempR);
			return min;
		}

		bool ifBinarySearchTree (Tree *root)
		{
			if (!root) {
				return true;
			}
			if (root->left && maxValue(root->left) > root->val ) {
				return false;
			}
			if (root->right && minValue(root->right) < root->val ) {
				return false;
			}
			if ( !ifBinarySearchTree(root->left) || !ifBinarySearchTree(root->right)) {
				return false;
			}
			return true;
		}

};

#endif
