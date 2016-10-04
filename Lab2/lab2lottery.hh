#ifndef LAB2LOTTERY_HH
#define LAB2LOTTERY_HH

using namespace std; 

struct Customer{
    int custID;
    int numTickets;
    int** lotteryNums;
};

struct Store{
    int storeID;
    int numCust;
    Customer* customerList; 
    int numSold;
    int numWinners[3];
};

struct Owner{
    Store* storeList;
    int numStores;
    int totalSold;
    int totalWinners[3]; 
};

Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);

#endif  
