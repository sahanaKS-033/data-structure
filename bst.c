#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "bst.h"
#define DATA_TYPE Node*
#include "queue.h"


Tree tree_new()
{
	Tree root ={NULL,0};
	return root;
}

static Node* make_new_node(int32_t element)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->data= element;
	new_node->right=NULL;
	new_node->left = NULL;
	return new_node;
}

Tree* add_node(Tree *t,int32_t element)
{
	assert(t!=NULL);
	Node *cur,*parent;
	cur=parent = t->root;
	while(cur!=NULL && cur->data!=element)
	{
		parent = cur;
		if(cur->data<element)
		{
			cur = cur->right;
		}
		else if(cur->data>element)
		{
			cur=cur->left;
		}
	}

	if(cur==NULL)
	{
		Node *new_node = make_new_node(element);
		if(parent==NULL)
		{
			t->root = new_node;
		}
		else if(parent->data<element)
		{
			parent->right = new_node;
		}
		else if(parent->data>element)
		{
			parent->left = new_node;
		}
		t->count++;

	}
	return t;
}


Tree* delete_node(Tree *t,int32_t element)
{
	assert(t!=NULL);
	t->root = _delete_(t,t->root,element);
	return t;
}


static Node* _delete_(Tree *t,Node *n ,int32_t element)
{
	Node *temp;
	if(n==NULL)
	{
		return n;
	}
	else if(element>n->data)
	{
		n->right= _delete_(t,n->right,element);
	}
	else if(element<n->data)
	{
		n->left= _delete_(t,n->left,element);
	}
	else if(n->right && n->left)
	{
		temp = find_minimum(n->right);
		n->data = temp->data;
		n->right = _delete_(t,n->right,n->data);
	}
	else
	{
		temp=n;
		if(n->right == NULL)
		{
			n = n->left; 
		}
		else
		{
			n = n -> right; 
		}
		free(temp);
		t->count--;
	}
	return n;
}


static Node* find_minimum(Node *n)
{
	if(n->left == NULL)
	{
		return n;
	}
	else
	{
		return find_minimum(n->left);
	}
}


int32_t lookup(Tree *t,int32_t element)
{
	assert(t!=NULL);
	Node *temp = t->root;
	while(temp!=NULL && temp->data!=element)
	{
		if(temp->data>element)
		{
			temp = temp->left;
		}
		else if(temp->data<element)
		{
			temp=temp->right;
		}
	}
	return (temp!=NULL);
}


uint32_t nodes_count(Tree *t)
{
	assert(t!=NULL);
	return t->count;
}


void tree_inorder(Tree *t)
{
	assert(t!=NULL);
	_inorder_(t->root);
}


static void _inorder_(Node *n)
{
	if(n)
	{
		_inorder_(n->left);
		printf("%d\t",n->data);
		_inorder_(n->right);
	}
}

void tree_preorder(Tree *t)
{
	assert(t!=NULL);
	_preorder_(t->root);
}

static void _preorder_(Node *n)
{
	if(n)
	{
		printf("%d\t",n->data);
		_preorder_(n->left);
		_preorder_(n->right);
	}
}

void tree_postorder(Tree *t)
{
	assert(t!=NULL);
	_postorder_(t->root);
	printf("\n");
}

static void _postorder_(Node *n)
{
	if(n)
	{
		_postorder_(n->left);
		_postorder_(n->right);
		printf("%d\t",n->data);
	}
}


void tree_levelorder(Tree *t)
{
	assert(t->root!=NULL);
	Node *temp;
	Queue Tree_queue = queue_new(t->count);
	Queue *queue = &Tree_queue;
	Queue_Result *res = (Queue_Result*) malloc(sizeof(Queue_Result));
	queue = queue_add(queue,t->root,res);
	while(queue->count!=0)
	{
		queue_delete(queue,res);
		temp = res->data;

		
		if(temp->left!=NULL)
		{	
			queue_add(queue,temp->left,res);
		}
		if(temp->right!=NULL)
		{
			queue_add(queue,temp->right,res);
		}
		printf("%d \t",temp->data);
	}
	printf("\n");
}