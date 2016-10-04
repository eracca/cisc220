#include "lab2lottery.hh"
#include <iostream>

using namespace std;

Owner *makeOwner(){    
    Owner *own = new Owner;
    for (int n=0; n<3; n++){
        own->totalWinners[n]=0;  
    }
    own->numStores= rand()&10+1;
    own->storeList= new Store[own->numStores]; 
    own->totalSold = 0; 
    for (int i=0; i< own->numStores;  i++){
        own->storeList[i] = makeStore();
        own->totalSold += own->storeList[i].numSold;
    }
    return own;   
}

Store makeStore(){
    Store shop;
    for (int n=0;  n<3; n++){
        shop.numWinners[n]=0; 
    }
    shop.storeID=rand()%100+1; 
    shop.numCust=rand()%10+1;
    shop.numSold=0;   
    shop.customerList = new Customer[shop.numCust]; 
    for (int i=0;  i< shop.numCust; i++){
        shop.customerList[i]= makeCustomer();
        shop.numSold+=shop.customerList[i].numTickets; 
    }
    return shop; 
}

Customer makeCustomer(){
    Customer cust;
    cust.custID=rand()%1000+1;
    cust.numTickets=rand()%20+1;
    cust.lotteryNums = new int*[cust.numTickets];
    for (int i=0; i< cust.numTickets; i++){
        cust.lotteryNums[i]=new int[3];
        cust.lotteryNums[i][0]=rand()%10;
        cust.lotteryNums[i][1]=rand()%10;
        cust.lotteryNums[i][2]=rand()%10;
        do {     
            cust.lotteryNums[i][0]=rand()%10;
            cust.lotteryNums[i][1]=rand()%10;
            cust.lotteryNums[i][2]=rand()%10;
        } while (cust.lotteryNums[i][0]==cust.lotteryNums[i][1]||
                 cust.lotteryNums[i][0]==cust.lotteryNums[i][2]||
                 cust.lotteryNums[i][1]==cust.lotteryNums[i][2]);
    }
    return cust;
}

void getWinners(int winners[]){
	winners[0] = rand() % 10;
	winners[1] = rand() % 10;
	winners[2] = rand() % 10;
	do {
		winners[0] = rand() % 10;
		winners[1] = rand() % 10;
		winners[2] = rand() % 10;
    }while(winners[0] == winners[1] ||
		  winners[0] == winners[2] ||
		  winners[1] == winners[2]);
}

int checkWin(int *nums, int *winners){
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

void findWinners(Owner *owner, int *winner){
    //find winners, update totalWinners 
    int win;
    for (int s=0;  s<owner->numStores; s++){
        for (int c=0; c< owner->storeList[s].numCust; c++){
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                win=checkWin(owner->storeList[s].customerList[c].lotteryNums[t],
                            winner);
                if (win > 0){
                    owner->storeList[s].numWinners[win-1]++;
                }
            }
        }
        for (int i=0; i<3; i++){
            owner->totalWinners[i]+=owner->storeList[s].numWinners[i];  
            }
    }

    //print all the required output
    cout << "winning tickets sold: " << (owner->totalWinners[0]+owner->totalWinners[1]+
    owner->totalWinners[2]) << endl; 
    cout << "winning numbers: " << winner[0] << winner[1] << winner[2] << endl;
    
    for (int s=0; s<owner->numStores; s++){
        cout <<"store id: " << owner->storeList[s].storeID << endl; 
        for (int c=0; c<owner->storeList[s].numCust;  c++){  
            cout <<"    customer id: " << owner->storeList[s].customerList[c].custID << endl;
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                if (checkWin(owner->storeList[s].customerList[c].lotteryNums[t],
                    winner)>0){
                    cout << "       ticket: " << 
                    owner->storeList[s].customerList[c].lotteryNums[t][0]
                     << owner->storeList[s].customerList[c].lotteryNums[t][1]<<
                     owner->storeList[s].customerList[c].lotteryNums[t][2] <<
                     "      matched: " <<
                     checkWin(owner->storeList[s].customerList[c].lotteryNums[t]
                     , winner) << endl; 
                }
            }
        }
        cout << "total count for store " << owner->storeList[s].storeID << ": " 
        << owner->storeList[s].numWinners[0] << " " << owner->storeList[s].numWinners[1] <<
        " "<< owner->storeList[s].numWinners[2] << endl;  
    }
}

void cleanUp(Owner *owner){
    //owners, stores, customers, and 2d arry of lottery nums are allocated dynamically
    //this means we need to go through and delete all of them
    for (int s=0; s<owner->numStores; s++){
        for (int c=0; c<owner->storeList[s].numCust; c++){
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                delete owner->storeList[s].customerList[c].lotteryNums[t];
            }
            delete owner->storeList[s].customerList[c].lotteryNums; 
        }
    }
    delete owner->storeList;
    delete owner; 
    return;
}
