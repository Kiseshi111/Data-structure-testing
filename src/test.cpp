#include <iostream>
#include "../include/Array.h"
#include "../include/LinkedList.h"
#include "../include/PriorityQueue.h"
#include "../include/BinaryTree.h"
#include "../include/Logger.h"

using namespace std;

int main() {

#if 0
	Kiseshi::Array<int> myarr(3);
	myarr.push_back(1);
	myarr.push_back(2);
	myarr.push_back(3);

	for (int i = 0; i < myarr.getSize(); ++i) {
		LOG_INFO("%d", myarr[i]);
	}


	Kiseshi::LinkedList<int> mylist;
	mylist.insert(4);
	mylist.insert(5);
	mylist.insert(6);

	mylist.print();


	Kiseshi::PriorityQueue<int> mypq;
	mypq.push(3);
	mypq.push(1);
	mypq.push(4);
	mypq.push(1);
	mypq.push(5);

	while (!mypq.empty()) {
		LOG_INFO("%d ", mypq.top());
		mypq.pop();
	}

#endif

	Kiseshi::BinaryTree<int> mytree;
	mytree.insert(5);
	mytree.insert(3);
	mytree.insert(8);
	mytree.insert(2);
	mytree.insert(4);
	mytree.insert(7);
	mytree.insert(9);

	mytree.traversal();

	int searchValue = 4;
	if (mytree.search(searchValue)) {
		LOG_INFO("found");
	}
	else {
		LOG_INFO("not found");
	}


	return 0;
}