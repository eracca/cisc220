#include "lab2lottery.hh"
<<<<<<< HEAD
#include <cstdlib>
#include <iostream>

=======
#include <iostream>
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4

using namespace std;

/*
Creates a new owner
Parameters:
Returns:
	new owner object
*/
Owner *makeOwner(){    
<<<<<<< HEAD
    Owner *own = new Owner;  
    own->numStores= rand()&10+1;
    own->totalSold = 0; 
	for (int i = 0; i < own->numStores; i++) {
		own->storeList[i] = makeStore();
		own->totalSold += own->storeList[i].numSold;
	}
=======
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
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
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
    for (int n=0;  n<3; n++){
        shop.numWinners[n]=0; 
    }
    shop.storeID=rand()%100+1; 
    shop.numCust=rand()%10+1;
<<<<<<< HEAD
    shop.numSold=0;  
	shop.customerList;
=======
    shop.numSold=0;   
    shop.customerList = new Customer[shop.numCust]; 
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
    for (int i=0;  i< shop.numCust; i++){
        shop.customerList[i]= makeCustomer();
        shop.numSold+=shop.customerList[i].numTickets; 
    }
    return shop; 
}

<<<<<<< HEAD
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
=======
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
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
	winners[0] = rand() % 10;
	winners[1] = rand() % 10;
	winners[2] = rand() % 10;
	do {
		winners[0] = rand() % 10;
		winners[1] = rand() % 10;
		winners[2] = rand() % 10;
<<<<<<< HEAD
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
=======
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
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
}


/*
Prints information regarding winners, stores, customers and owners
Parameters:
	owner object
	list of 3 winning lottery numbers
Returns:
*/
void findWinners(Owner *owner, int *winner){
    //find winners, update totalWinners 
    int win;
<<<<<<< HEAD
    for (int s=0;  s < owner->numStores; s++){
        for (int c=0; c< owner->storeList[s].numCust; c++){
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                win = checkWin(owner->storeList[s].customerList[c].lotteryNums[t], owner->storeList[s].numWinners);
                if (win > 0){
                    owner->totalWinners[win-1]++;
=======
    for (int s=0;  s<owner->numStores; s++){
        for (int c=0; c< owner->storeList[s].numCust; c++){
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
                win=checkWin(owner->storeList[s].customerList[c].lotteryNums[t],
                            winner);
                if (win > 0){
                    owner->storeList[s].numWinners[win-1]++;
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
                }
            }
        }
        for (int i=0; i<3; i++){
            owner->totalWinners[i]+=owner->storeList[s].numWinners[i];  
            }
    }
<<<<<<< HEAD
=======

    //print all the required output
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
    cout << "winning tickets sold: " << (owner->totalWinners[0]+owner->totalWinners[1]+
    owner->totalWinners[2]) << endl; 
    cout << "winning numbers: " << winner[0] << winner[1] << winner[2] << endl;
    
    for (int s=0; s<owner->numStores; s++){
        cout <<"store id: " << owner->storeList[s].storeID << endl; 
        for (int c=0; c<owner->storeList[s].numCust;  c++){  
            cout <<"    customer id: " << owner->storeList[s].customerList[c].custID << endl;
            for (int t=0; t< owner->storeList[s].customerList[c].numTickets; t++){
<<<<<<< HEAD
                if (checkWin(owner->storeList[s].customerList[c].lotteryNums[t], owner->storeList[s].numWinners)>0){
=======
                if (checkWin(owner->storeList[s].customerList[c].lotteryNums[t],
                    winner)>0){
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
                    cout << "       ticket: " << 
                    owner->storeList[s].customerList[c].lotteryNums[t][0]
                     << owner->storeList[s].customerList[c].lotteryNums[t][1]<<
                     owner->storeList[s].customerList[c].lotteryNums[t][2] <<
                     "      matched: " <<
<<<<<<< HEAD
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
=======
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
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
}
