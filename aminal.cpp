//Yuxin Sun-program3-CS202
//15-11-2020
//animal.cpp file
//the file is working for the function about aquarium, feed, wild zoo and animal class
//the main idea is operator overloading
#include"animal.h"
using namespace std;
//The animal class - the base class
//constructor of animal
//default construction
animal::animal():name(NULL)
{
	date.clear();
}
//destructor
animal::~animal()
{
	delete[]name;
	name=NULL;
	date.clear();
}
//copy constructor
animal::animal(const animal&source)
{
	if(source.name)
       {     
	name=new char[strlen(source.name)+1];
	strcpy(name,source.name);	
        }
	date=source.name;
}

 animal&animal::operator=(const animal&a1)
{
	if(this==&a1)
		return *this;
	if(name!=NULL)
		delete [] name;
	name=new char[strlen(a1.name)+1];
	strcpy(name,a1.name);
        date=a1.date;
	return *this;
}


 bool animal::operator < (const animal &p1)
 {
 	if(strcmp(name,p1.name)<0)
 		return 1;
 	return 0;
 }
 bool animal::operator <=(const animal &p1)
 {
 	if(strcmp(name,p1.name)<=0)
 		return 1;
 	return 0;
 }

 bool animal::operator > (const animal &p1)
 {
 	if(strcmp(name,p1.name)>0)
 		return 1;
 	return 0;
 }
 bool animal::operator >= (const animal &p1)
 {
 	if(strcmp(name,p1.name)>=0)
 		return 1;
 	return 0;
 }

 bool animal::operator ==(const animal &p1)
 {
 	if(strcmp(name,p1.name)==0)
 		return 1;
 	return 0;
 }
 bool animal::operator != (const animal &p1)
 {
 	if(strcmp(name,p1.name)==0)
 		return 0;
 	return 1;
 }
bool animal::operator < (const char*n1)
 {
 	if(strcmp(name,n1)<0)
 		return 1;
 	return 0;
 }
 bool animal::operator <=(const char*n1)
 {
 	if(strcmp(name,n1)<=0)
 		return 1;
 	return 0;
 }

 bool animal::operator > (const char*n1)
 {
 	if(strcmp(name,n1)>0)
 		return 1;
 	return 0;
 }
 bool animal::operator >= (const char*n1)
 {
 	if(strcmp(name,n1)>=0)
 		return 1;
 	return 0;
 }

 bool animal::operator ==(const char*n1)
 {
 	if(strcmp(name,n1)==0)
 		return 1;
 	return 0;
 }
 bool animal::operator != (const char*n1)
 {
 	if(strcmp(name,n1)==0)
 		return 0;
 	return 1;
 }
char*animal::get_name()
{

	return name;
}
//The aquarium class
//constructor
aquarium::aquarium()
{
      animal_name.clear();
      address.clear();
}
//deconstructor
aquarium::~aquarium()
{
      animal_name.clear();
      address.clear();
}
//copy constructure
aquarium::aquarium(const aquarium&source):animal(source)
{
	animal_name=source.animal_name;
         address=source.address;
		
}
//add a aquarium
void aquarium::add()
{
         char name_copy[100];
	cout<<"Please enter the animal activity name " <<endl;
	cin.get(name_copy,100,'\n');
	cin.ignore(100,'\n');
	name=new char[strlen(name_copy)+1];
	strcpy(name,name_copy);
	cout<<"Please enter the date of the activity"<<endl;
	cin>>date;
	cin.ignore(100,'\n');
	cout<<"Please enter the animal name of the activity"<<endl;
	cin>>animal_name;
	cin.ignore(100,'\n');
	cout<<"Please enter the address of the activity"<<endl;
	cin>>address;
	cin.ignore(100,'\n');
         
}
     
aquarium&aquarium::operator=(const aquarium&to_copy)
{
	if(this==&to_copy)
		return *this;
	if(name!=NULL)
	{
		delete []name;
	}
	name=new char[strlen(to_copy.name)+1];
	strcpy(name,to_copy.name);
         date=to_copy.date;
	animal_name=to_copy.animal_name;
	address=to_copy.address;        
	return *this;

}

