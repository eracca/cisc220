#include <time.h>
#include <stdlib.h>
#include "lab2lottery.hh"
#include "lab2lottery.cc"

using namespace std; 

int main() {
    srand(time(NULL));
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
