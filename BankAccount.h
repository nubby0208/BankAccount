
class BankAccount{
  private:
      const static  double  MIN_BALANCE;
       const static double REWARD_RATE;
       const static double MIN_REWARD_AMOUNT;
    public: static int count;
    private:
      int accountNumber,id;
      std::string accountName;
      double accountBalance;

    public: 
      BankAccount();
      BankAccount(std::string accountName, int id,int accountNumber, double accountBalance);
       //getters
      public:
        std::string getAccountName();
        int getAccountNumber();
        double getAccountBalance();
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

      void setAccountBalance(double accountBalance);

      std::string toString();

      bool withdraw(double amount);
      int getCount();
      
      void deposit(double amount);
      bool equals(std::shared_ptr<BankAccount>other);
      private: void addReward(double amount);
      private: int getId();

    
};
 