#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<memory>
#include <algorithm>
#include <cstdlib>//for exit
#include "BankAccount.h"  //bad practice to include cpp files

using namespace std;

void fillArray (ifstream &input,vector<shared_ptr<BankAccount>> &accountsVector);
int largest(vector<shared_ptr<BankAccount>> &accountsVector);
int smallest(vector<shared_ptr<BankAccount>> &accountsVector);
void printArray(vector<shared_ptr<BankAccount>>&accountsVector);
void checkDuplicates(vector<shared_ptr<BankAccount>> &accountsVector);
bool removeDuplicate(shared_ptr<BankAccount>& account1, shared_ptr<BankAccount>& account2);
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
  for(int i=0; i < accountsVector.size(); i++){
   	for(int j=i+1; j < accountsVector.size(); j++){
   		if(removeDuplicate(accountsVector[i], accountsVector[j]))
   		{
   			cout<<"Duplicates Found at "<<i<<" and "<<j<<endl;
		}
	}
	}
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
 	auto comparison = [](shared_ptr<BankAccount> &a, shared_ptr<BankAccount> &b)
        {
            return a->getAccountBalance() < b->getAccountBalance();
        };

    auto max = std::max_element(accountsVector.begin(), accountsVector.end(), comparison);
    return std::distance(accountsVector.begin(), max);
}
int smallest(vector<shared_ptr<BankAccount>>  &accountsVector){
// *** write this method
auto comparison = [](shared_ptr<BankAccount> &a, shared_ptr<BankAccount> &b)
        {
            return a->getAccountBalance() < b->getAccountBalance();
        };

    auto min = std::min_element(accountsVector.begin(), accountsVector.end(), comparison);
    return std::distance(accountsVector.begin(), min);
}
bool  removeDuplicate(shared_ptr<BankAccount>& account1, shared_ptr<BankAccount>& account2)
{
  // write this method
	return account1->equals(account2);
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
    accountsVector.push_back(make_shared<BankAccount>("newbie2",20,200,2000));
    accountsVector.push_back(make_shared<BankAccount>("newbie3",30,300,3000));
    accountsVector.push_back(make_shared<BankAccount>("newbie4",40,400,4000));
}
