#include <iostream>
#include "tree.h"

int main()
{
	TREE bt;
	bt.insertNodes(bt.returnRoot(),10);
	
	
	bt.insertNodes(bt.returnRoot(),20);
	bt.insertNodes(bt.returnRoot(),30);
	bt.insertNodes(bt.returnRoot(),40);
	bt.insertNodes(bt.returnRoot(),50);
	// bt.insertNodes(bt.returnRoot(),2);
	// bt.insertNodes(bt.returnRoot(),1);
	// bt.insertNodes(bt.returnRoot(),3);
	bt.displayPreorder(bt.returnRoot());
	//bt.displayInorder(bt.returnRoot());
	//cout << (bt.ifBinarySearchTree(bt.returnRoot()) ? "true" : "false") << endl;
	cout << endl;
	cout << (!bt.ifBinarySearchTree(bt.returnRoot()) ? "false" : "true") << endl;
	// cout << bt.maxValue(bt.returnRoot()->left) << endl;
	// cout << bt.minValue(bt.returnRoot()->right) << endl;


	return 0;
}