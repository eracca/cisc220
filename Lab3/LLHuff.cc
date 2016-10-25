/*LLHuff.cc
*/

#include "LLHuff.hh"
#include "LLPQ.hh"
#include "LLNode.hh"

LLHuff::LLHuff(string f) {
	file = f;
	pq = new LLPQ();
}

LLHuff::~LLHuff() {
	//
}

LLHuff::MakeHuff() {
	while (pq.size > 0) {
		LLNode *leftChild = pq.remFirst();
		LLNode *rightChild = pq.remFirst();
		LLNode *parent = new LLNode("*");
		parent->count = leftChild->count + rightChild->count;
		parent->left = leftChild;
		parent->right = rightChild;
		pq.insertInOrder(parent);
	}
	root = pq->first;
}

LLHuff::FindCode() {
	delete pq;
	pq = new LLPQ();
	HelpFindCode(root, "");
}

LLHuff::HelpFindCode(LLNode *root, string path) {
	//check with TA or Dr. Y 
	if (root == NULL) {
		return;
	}
	HelpFindCode(root->left, path + "0");
	root->code = path;
	if (root->data != "*") {
		pq.insertInOrder(root);
	}
	HelpFindcode(root->right, path + "1");
}

LLHuff::ReadFile() {
	ifstream infile(file.c_str(), ios::in); // open file
	char k;
	while (infile.get(k)) { // loop getting single characters
		pq->insertUnique(k);// inserting the character k into the priority queue
	}
	infile.close();
}

LLHuff::compressFile() {

	ReadFile();
	MakeHuff();
	ofstream outfile(“compressed.txt”, ios::out);


}

void LLHuff::ReadAscii() {
	cout << file << endl;
	ifstream infile("asciitable.txt", ios::in); // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}
	infile >> asciicode;
	pq->addFirst(' ', asciicode);
	infile >> asciicode;
	while (infile >> ch) { // loop getting single characters
		cout << ch;
		infile >> asciicode; // gets entire word (code)
		cout << asciicode << endl;
		pq->addAtFirst(ch, asciicode);
	}
	cout << endl;
	infile.close();
	/////////////////////////////////////
	ifstream infile2(file.c_str(), ios::in); // open file for reading
	ofstream outfile("asciivsn.txt", ios::out);
	char k;
	string comp;
	while (infile2.get(k)) { // loop getting single characters
		cout << k;
		comp = pq->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		}
		else {
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}
	}
	cout << endl;
	infile2.close();
	outfile.close();
}