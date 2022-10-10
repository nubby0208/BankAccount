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
bool removeDuplicate(vector<shared_ptr<BankAccount>> &accountsVector, shared_ptr<BankAccount> account);
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
		std::sort(accountsVector.begin(), accountsVector.end());

    auto i1 = std::adjacent_find(accountsVector.begin(), accountsVector.end());
    
    if (i1 == accountsVector.end()) {
        std::cout << "No Duplicates\n";
    } else {
        std::cout << "Duplicates Found";
//                  << std::distance(v1.begin(), i1) << ", *i1 = "
//                  << *i1 << '\n';
		removeDuplicate(accountsVector, accountsVector[std::distance(accountsVector.begin(), i1)]);
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
bool  removeDuplicate(vector<shared_ptr<BankAccount>>  & accountsVector, shared_ptr<BankAccount> account)
{
	
  // write this method
for (std::vector<shared_ptr<BankAccount>>::iterator it = accountsVector.begin(); it != accountsVector.end();)
    {
        if (*it == account){
		
            it = accountsVector.erase(it);
            return true;
        }
    }
    return false;
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
