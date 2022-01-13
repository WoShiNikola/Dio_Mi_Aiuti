#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _tree* pointer;
typedef struct _tree {
	int val;
	pointer left;
	pointer right;
}Tree;

pointer createLeaf(int data) {
	pointer newLeaf = (pointer)malloc(sizeof(Tree));
	if (!newLeaf)
		return NULL;

	newLeaf->left = NULL;
	newLeaf->right = NULL;
	newLeaf->val = data;

	return newLeaf;
}

int addElement(pointer root, int data) {
	
	if (!root->left && data < root->val) {
		pointer newLeaf = createLeaf(data);
		newLeaf->left = root->left;
		root->left = newLeaf;
		return 0;
	}
	else if (root->left && data < root->val)
		addElement(root->left, data);
	if (!root->right && data > root->val) {
		pointer newLeaf = createLeaf(data);
		newLeaf->right = root->right;
		root->right = newLeaf;
		return 0;
	}
	else if (root->right && data > root->val)
		addElement(root->right, data);

	return 0;
}

int printTreePre(pointer root) {
	if (!root)
		return 0;
	printf("%d ", root->val);
	printTreePre(root->left);
	printTreePre(root->right);

	return 0;
}


int printTreeIn(pointer root) {
	if (!root)
		return 0;
	
	printTreeIn(root->left);
	printf("%d ", root->val);
	printTreeIn(root->right);

	return 0;
}

int printTreePost(pointer root) {
	if (!root)
		return 0;

	printTreePost(root->left);
	printTreePost(root->right);
	printf("%d ", root->val);
	

	return 0;
}

pointer findElement(pointer root, int target) {

	if (!root ||root->val == target)
		return root;
	else if (root->val < target)
		findElement(root->right, target);
	else
		findElement(root->left, target);

}

//pointer findElementToDelete(pointer root, int target) {
//
//	if (!root) {
//		return root;
//	}
//	if (root->left && root->left->val == target) {
//		return root->left;
//	}
//		
//	else if (root->right && root->right->val == target) {
//		return root->right;
//	}
//	else if (root->val < target)
//		findElement(root->right, target);
//	else
//		findElement(root->left, target);
//
//}

pointer minValueNode(pointer Leaf){
pointer curr = Leaf;

	/* loop down to find the leftmost leaf */
	while (curr && curr->left)
		curr = curr->left;

	return curr;
}

pointer deleteLeaf(pointer root, int target) {
	if (!root)
		return 0;

	if (root->val < target)
		root->right = deleteLeaf(root->right, target);
	else if (root->val > target)
		root->left = deleteLeaf(root->left, target);
	else {
		if (!root->left) {
			pointer temp = root->right;
			free(root);
			return temp;
		}
		else if (!root->right) {
			pointer temp = root->left;
			free(root);
			return temp;
		}


		pointer temp = minValueNode(root->right);

		root->val = temp->val;

		root->right = deleteLeaf(root->right, temp->val);
	}
	return root;
}

//pointer findElement(pointer root, int target) {
//	if (!root)
//		return root;
//	pointer temp = root;
//	
//	while (temp) {
//		if (temp->val == target)
//			return temp;
//		else if (temp->val < target)
//			temp = temp->left;
//		else
//			temp = temp->right;
//	}
//
//	return temp;
//}


int main() {

	pointer treeRoot = createLeaf(7);

	addElement(treeRoot, 2);
	addElement(treeRoot, 9);
	addElement(treeRoot, 5);
	addElement(treeRoot, 20);
	addElement(treeRoot, 8);



	printTreePost(treeRoot);

	

	return 0;
}