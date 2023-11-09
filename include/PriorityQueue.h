#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

namespace Kiseshi {
	template <typename T>
	class PriorityQueue {
	private:
		std::vector<T> heap;

		// �ϸ���������֤���ڵ���ӽڵ�С
		void heapifyUp(int index) {
			while (index > 0) {
				// ���㸸�ڵ�����
				int parent = (index - 1) / 2;
				// ������ڵ�����ӽڵ㣬�򽻻�����
				if (heap[parent] > heap[index]) {
					std::swap(heap[parent], heap[index]);
					// �������ϼ��
					index = parent;
				} 
				else {
					// ������ڵ㲻�����ӽڵ㣬���������㣬�˳�ѭ��
					break;
				}
			}
		}

		// �³���������֤���ڵ���ӽڵ�С
		void heapifyDown(int index) {
			int size = heap.size();
			while (index < size) {
				// �������ӽڵ�����
				int leftChild = 2 * index + 1;
				// �������ӽڵ�����
				int rightChild = 2 * index + 2;
				int smallest = index;

				// �������ӽڵ����ҵ���С�Ľڵ�
				if (leftChild < size && heap[leftChild] < heap[smallest]) {
					smallest = leftChild;
				}

				if (rightChild < size && heap[rightChild] < heap[smallest]) {
					smallest = rightChild;
				}

				if (smallest != index) {
					// �����С�ڵ㲻�ǵ�ǰ�ڵ㣬��������
					std::swap(heap[index], heap[smallest]);
					// �������¼��
					index = smallest;
				}
				else {
					break;
				}
			}
		}

	public:
		void push(const T& value) {
			// ��Ԫ����ӵ��ѵ�ĩβ
			heap.push_back(value);
			// ��ĩβԪ�ؿ�ʼִ���ϸ�
			heapifyUp(heap.size() - 1);
		}

		void pop() {
			if (!empty()) {
				// ���Ѷ�Ԫ�������һ��Ԫ�ؽ���
				std::swap(heap[0], heap.back());
				// �������һ��Ԫ��
				heap.pop_back();
				// ���µĶѶ�Ԫ�ؿ�ʼִ���³�����
				heapifyDown(0);
			}
		}

		T top() {
			if (!empty()) {
				return heap[0];
			}
			else {
				return T();
			}
		}

		bool empty() const {
			return heap.empty();
		}

		size_t getSize() const {
			return heap.size();
		}
	};
}

#endif PRIORITY_QUEUE_H