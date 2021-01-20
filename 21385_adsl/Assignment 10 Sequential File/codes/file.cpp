//============================================================================
// Name        : Assignment10_File.cpp
// Author      : swapnil Ghule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class FileOperations
{
	fstream file,file2;
public:
	  void writeInfo()
	{
		int roll;
		string name,division,address;
		file.open("Student.txt", ios::app);
			if(!file)
			{
				cout<<"Error in opening file";
				return ;
			}
			cout<<"Enter roll no: ";cin>>roll;
			cout<<"Enter name: ";cin>>name;
			cout<<"Enter division: ";cin>>division;
			cout<<"Enter address: ";cin>>address;
			//cout<<roll<<name<<division<<address;
		//	string r= to_string(roll);
		    file<<roll;
			file<<" "+name+" "+division+" "+address+"\n";
			file.close();
			cout<<"\nRecord added";
	}
   void readInfo()
   {
	   string data;
	   file.open("Student.txt", ios::in);
	   			if(!file)
	   			{
	   				cout<<"Error in opening file";
	   				return;
	   			}
	   			while (std::getline(file, data)) {
	   				cout<<data<<"\n";
	   			}
	   			file.close();
   }
   void searchRecord()
   {
	   string line;string roll;
	   size_t pos;bool flag=0;

	   	   file.open("Student.txt");
	   	   			if(!file)
	   	   			{
	   	   				cout<<"Error in opening file student.txt";
	   	   				return;
	   	   			}
	   	   			cout<<"\nEnter a roll no.";cin>>roll;
	   	   		while(getline(file,line))
	   	   					{
	   	   					   pos = line.find(roll);
	   	   					   if(pos!=string::npos) // string::npos is returned if string is not found
	   	   		                 {
	   	   		                  cout <<"Found!"<<"\n";
	   	   		                  cout<<line;
	   	   		                  flag=1;break;
	   	   		                 }
	   	   		              }
	   	   		if(flag==0)
	   	   			cout<<"\nRecord not found..";
	   	   	    file.close();
   }
   void deleteRecord()
      {
   	   string line;string roll;
   	   size_t pos;bool flag=0;
   	       file2.open("Sample.txt",ios::app);
   	   	   file.open("Student.txt");
   	   	   			if(!file)
   	   	   			{
   	   	   				cout<<"Error in opening file student.txt";
   	   	   				return;
   	   	   			}
   	   	   		if(!file2)
   	   	   					{
   	   	   						cout<<"Error in opening file sample.txt";
   	   	   						return ;
   	   	   					}
   	   	   			cout<<"\nEnter a roll no.";cin>>roll;
   	   	   		while(getline(file,line))
   	   	   					{
   	   	   					   pos = line.find(roll);
   	   	   					   if(pos!=string::npos) // string::npos is returned if string is not found
   	   	   		                 {
   	   	   		                  cout <<"Found!"<<"\n";
   	   	   		                  cout<<"Deleted record\n";
   	   	   		                  cout<<line;
   	   	   		                  file<<"";
   	   	   		                  flag=1;
   	   	   		                 }else
   	   	   		                 file2<<line<<"\n";
   	   	   		              }
   	   	   		if(flag==0)
   	   	   			cout<<"\nRecord not found..";
   	   	   	    file.close();
   	   	   		file2.close();
   	   	   	    remove("Student.txt");
   	   	   		rename("Sample.txt","Student.txt");
      }
};
int main() {
	FileOperations s;
	int choice;char ch;
	do{
	cout<<"\n1.Add record.\n2.Search Record\n3.Delete Record.\n4.Display all records.\nEnter a choice >>";cin>>choice;
	switch(choice)
	{
	case 1:s.writeInfo();
		   break;
	case 2:s.searchRecord();
		   break;
	case 3:s.deleteRecord();
		   break;
	case 4:s.readInfo();
		   break;
	default:  cout<<"\nInvalid choice...";
	}
	cout<<"\nContinue(y/n)";cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}
