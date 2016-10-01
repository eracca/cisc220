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

Customer makeCustomer(){
    int r; 
    Customer cust;
    cust.custID=rand()%1000+1;
    cust.numTickets=rand()%20+1;
    cust.lotteryNums = new int*[cust.numTickets];
    for (int i=0; i< cust.numTickets; i++){
        cust.lotteryNums[i]=new int[3];
        cust.lotteryNums[i][0]=rand()%10;
        r =rand()%10;
        do{
            r =rand()%10; 
        } while (r ==cust.lotteryNums[i][0]);
        cust.lotteryNums[i][1]=rand()%10;
        do{
            r =rand()%10;
        } while (r ==cust.lotteryNums[i][0] ||
         r ==cust.lotteryNums[i][1]);
        cust.lotteryNums[i][2]=rand; 
        
    }
    return cust;
}

void getWinners (int winners[]){
	winners[0] = rand() % 10;
	winners[1] = rand() % 10;
	winners[2] = rand() % 10;
	do {
		winners[0] = rand() % 10;
		winners[1] = rand() % 10;
		winners[2] = rand() % 10;
	}
	while(winners[0] == winners[1] ||
		  winners[0] == winners[2] ||
		  winners[1] == winners[1])
}
    

void findWinners(Owner *owner, int *ls) {
	for (int s=0; s < owner.numStores; s++) {
		for (int c=0; c < owner.storeList[s].numCust; c++) {
			for (int t = 0; t < owner.storeList[s].customerList[c].numTickets; t++) {
				cout << checkwin(owner.StoreList[s].customerList[c].lotteryNums, getWinners(winner[3])) << endl;
				cout << getWinners[3] << endl;
				cout << owner.StoreList[s].storeID << endl;
				cout << owner.StoreList[s].customerList[c].custID << endl;
			}
		}
	}


}

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
