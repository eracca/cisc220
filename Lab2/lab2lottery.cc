#include "lab2lottery.hh"

Owner *makeOwner(){    
    Owner *own = new Owner;  
    own=>numStores= rand()&10+1;
    own=>storeList[numStores]; 
    own=>totalSold = 0; 
    for (int i=0; i< own.numStores;  i++){
        own.storeList[i] = makeStore();
        own.totalSold += own.storeList[i].numSold
    }
    return own;   
}

Store makeStore(){
    Store shop;
    shop.storeID=rand()%100+1; 
    shop.numCust=rand()%10+1;

}
Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

