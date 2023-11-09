#ifndef ARRAY_H
#define ARRAY_H

namespace Kiseshi {
	template <typename T>
	class Array {
	private:
		T* arrayData;

		// ʹ��size_t����ֹ����/����Ϊ��
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
				// �ͷ�ԭ�е��ڴ�
				delete[] arrayData;

				// ��������
				arrayCapacity = other.arrayCapacity;

				// �����µ��ڴ沢����Ԫ��
				arrayData = new T[arrayCapacity];
				for (size_t i = 0; i < other.arraySize; ++i) {
					arrayData[i] = other.arrayData[i];
				}

				// ���������С
				arraySize = other.arraySize;
			}
			return *this;
		}

		T& front() {
			if (arraySize > 0) {
				return arrayData[0];
			}
			else {
				// T��ģ����������������д洢��Ԫ�ص�����
				// ���� T ���͵�Ĭ�Ϲ��캯��������һ������
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
				// ��չ��������
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