#include <stdio.h>
#include <conio.h>

struct node{
	int data;         //all nodes have a data 
	struct node *left;   // if there is a root , left, right =NULL;
	struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int data){     //a create new node 
	BTREE *p=(BTREE*)malloc(sizeof(BTREE));  //
	p->data=data;
	p->left=p->right=NULL;       
	return p;
}  

BTREE *insert(BTREE *root,int data){      
	if(root==NULL)
		root=new_node(data);  //we have just one node here and we create it with new_node func. so ýt is name root
	else{  //there is a one node or more we will add new
		if(data<root->data)
			root->left=insert(root->left,data);   // if new node's data is less than root , we add it must root's left 
		else
			root->right=insert(root->right,data);	
	}
	return root;
}

void inorder(BTREE *root){    // inorder sýralama,sort  //preorder, postorder 
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
main(){
	BTREE *myroot=NULL;  
	int i;
	do{
		printf("\n agaca veri eklemek icin sayi giriniz ...");
		scanf("%d",&i);
		if(i!=-1);   
			myroot=insert(myroot,i);
	}while(i!=-1);	
	inorder(myroot);
	printf("\n");
	getch();
	return 0;
}














