<<<<<<< HEAD
=======
/*
Lab3main.cc
*/
>>>>>>> 728ed1c5585fae33fa180d0a4bd7d08d1e7084cd
#include <stdio.h>
#include <iostream>
#include "LLNode.hh"
#include "LLHuff.hh"
using namespace std;

int main() {
<<<<<<< HEAD
	/*
	cout << "reading file" << endl;
	LLHuff code("tests.txt");
	code.ReadFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.MakeHuff();
	code.compressFile();
	code.ReadAscii();
	return 0;
	*/
}
=======
    cout << "reading file" << endl;
    LLHuff code("tests.txt");
    cout << "made LLHuff object" << endl; 
    code.ReadFile();
    cout << "read file" << endl; 
    code.pq->printLLPQ();
    cout << "I printed" << endl;  
    code.pq->sortLL();
    cout << "I sorted" << endl; 
    code.pq->printLLPQ();
    code.MakeHuff();
    cout << "I made Huff" << endl; 
    code.pq->printLLPQ();  
    cout << "~~~~~~~" << endl;
    code.compressFile();
    cout << "I compressed the file"<< endl; 
    code.ReadAscii();
    return 0;
}


>>>>>>> 728ed1c5585fae33fa180d0a4bd7d08d1e7084cd
