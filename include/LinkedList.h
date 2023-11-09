#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

namespace Kiseshi {
	template <typename T>
	class Node {
	public:
		T linkedListData;
		Node* next;

		Node(const T& value) : 
			linkedListData(value), 
			next(nullptr) {}
	};

	template <typename T> 
	class LinkedList {
	private:
		Node<T>* linkedListHead;

	public:
		LinkedList() : 
			linkedListHead(nullptr) {}

		void insert(const T& value) {
			Node<T>* newNode = new Node<T>(value);
			if (!linkedListHead) {
				linkedListHead = newNode;
			}
			else {
				Node<T>* current = linkedListHead;
				while (current->next) {
					current = current->next;
				}
				current->next = newNode;
			}
		}

		void print() {
			Node<T>* current = linkedListHead;
			while (current) {
				std::cout << current->linkedListData << " -> ";
				current = current->next;
			}
			std::cout << "nullptr" << std::endl;
		}

		~LinkedList() {
			while (linkedListHead) {
				Node<T>* temp = linkedListHead;
				linkedListHead = linkedListHead->next;
				delete temp;
			}
		}
	};
}

#endif LINKED_LIST_H