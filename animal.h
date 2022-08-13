#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include<cstdlib>

using namespace std;

//Yuxin Sun-CS202-program3
//15-11-2020
//animal.h file
//the class and photograph of the function
//The program is working for the animal activity
////the activity have three type
//which are aquarium, feeding and wild zoo
//and the base class is animal
//the data structure will be BST
//the base class animal
class animal
{
	public:
		animal();
		animal(const animal&source);
		virtual ~animal()=0;
		virtual void add()=0;
		virtual void display(ostream&out)const =0;

		 animal&operator=(const animal&a1);
		friend ostream&operator<<(ostream&out, const animal&to_display);
	        bool operator<(const animal&);
		bool operator>(const animal&);
		bool operator<=(const animal&);
		bool operator>=(const animal&);
		bool operator==(const animal&);
		bool operator!=(const animal&);;
		bool operator<(const char*);
		bool operator>(const char*);
		bool operator<=(const char*);
		bool operator>=(const char*);
		bool operator==(const char*);
		bool operator!=(const char*);


		char*get_name();
	protected:
		char*name;
		string date;
};

//aquarium class

 class aquarium:public animal
{
	public:
		aquarium();
		~aquarium();
		aquarium(const aquarium&source);
		void add();
		//I am still thinking about operator part
                 aquarium&operator =(const aquarium&to_copy);
                 friend ostream&operator<<(ostream &out,const aquarium &to_display);
                 void display(ostream&out) const;
	protected:
		string animal_name;
		string address;
};

//feed class
class feed:public animal
{
	public:
		feed();
		~feed();
		feed(const feed&source);
		void add();
		//I am still thinking about operator part
		feed&operator =(const feed&to_copy);
                 friend ostream&operator<<(ostream &out,const feed&to_display);
                 void display(ostream&out) const;

	protected:
		string animal_name;
		string address;
		string prepare;
};

//wild zoo
class wild_zoo:public animal
{
	public:
		wild_zoo();
		~wild_zoo();
		wild_zoo(const wild_zoo&source);
		void add();
		//I am still thinking about operator part
		 wild_zoo&operator =(const wild_zoo&to_copy);
                 friend ostream&operator<<(ostream &out,const wild_zoo &to_display);
                 void display(ostream&out) const;

	protected:
		string zoo_name;
	
		string address;
		
};

//node class for the tree
class node
{
	public:
	node();
	~node();
	node(animal*source);
	node(const node&source);
	node&operator=(const node&);
	int insert(animal&to_add);
	node*remove(char*name,node *parent, node*&root, int path);
	node*IOS(node*&current,node*&parent);
	bool search(char*name, animal**i);
	int delete_all();
	void display() const;
	 friend ostream&operator<<(ostream &out,const node&to_display);
                 
	protected:
		animal*data;
		node*left;
		node*right;
};

class tree
{
	public:
		tree();
		~tree();
		tree(const tree&source);
		tree&operator=(const tree&t1);
		int insert(animal*to_add);
		int remove(char*name);
		bool search(char*name, animal**i);
		int remove_all();
		int display();
	private:
		node*root;
};
