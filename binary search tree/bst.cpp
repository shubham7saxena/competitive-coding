#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
	Node(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node* insert(struct Node* root, int key){
	if(root==NULL){
		struct Node* temp = new Node(key);
		return temp;
	}
	if(key < root->val) root->left = insert(root->left, key);
	else if(key > root->val) root->right = insert(root->right, key);

	return root;
}

void levelOrder(struct Node* root){
	queue<struct Node*> q;
	struct Node* temp = root;
	while(temp!=NULL){
		cout<<temp->val<<"\t";
		q.push(temp->left);
		q.push(temp->right);
		temp = q.front();
		q.pop();
	}
}

// depth first search
void inOrder(struct Node* root){
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->val<<"\t";
	inOrder(root->right);
}

void preOrder(struct Node* root){
	if(root==NULL) return;
	cout<<root->val<<"\t";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->val<<"\t";
}

int minValue(struct Node* root){
	struct Node *temp = root;
	while(temp->left!=NULL) temp = temp->left;
	return temp->val;
}

int maxValue(struct Node* root){
	struct Node *temp = root;
	while(temp->right!=NULL) temp = temp->right;
	return temp->val;
}

bool isBST(Node* root){
	if(root == NULL) return 1;
	return (root->right->val > root->val && root->left->val < root->val && isBST(root->left) && isBST(root->right));
}

int inorderSuccessor(Node* root){
	if(root->right == NULL){
		return root->val;
	}
	else{
		Node *temp = root;
		temp = temp->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		return temp->val;	
	}
}

int inorderPredecessor(Node* root){
	if(root->left == NULL){
		return root->val;
	}
	else{
		Node *temp = root;
		temp = temp->right;
		while(temp->right!=NULL){
			temp = temp->right;
		}
		return temp->val;	
	}
}

void deleteNode(Node* root, int key){
	if(key < root->val) deleteNode(root->left, key);
	else if(key > root->val) deleteNode(root->right, key);
	else{
		if(root->right == NULL && root->left == NULL){
			delete root;
		}
		else if (root->right != NULL && root->left == NULL){
			swap(root->val, root->right->val);
			delete root->right;
		}
		else if (root->right == NULL && root->left != NULL){
			swap(root->val, root->left->val);
			delete root->left;
		}
		else{
			int temp = inorderSuccessor(root);
			swap(root->val, temp);
			deleteNode(root, temp);
		}
	}
}
int main(){

}