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
    int search;
    int newAmount;
    cout<<"Enter Your Account Number: ";
    cin>>search;
    cout<<"Enter Amount to deposit: ";
    cin>>newAmount;

    fstream file,file1;
    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accNo>>name>>aadharNo>>MobNo>>email>>amount;

     while(!file.eof()){
        if(accNo==search){
            cout<<"\ncurrent amount: "<<amount;
            amount=amount+newAmount;
            cout<<"\nupdated amount: "<<amount;
            file1<<accNo<<name<<"\t"<<FatherName<<"\t"<<aadharNo<<"\t"<<MobNo<<"\t"<<email<<"\t"<<amount<<endl;
        }else{
            file1<<accNo<<name<<"\t"<<FatherName<<"\t"<<aadharNo<<"\t"<<MobNo<<"\t"<<email<<"\t"<<amount<<endl;
        }
        file>>accNo>>name>>FatherName>>aadharNo>>MobNo>>email>>amount;
     }

     file.close();
     file1.close();
     remove("data.txt");
     rename("data1.txt","data.txt");

     return 0;
     
}