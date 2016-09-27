#ifndef LAB2LOTTERY_HH
#define LAB2LOTTERY_HH

struct Customer{
    int custID;
    int numTickets;
    int** lotteryNums;
}

struct Store{
    int storeID;
    int numCust;
    Customer* customerList; 
    int numSold;
    int numWinners[3] = {0,0,0};
 }

struct Owner{
    Store* storeList;
    int numStores;
    int totalSold;
    int totalWinners[3]; 
}

Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

#endif  
