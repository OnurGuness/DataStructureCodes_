#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

typedef struct node BTREE;


//leaf sayýsýný

int leafCount(BTREE *node){
	if(node==NULL)
		return 0;
	else if(node->left==NULL && node->right==NULL)
		return 1;
	else 
		return leafCount(node->left) + leafCount(node->right);
}

BTREE *new_node(int data){
	BTREE *node = (BTREE*)malloc(sizeof(BTREE));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

BTREE *insert(BTREE *root,int data){
	if(root!=NULL){
		if(data<root->data)
			root->left = insert (root->left,data);
		else
			root->right = insert(root->right,data);
	}else  // ortada root yok, root==NULL ?
		root =  new_node(data);
	return root;
	
}

//düðümlerin datalarýnýn toplamýný

int sumBTREE(BTREE *root){
	if(root==NULL)
		return 0;
	return (root->data + sumBTREE(root->left) + sumBTREE(root->right));
}


//agactaki herhangi bir düðümün depth

int find_depth(BTREE *root, int data){
	if(root==NULL){
		printf("there is no %d\n",data);
		return -1000;
	}
	if(root->data==data)  // kök düðümünün derinliði 0 
		return 0;
	else if(data < root->data)
		return 1+ find_depth(root->left,data);
	else 
		return 1+ find_depth(root->right,data);
	
}

//agacýn yüsseklðini bulduran fonk. 
int tree_height(BTREE *root){
	if(!root)
		return -1;
	else{
		int left_height = tree_height(root->left);
		int rigth_height = tree_height(root->right);
		if(left_height > rigth_height)
			return left_height + 1;
		else 
			return rigth_height + 1;
	}
}


int main(){
	BTREE *myroot = new_node(10);
	myroot= insert (myroot,8);
	myroot= insert (myroot,7);
	myroot= insert (myroot,9);
	myroot= insert (myroot,12);
	myroot= insert (myroot,13);
	myroot= insert (myroot,11);
	myroot= insert (myroot,6);
	myroot= insert (myroot,4);
	
	
	printf("leaf count on tree :%d\n",leafCount(myroot));
	printf("sum of data on tree : %d\n",sumBTREE(myroot));
	printf("depth of the given node :%d\n",find_depth(myroot,6));
	int height = tree_height(myroot);
	printf("height of tree :%d\n",height);
	
	getch();
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}





















