#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

namespace Kiseshi {
	template <typename T>
	class PriorityQueue {
	private:
		std::vector<T> heap;

		// 上浮操作，保证父节点比子节点小
		void heapifyUp(int index) {
			while (index > 0) {
				// 计算父节点索引
				int parent = (index - 1) / 2;
				// 如果父节点大于子节点，则交换它们
				if (heap[parent] > heap[index]) {
					std::swap(heap[parent], heap[index]);
					// 继续向上检查
					index = parent;
				} 
				else {
					// 如果父节点不大于子节点，堆性质满足，退出循环
					break;
				}
			}
		}

		// 下沉操作，保证父节点比子节点小
		void heapifyDown(int index) {
			int size = heap.size();
			while (index < size) {
				// 计算左子节点索引
				int leftChild = 2 * index + 1;
				// 计算右子节点索引
				int rightChild = 2 * index + 2;
				int smallest = index;

				// 在左右子节点中找到最小的节点
				if (leftChild < size && heap[leftChild] < heap[smallest]) {
					smallest = leftChild;
				}

				if (rightChild < size && heap[rightChild] < heap[smallest]) {
					smallest = rightChild;
				}

				if (smallest != index) {
					// 如果最小节点不是当前节点，交换它们
					std::swap(heap[index], heap[smallest]);
					// 继续向下检查
					index = smallest;
				}
				else {
					break;
				}
			}
		}

	public:
		void push(const T& value) {
			// 将元素添加到堆的末尾
			heap.push_back(value);
			// 从末尾元素开始执行上浮
			heapifyUp(heap.size() - 1);
		}

		void pop() {
			if (!empty()) {
				// 将堆顶元素与最后一个元素交换
				std::swap(heap[0], heap.back());
				// 弹出最后一个元素
				heap.pop_back();
				// 从新的堆顶元素开始执行下沉操作
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