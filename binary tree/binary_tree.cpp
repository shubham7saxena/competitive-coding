#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int level;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value){
	struct Node* node = new Node;
	node->val = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// breadth first search
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

int height(struct Node* node)
{
    // leaf node
    if(node == NULL)
       return 0;
   return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(struct Node* root){
	if(root == NULL)
		return true;
	int lh,rh;
	lh = height(root->left);
	rh = height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
		return true;
	}

	return false;
}

bool isSymmetric(struct Node* A, struct Node* B){
	if(A==NULL && B==NULL) return 1;
	else if(A!=NULL && B!=NULL){
		return(A->val == B->val && isSymmetric(A->left,B->right) && isSymmetric(A->right, B->left));
	}
	return 0;
}

bool search(Node* root, int val, vector<int> &path){
    if(root == NULL) return 0;
    path.push_back(root->val);
    if(root->val == val) return 1;
    search(root->right, val, path);
    search(root->left, val, path);
}

int lca(Node* A, int val1, int val2) {
    vector<int> p1, p2;
    if(search(A,val1,p1) && search(A,val2,p2)){
        for(int i = 0; i < min(p1.size(),p2.size()); i++){
            if(p1[i]!=p2[i]){
                return p1[i-1];
            }
        }
        return p1[min(p1.size(),p2.size())-1];
    }
    return -1;
}

int main(){
	return 0;
}