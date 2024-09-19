#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class temp{

    int accNo;
    char name[25];
    char FatherName[25];
    char aadharNo[25];
    char MobNo[25];
    char email[25];
    float amount;
    int newAmount;
    fstream file,file1;

    public:
    int search;
    
    void createAccount(void);
    void depositAmount(void);
    void withdrawAmount(void);
    void checkInfo(void);

};
int main(){

     temp obj;
    char choice;

    cout<<"\n\n\n\t\t......:::ABCD Bank:::......";
	cout<<"\n\t\t:: press 1 to Login  Account :: ";
	cout<<"\n\t\t:: press 2 to Create Account ::";
	cout<<"\n\t\t:: press 0 to Exit           ::";
	cout<<"\n\t\t:: ......................... ::\n\t\t\t\t";
	cin>>choice;
    
    switch(choice){
        case '1':
            cout<<"Enter your account no :: ";
	        cin>>obj.search;
        while(1){

            cout<<"\n\n\n\t\t.......:::ABCD Bank:::.......";
            cout<<"\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout<<"\n\t\t:: press 2 to Withdraw Amount  ::";
            cout<<"\n\t\t:: press 3 to Check    Info    ::";
            cout<<"\n\t\t:: press 0 to Exit     Menu    ::";
            cout<<"\n\t\t:: ........................... ::\n\t\t\t\t";
            cin>>choice;

            switch (choice)
            {
            case '1':
                obj.depositAmount();
            break;
            case '2':
                obj.withdrawAmount();
            break;
            case '3':
                obj.checkInfo();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice...!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            obj.createAccount();
        break;
        case '0':
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice...! ";
        break;
    }
    return 0;
}

void temp::createAccount(){

  srand(time(0));
    accNo = rand()*rand()+rand()*rand();

    cout<<"Enter Your Name: ";
    cin>>name;

    cout<<"Enter Your Father's Name: ";
    cin>>FatherName;

    cout<<"Enter Your Aadhar Card Number: "<<endl;
    cin>>aadharNo;

    cout<<"Enter Your Mobile Number: ";
    cin>>MobNo;

    cout<<"Enter Your Email: ";
    cin>>email;

    cout<<"Enter Your Amount: ";
    cin>>amount;

    cout<<accNo<<" This is your Account Number...\n";
    cout<<"Please save it ";

    file.open("data.txt",ios::out|ios::app);
    file<<accNo<<"\t"<<name<<"\t"<<FatherName<<"\t"<<aadharNo<<"\t"<<MobNo<<"\t"<<email<<"\t"<<amount<<endl;
    file.close();
    }

    void temp::depositAmount(){
        cout<<"Enter Amount to deposit: ";
    cin>>newAmount;

    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accNo>>name>>FatherName>>aadharNo>>MobNo>>email>>amount;

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

    }
void temp:: withdrawAmount(){
    cout<<"Enter Amount to withdraw: ";
    cin>>newAmount;


file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accNo>>name>>FatherName>>aadharNo>>MobNo>>email>>amount;

     while(!file.eof()){
        if(accNo==search){
            cout<<"\ncurrent amount: "<<amount;
            amount=amount-newAmount;
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
}

void temp:: checkInfo(){
    fstream file;
    file.open("data.txt",ios::in);
    if(!file){
    cout<<"File opening error !";
    }
    file>>accNo>>name>>FatherName>>aadharNo>>MobNo>>email>>amount;
	while(!file.eof()){
		if(accNo==search){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: account Number ::: ";
            cout<<"\t   "<<accNo<<endl;
            cout<<"\t::: User Name      ::: ";
            cout<<"\t   "<<name<<"\n";
            cout<<"\t::: Father Name    ::: ";
            cout<<"\t   "<<FatherName<<"\n";
            cout<<"\t::: Aadhar number    ::: ";
            cout<<"\t   "<<aadharNo<<"\n";
            cout<<"\t::: Phone Number   ::: ";
            cout<<"\t   "<<MobNo<<"\n";
            cout<<"\t::: Email          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";
		
	    }
		file>>accNo>>name>>FatherName>>aadharNo>>MobNo>>email>>amount;
	}
	
	file.close();
}


