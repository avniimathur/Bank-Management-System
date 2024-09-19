#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){

    int accNo;
    char name[25];
    char FatherName[25];
    char aadharNo[25];
    char MobNo[25];
    char email[25];
    float amount;

    srand(time(0));
    accNo = rand()*rand()+rand()*rand();

    cout<<"Enter Your Name: ";
    cin>>name;

    cout<<"Enter Your Father's Name: ";
    cin>>FatherName;

    cout<<"Enter Your Aadhar Card Number: ";
    cin>>aadharNo;

    cout<<"Enter Your Mobile Number: ";
    cin>>MobNo;

    cout<<"Enter Your Email: ";
    cin>>email;

    cout<<"Enter Your Amount: ";
    cin>>amount;

    cout<<accNo<<"This is your Account Number...\n";
    cout<<"Please save it ";

    fstream file;

    file.open("data.txt",ios::out|ios::app);
    file<<accNo<<"\t"<<name<<"\t"<<aadharNo<<"\t"<<MobNo<<"\t"<<email<<"\t"<<amount<<endl;
    file.close();

    return 0;

}