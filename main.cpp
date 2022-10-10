#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<memory>
#include <cstdlib>//for exit
#include "BankAccount.h"  //bad practice to include cpp files

using namespace std;

void fillArray (ifstream &input,vector<shared_ptr<BankAccount>> &accountsVector);
int largest(vector<shared_ptr<BankAccount>> &accountsVector);
int smallest(vector<shared_ptr<BankAccount>> &accountsVector);
void printArray(vector<shared_ptr<BankAccount>>&accountsVector);
void checkDuplicates(vector<shared_ptr<BankAccount>> &accountsVector);
void insertAccounts(vector<shared_ptr<BankAccount>> &accountVector);
int main() {
  vector<shared_ptr<BankAccount>> accountsVector;
  try{
  ifstream input("BankData.txt");
  if (input){  
    //cout<<" FIle Open "<<endl;
    
    fillArray(input,accountsVector);
    //getCount using static variable getCount
    //getCount using vector size
    printArray(accountsVector);
    
    cout<<"Largest Balance: "<<endl;
    cout<<accountsVector[largest(accountsVector)]->toString()<<endl;
    cout<<"Smallest Balance :"<<endl;
    cout<<accountsVector[smallest(accountsVector)]->toString()<<endl;
    cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
    cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
    
    checkDuplicates(accountsVector);
    cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
     cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
     insertAccounts(accountsVector);
     cout<<"\nInserted Three New Accounts: Reprinting List \n" <<endl;
     printArray(accountsVector);
      cout<<"Using the static count, there are "<<BankAccount::count<< " accounts"<<endl;
     cout<<"Using vector size, there are "<<accountsVector.size()<< " accounts"<<endl;
    
    
  }
  else 
     throw string("File Open Error");
}
catch (string message){
   cout<<message<<endl;
   exit(0);
}
}
void checkDuplicates(vector<shared_ptr<BankAccount>>  &accountsVector){
  // *** Write this method

    }
  
   
void fillArray (ifstream &input,vector<shared_ptr<BankAccount>>  &accountsVector){
   string accountName;string lastName;string firstName,inputLine;
  int id,accountNumber;
  double accountBalance;
  while (!input.eof()){
    getline(input,inputLine);
    istringstream streamLine(inputLine);
    streamLine>>firstName>>lastName>>id>>accountNumber>>accountBalance;
      accountName=firstName+" " + lastName;
      shared_ptr<BankAccount> temp=make_shared<BankAccount>(accountName,id,accountNumber,accountBalance);
      accountsVector.push_back(temp);
    }

}
//presumes that negative balances will not be there
int largest(vector<shared_ptr<BankAccount>>  &accountsVector){
 // ****write this method
}
int smallest(vector<shared_ptr<BankAccount>>  &accountsVector){
// *** write this method
}
bool  removeDuplicate(shared_ptr<BankAccount> account1, shared_ptr<BankAccount> account2)
{

  // write this method

}
void printArray(vector<shared_ptr<BankAccount>>  &accountsVector){
   cout<<"FAVORITE BANK - CUSTOMER DETAILS "<<endl;
   cout<<"--------------------------------"<<endl;
   auto iter = accountsVector.begin();
   for (iter = accountsVector.begin();iter<accountsVector.end();iter++)
   
       cout<<(*iter)->toString()<<endl;
//use iterator
}   
void insertAccounts(vector<shared_ptr<BankAccount>>  & accountsVector){

  //****write this method
  
}