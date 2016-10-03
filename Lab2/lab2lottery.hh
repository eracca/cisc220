#ifndef LAB2LOTTERY_HH
#define LAB2LOTTERY_HH

using namespace std; 

/* 
Customer 
Includes:
- customer ID
- number of tickets purchased
- lottery numbers
*/
struct Customer{
    int custID;
    int numTickets;
    int** lotteryNums;
};


/*Store
Includes:
- store ID
- number of customers
- list of customer objects
- number of lottery tickets sold
- number of winners at store
*/
struct Store{
    int storeID;
    int numCust;
    Customer* customerList; 
    int numSold;
    int numWinners[3] = {0,0,0};
};

/*
Owner
Includes:
- list of store objects
- number of stores the owner owns
- total number of tickets sold
- total number of winners
*/
struct Owner{
    Store* storeList;
    int numStores;
    int totalSold;
    int totalWinners[3]= {0,0,0}; 
};

// function declerations 
Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);

#endif  
