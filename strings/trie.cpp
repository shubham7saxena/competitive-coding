#include <bits/stdc++.h>

using namespace std;


struct node{
	struct node* children[26];
	int prefixes;
	bool isLeaf;
};

struct node *newNode()
{
    struct node *parentNode = NULL;
 
    parentNode = new node;
 
    if (parentNode)
    {
        parentNode->isLeaf = false;
 		parentNode->prefixes = 0;
        for (int i = 0; i < 26; i++)
            parentNode->children[i] = NULL;
    }
 
    return parentNode;
}

void insert(struct node *root, string word)
{
    int index;
    int length = (int)word.size();
 
    struct node *pCrawl = root;
 
    for (int level = 0; level < length; level++)
    {
        index = (int)(word[level] - 'a');
        if (!pCrawl->children[index])
            pCrawl->children[index] = newNode();
 		pCrawl->prefixes++;
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isLeaf = true;
}

bool search(struct node *root, string key)
{
    int length = (int)key.size();
    int index;
    struct node *pCrawl = root;
 
    for (int level = 0; level < length; level++)
    {
        index = (int)(key[level]-'a');
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isLeaf);
}

// returns proper prefixes
int countPrefixes(struct node *root, string key)
{
    int length = (int)key.size();
    int index;
    struct node *pCrawl = root;
 
    for (int level = 0; level < length; level++)
    {
        index = (int)(key[level]-'a');
 
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return pCrawl->prefixes;
}

int main(){
    int n;
    cin>>n;
    string s1,s2;
    struct node *root = newNode();
    for(int i = 0; i < n; i++){
    	cin>>s1>>s2;
    	if(s1=="add"){
    		insert(root,s2);
    	}
    	else{
    		cout<<countPrefixes(root,s2)<<endl;
    	}
    }
	return 0;
}