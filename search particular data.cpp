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
    cout<<"Enter Your Account Number: ";
    cin>>search;

    fstream file;
    file.open("data.txt",ios::in);
    if(!file){
        cout<<"File opening error !";
    }
    file<<accNo<<name<<aadharNo<<MobNo<<email<<amount;
    while(!file.eof()){
        if(accNo==search){
            cout<<accNo<<name<<aadharNo<<MobNo<<email<<amount;
        }
        file>>accNo>>name>>aadharNo>>MobNo>>email>>amount;
    }
    
    file.close();

    return 0;

}