void aquarium::display(ostream&out) const
{
	out<<"The animal activity is "<<name<<endl;
	out<<"The date is"<<date<<endl;
	out<<"The address is:"<<address<<endl;
        out<<"There have "<<animal_name<<" in the aquarium."<<endl;
          
}

ostream&operator<<(ostream &out,const aquarium &to_display)
{
      to_display.display(out);
      return out;
}


//The feed class
//constructor
feed::feed()
{
      animal_name.clear();
      address.clear();
      prepare.clear();
}
//deconstructor
feed::~feed()
{
      animal_name.clear();
      address.clear();
      prepare.clear();
}
//copy constructure
feed::feed(const feed&source):animal(source)
{
	animal_name=source.animal_name;
         address=source.address;
	 prepare=source.prepare;
		
}
//add a feed
void feed::add()
{
         char name_copy[100];
	cout<<"Please enter the animal activity name " <<endl;
	cin.get(name_copy,100,'\n');
	cin.ignore(100,'\n');
	name=new char[strlen(name_copy)+1];
	strcpy(name,name_copy);
	cout<<"Please enter the date of the activity"<<endl;
	cin>>date;
	cin.ignore(100,'\n');
	cout<<"What kind of animal you will feed "<<endl;
	cin>>animal_name;
	cin.ignore(100,'\n');
	cout<<"Please enter the address of the activity"<<endl;
	cin>>address;
	cin.ignore(100,'\n');
	cout<<"What things need to prepare?"<<endl;
	cin>>prepare;
	cin.ignore(100,'\n');
         
}
     
feed&feed::operator=(const feed&to_copy)
{
	if(this==&to_copy)
		return *this;
	if(name!=NULL)
	{
		delete []name;
	}
	name=new char[strlen(to_copy.name)+1];
	strcpy(name,to_copy.name);
         date=to_copy.date;
	animal_name=to_copy.animal_name;
	address=to_copy.address;        
	prepare=to_copy.prepare;
	return *this;

}

void feed::display(ostream&out) const
{
	out<<"The animal activity is "<<name<<endl;
	out<<"The date is"<<date<<endl;
	out<<"The address is:"<<address<<endl;
        out<<"You will feed "<<animal_name<<" in the activity."<<endl;
	out<<"You need to prepare "<<prepare<<" to this activity."<<endl;

          
}

ostream&operator<<(ostream &out,const feed &to_display)
{
      to_display.display(out);
      return out;
}

//The wild zoo class
//constructor
wild_zoo::wild_zoo()
{
      zoo_name.clear();
      address.clear();
}
//deconstructor
wild_zoo::~wild_zoo()
{
      zoo_name.clear();
      address.clear();
}
//copy constructure
wild_zoo::wild_zoo(const wild_zoo&source):animal(source)
{
	 zoo_name=source.zoo_name;
         address=source.address;
		
}
//add a aquarium
void wild_zoo::add()
{
         char name_copy[100];
	cout<<"Please enter the animal activity name " <<endl;
	cin.get(name_copy,100,'\n');
	cin.ignore(100,'\n');
	name=new char[strlen(name_copy)+1];
	strcpy(name,name_copy);
	cout<<"Please enter the date of the activity"<<endl;
	cin>>date;
	cin.ignore(100,'\n');
	cout<<"Please enter the name of the zoo"<<endl;
	cin>>zoo_name;
	cin.ignore(100,'\n');
	cout<<"Please enter the address of the zoo"<<endl;
	cin>>address;
	cin.ignore(100,'\n');
         
}
     
wild_zoo&wild_zoo::operator=(const wild_zoo&to_copy)
{
	if(this==&to_copy)
		return *this;
	if(name!=NULL)
	{
		delete []name;
	}
	name=new char[strlen(to_copy.name)+1];
	strcpy(name,to_copy.name);
         date=to_copy.date;
	zoo_name=to_copy.zoo_name;
	address=to_copy.address;        
	return *this;

}

void wild_zoo::display(ostream&out) const
{
	out<<"The animal activity is "<<name<<endl;
	out<<"The date is"<<date<<endl;
	out<<"The address is:"<<address<<endl;
        out<<"The zoo name is "<<zoo_name<<"."<<endl;
          
}

ostream&operator<<(ostream &out,const wild_zoo &to_display)
{
      to_display.display(out);
      return out;
}
