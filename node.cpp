#include"animal.h"

using namespace std;
//Yuxin Sun-CS202-Program3
//11-29-2021
//node.cpp file
//The file is wroking for the data structure
//the tree class manage the node class 
//the tree si binary search tree
//to operator overloding also in the data structore
//node class
//the function of the node
//constructor
node::node()
{
	data=NULL;
	left=NULL;
	right=NULL;
}
//default of the node
node::~node()
{
	delete data;
	data=NULL;

} 
//constructor of the node
node::node(animal*source)
{
	this->data=source;
	left=NULL;
	right=NULL;
}
//copy constructor of the node
node::node(const node&source)
{
	this->data=source.data;
	this->left=source.left;
	this->right=source.right;
}
//operator = overloading
node&node::operator=(const node&source)
{
	if(this==&source)
	return *this;
	if(this->data)
	{
		delete data;
	}
	if(this->right)
	{
		delete right;
	}
	if(this->left)
	{
		delete left;
	}
	this->data=source.data;
	this->left=source.left;
	this->right=source.right;
	return *this;
}
//add the node 
int node::insert(animal&to_add)
{
	if(strcmp(to_add.get_name(),this->data->get_name())<=0)
	{
		if(!this->left)
		{
			this->left=new node(&to_add);
			return 0;
		}
		this->left->insert(to_add);
	}
	else
	{
		if(this->right==NULL)
		{
			this->right=new node(&to_add);
			return 0;
		}
		this->left->insert(to_add);
	}
	return 1;
}
//remove a node
node*node::remove(char*name_rm,node *parent, node*&root, int path)
{
	if(!this)
		return 0;
	if(strcmp(this->data->get_name(),name_rm)>0)
	{
		node*rm=this->left->remove(name_rm,this,root,0);
		if(rm)
		{
			if(!rm->left&&rm->right)
			{
				this->right=rm->right;
				delete rm;
				rm=NULL;
			}
			else if(rm->left&&!rm->right)
			{
				this->left=rm->left;
				delete rm;
				rm=NULL;
			}
			else if(!rm->left&&!rm->right)
			{
				this->left=NULL;
				delete rm;
				rm=NULL;
			}
		}
	}
	else if(strcmp(this->data->get_name(),name_rm)<0)
	{
		node*rm=this->right->remove(name_rm,this,root,1);
		if(rm)
		{
			if(!rm->left&&rm->right)
			{
				this->right=rm->right;
				delete rm;
				rm=NULL;
			}
			else if(rm->left&&!rm->right)
			{
				this->left=rm->left;
				delete rm;
				rm=NULL;
			}
			else if(!rm->left&&!rm->right)
			{
				this->left=NULL;
				delete rm;
				rm=NULL;
			}
		}
	}
	else{
		if(this==root)
		{
			if(!root->left&&!root->right)
			{
				delete root;
				root=NULL;
				return root;
			}
			if(!root->right->left)
			{
				node*temp=root;
				root=root->right;
				root->left=temp->left;
				delete temp;
				return root;
			}
			else
			{
				node*ios=IOS(this->right,this->right);
				ios->right=root->right;
				ios->left=this->left;
				node*temp=root;
				root=ios;
				delete temp;
				return root;
			}
		}
		if(!this->left&&!this->right)
		{
			return this;
		}
		if(!this->left)
		{
			return this;
		}
		else if(!this->right)
		{
			parent->left=this->left;
			return this;
		}
		if(!this->right->left)
		{
			if(path==0)
			{
				parent->left=this->left;
				this->right->left=this->left;
			}
			else
			{
				parent->right=this->right;
				this->right->left=this->left;
			}
			return this;
		}
		node*ios=IOS(this->right,this->right);
		ios->right=this->right;
		ios->left=this->left;
		if(path==0)
		{
			parent->left=ios;
		}
		else
		{
			parent->right=ios;
		}
		return this;
	}
	return this;
}
//find the ios of the node

node*node::IOS(node*&current,node*&parent)
{
	if(!current)
		return NULL;
	if(current->left)
	{
		return IOS(current->left,current);
	}
	node*temp=current;
	parent->left=current->right;
	temp->right=NULL;
	temp->left=NULL;
	return temp; 
}
//search the node by name
bool node::search(char*name_search, animal**i)
{
	if(this==NULL)
		return 0;
	if(strcmp(name_search,this->data->get_name())<0)
	{
		return this->left->search(name_search,i);
	}
	if(strcmp(name_search,this->data->get_name())>0)
	{
		return this->right->search(name_search,i);
	}
	*i=this->data;
	return 1;
			
}
//delete the whole tree
int node::delete_all()
{
	if(this->left)
	{
		this->left->delete_all();
		delete this->left;
		this->left=NULL;
	}
	if(this->right)
	{
		this->right->delete_all();
		delete this->right;
		this->right=NULL;
	}
	return 1;
}
//display the tree
void node::display() const
{

	if(this==NULL)
		return ;
	this->left->display();
	this->data->display(cout);
	this->right->display();
	return ;
}



//Tree class
//constructor
tree::tree()
{
	root=NULL;
}
//destructore
tree::~tree()
{
	if(root)
	{
		root->delete_all();
	}
}
//copy constructor
tree::tree(const tree&source)
{
	this->root=source.root;
}
//add a new node to the list
int tree::insert(animal*to_add)
{
	if(!root)
	{
		root=new node(to_add);
		return 0;
	}
	else
	{
		root->insert(*to_add);
		return 1;
	}
}
//remove the node 
int tree::remove(char*name)
{
	if(!root)
		return 0;
	root->remove(name,NULL,root,0);
	return 1;
}
//search a node in the tree
bool tree::search(char*name, animal**i)
{
	if(!root)
		return 0;
	return root->search(name,i);
}
//remove all node in the list
int tree::remove_all()
{
	if(root==NULL)
	{
		return 0;
	}
	root->delete_all();
	delete root;
	root=NULL;
	return 1;
}
//display a tree

int tree::display()
{
	if(root==NULL)
		return 0;
	root->display();
	return 1;
}

	
