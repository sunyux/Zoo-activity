#include"animal.h"
//Yuxin Sun-CS202_program 3
//11-18-2020
//main.cpp
//is working for the main function of the program
//and the interface of the system
//the user can add, remove display and display all function of the tree
using namespace std;

int main()
{
	int SIZE=1000;
	tree a_tree;
	int choose=0;
	int choose_type=0;
	char*temp_name=NULL;
	while(true)
	{
		cout<<">>>>>>>>Welcome to use animal system!<<<<<<<"<<endl;
		cout<<"      Please choose the function:           "<<endl;
		cout<<"      Enter '0' to quit the system\n"<<endl;
		cout<<"      Enter '1' to add an activity\n"<<endl;
		cout<<"      Enter '2' to delete an activity\n"<<endl;
		cout<<"      Enter '3' to display all activity\n"<<endl;
		cout<<"      Enter '4' to delete all activities\n"<<endl;
		cout<<"      Please enter your choose  \n"<<endl;
		cin>>choose;
		cin.ignore(100,'\n');
		try{
			if(choose>4)
				throw choose;
		}
		catch(int)
		{
			cout<<"  Wrong choose, quit the system\n";
			choose=0;
		}
		switch(choose)
		{
			case 0:
				cout<<"  Have a good dat! ^-^"<<endl;
				return 0;
			case 1:
				{
					cout<<"        What kind of activity you want to add?"<<endl;
					cout<<"        1.Aquarium"<<endl;
					cout<<"        2.Feed"<<endl;
					cout<<"        3.Wild Zoo"<<endl;
					cin>>choose_type;
					cin.ignore(100,'\n');
					if(choose_type<1||choose_type>3)
						cout<<"Wrong choose, please check again"<<endl;
					if(choose_type==1)
					{

						animal *a_quarium=new aquarium;
						a_quarium->add();
						a_tree.insert(a_quarium);
						break;
					}
					if(choose_type==2)
					{
						animal*a_feed=new feed;
						a_feed->add();
						a_tree.insert(a_feed);
						break;
					}
					if(choose_type==3)
					{
						animal*a_zoo=new wild_zoo;
						a_zoo->add();
						a_tree.insert(a_zoo);
						break;
					}
					break;
				}
			case 2:
				{
					cout<<"Please enter the name that you want to delete"<<endl;
					char temp_name_rm[200];
				
					cin.get(temp_name_rm,100,'\n');
					temp_name=new char[strlen(temp_name_rm)+1];
					strcpy(temp_name,temp_name_rm);
					cin.ignore(100,'\n');
					if(a_tree.remove(temp_name))
						cout<<"Delete it!"<<endl;
					else
						cout<<"The activity isn't exist"<<endl;
					break;
				}
			case 3:
				{
					a_tree.display();
					break;
				}
			case 4:
				{
					a_tree.remove_all();
					break;
				}
			default:
				{
					cout<<"  Have a good day!"<<endl;
					return 0;
				}

}
}
}

