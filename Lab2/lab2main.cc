#include <time.h>
#include <stdlib.h>
#include "lab2lottery.hh"
<<<<<<< HEAD
#include "lab2lottery.cc"
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> bdcb1ba13a9908966e07e546a0a2834789093fa4
=======
#include  <iostream>
>>>>>>> 728ed1c5585fae33fa180d0a4bd7d08d1e7084cd

using namespace std; 
int main() {
    srand((unsigned int)time(NULL));
    Owner *me= makeOwner();
    int winners[3] = {0,0,0};
    getWinners (winners);
    for (int i = 0; i < 3; i++) {
        cout << winners[i] << endl;
    }
    findWinners(me, winners);
    cout << "won with 1 number: "<< me->totalWinners[0] << endl;
    cout << "won with 2 numbers: " << me->totalWinners[1] << endl;
    cout << "won with 3 numbers: " << me->totalWinners[2] << endl;
    //cout << x << endl;
    cleanUp(me); 
    return 0;
} //main
