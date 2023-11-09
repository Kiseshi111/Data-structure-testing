#ifndef ARRAY_H
#define ARRAY_H

namespace Kiseshi {
	template <typename T>
	class Array {
	private:
		T* arrayData;

		// 使用size_t，防止长度/容量为负
		size_t arraySize;
		size_t arrayCapacity;

	public:
		Array() :
			arrayData(nullptr),
			arraySize(0),
			arrayCapacity(0) {}

		Array(size_t initialCapacity) :
			arraySize(0),
			arrayCapacity(initialCapacity)
		{
			arrayData = new T[initialCapacity];
		}

		T& operator[](size_t index) {
			return arrayData[index];
		}

		T& operator=(const Array& other) {
			if (this != &other) {
				// 释放原有的内存
				delete[] arrayData;

				// 复制容量
				arrayCapacity = other.arrayCapacity;

				// 分配新的内存并复制元素
				arrayData = new T[arrayCapacity];
				for (size_t i = 0; i < other.arraySize; ++i) {
					arrayData[i] = other.arrayData[i];
				}

				// 复制数组大小
				arraySize = other.arraySize;
			}
			return *this;
		}

		T& front() {
			if (arraySize > 0) {
				return arrayData[0];
			}
			else {
				// T是模板参数，代表数组中存储的元素的类型
				// 调用 T 类型的默认构造函数并返回一个对象
				return T();
			}
		}

		T& back() {
			if (arraySize > 0) {
				return arrayData[arraySize - 1];
			}
			else {
				return T();
			}
		}

		size_t getSize() const {
			return arraySize;
		};

		void push_back(const T& value) {
			if (arraySize == arrayCapacity) {
				// 扩展数组容量
				if (arrayCapacity == 0) {
					arrayCapacity = 1;
				}
				else {
					arrayCapacity *= 2;
				}

				T* newData = new T[arrayCapacity];
				for (int i = 0; i < arraySize; ++i) {
					newData[i] = arrayData[i];
				}
				delete[] arrayData;
				arrayData = newData;
			}

			arrayData[arraySize] = value;
			arraySize++;
		}
		
		~Array() {
			delete[] arrayData;
		}
	};
}

#endif ARRAY_H