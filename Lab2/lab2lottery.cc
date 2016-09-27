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
    shop.numSold=0;  
    Customer shop.customerList[numCust];
    for (int i=0;  i< shop.numCust; i++){
        shop.customerList[i]= makeCustomer;
        shop.numSold+=shop.customerList[i].numTickets; 
    }
    return shop; 
}

Customer makeCustomer();
void getWinners (int winners[]);
void findWinners(Owner *owner, int *ls);

int checkwin(int *nums, int *winners){
    int match=0;  
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (nums[i]==winners[j]){
                match++; 
            }
        }
    }
    return match;  
}

//check with TA
void cleanUp(Owner *own){
    delete own; 
}
