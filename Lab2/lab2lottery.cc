#include "lab2lottery.hh"
#include <cstdlib>
#include <iostream>


using namespace std; 

/*
Creates a new owner
Parameters:
Returns:
	new owner object
*/
Owner *makeOwner(){    
    Owner *own = new Owner;  
    own->numStores= rand()&10+1;
    own->totalSold = 0; 
	for (int i = 0; i < own->numStores; i++) {
		own->storeList[i] = makeStore();
		own->totalSold += own->storeList[i].numSold;
	}
    return own;   
}
 
/*
Creates a store 
Parameters:
Returns:
	store object
*/
Store makeStore(){
    Store shop;
    shop.storeID=rand()%100+1; 
    shop.numCust=rand()%10+1;
    shop.numSold=0;  
	shop.customerList;
    for (int i=0;  i< shop.numCust; i++){
        shop.customerList[i]= makeCustomer();
        shop.numSold+=shop.customerList[i].numTickets; 
    }
    return shop; 
}

/*
Creates a  customer
Parameters:
Returns:
	customer object
*/
Customer makeCustomer() {
	Customer cust;
	cust.custID = rand() % 1000 + 1;
	cust.numTickets = rand() % 20 + 1;
	cust.lotteryNums = new int*[cust.numTickets];
	for (int i = 0; i < cust.numTickets; i++) {
		cust.lotteryNums[i] = new int[3];
		cust.lotteryNums[i][0] = rand() % 10;
		cust.lotteryNums[i][1] = rand() % 10;
		cust.lotteryNums[i][2] = rand() % 10;
		do {
			cust.lotteryNums[i][0] = rand() % 10;
			cust.lotteryNums[i][1] = rand() % 10;
			cust.lotteryNums[i][2] = rand() % 10;
		} while (cust.lotteryNums[i][0] == cust.lotteryNums[i][1] ||
			cust.lotteryNums[i][0] == cust.lotteryNums[i][2] ||
			cust.lotteryNums[i][1] == cust.lotteryNums[i][2]);
		return cust;
	}
}

/*
Takes a list of 0's and modifies it to contain 3 unique numbers between 0-9
Parameters:
	list of 3 0's
Returns:
*/
void getWinners (int winners[]){
	winners[0] = rand() % 10;
	winners[1] = rand() % 10;
	winners[2] = rand() % 10;
	do {
		winners[0] = rand() % 10;
		winners[1] = rand() % 10;
		winners[2] = rand() % 10;
	} while (winners[0] == winners[1] ||
		winners[0] == winners[2] ||
		winners[1] == winners[1]);
}
    

/*
Takes a list of 3 nums and returns matching nums
Parameters:
	list of nums
	winning list
Returns:
	number of matching tickets
*/
int checkWin(int *nums, int *winners) {
	int match = 0;
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (nums[i] == winners[j]) {
				match++;
			}
		}
	}
	return match;
}


/*
Prints information regarding winners, stores, customers and owners
Parameters:
	owner object
	list of 3 winning lottery numbers
Returns:
*/
void findWinners(Owner *owner, int *winner){
    int win;
    for (int s=0;  s < owner->numStores; s++){
        for (int c=0; c< owner->storeList[s].numCust; c++){
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                win = checkWin(owner->storeList[s].customerList[c].lotteryNums[t], owner->storeList[s].numWinners);
                if (win > 0){
                    owner->totalWinners[win-1]++;
                }
            }
        }
        for (int i=0; i<3; i++){
            owner->totalWinners[i]+=owner->storeList[s].numWinners[i];  
            }
    }
    cout << "winning tickets sold: " << (owner->totalWinners[0]+owner->totalWinners[1]+
    owner->totalWinners[2]) << endl; 
    cout << "winning numbers: " << winner[0] << winner[1] << winner[2] << endl;
    
    for (int s=0; s<owner->numStores; s++){
        cout <<"store id: " << owner->storeList[s].storeID << endl; 
        for (int c=0; c<owner->storeList[s].numCust;  c++){  
            cout <<"    customer id: " << owner->storeList[s].customerList[c].custID << endl;
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                if (checkWin(owner->storeList[s].customerList[c].lotteryNums[t], owner->storeList[s].numWinners)>0){
                    cout << "       ticket: " << 
                    owner->storeList[s].customerList[c].lotteryNums[t][0]
                     << owner->storeList[s].customerList[c].lotteryNums[t][1]<<
                     owner->storeList[s].customerList[c].lotteryNums[t][2] <<
                     "      matched: " <<
                     checkWin(owner->storeList[s].customerList[c].lotteryNums[t], owner->storeList[s].numWinners) << endl;
                }
            }
        }
        cout << "total count for store " << owner->storeList[s].storeID << ": "
        << owner->storeList[s].numWinners[0] << " " << owner->storeList[s].numWinners[1] <<
        " "<< owner->storeList[s].numWinners[2] << endl;
    }
}


//check with TA
void cleanUp(Owner *own){
    delete own; 
}
