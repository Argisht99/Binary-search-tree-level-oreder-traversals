#include"BST.h"


int main()
{
	bst<int> A;
	
	A.insert(15);
	A.insert(10);
	A.insert(20);
	A.insert(9);
	A.insert(11);
	A.insert(22);
	A.insert(17);
	A.printlevelorder();
	//A.printpostorder();
	//std::cout<<A.find(22)<<std::endl;
	A.remove(15);
	std::cout << std::endl;

	A.printlevelorder();

	//A.printlevelorder();
	//A.printpostorder();
	//A.printpreorder();
	//A.printinorder();
	return 0;
}