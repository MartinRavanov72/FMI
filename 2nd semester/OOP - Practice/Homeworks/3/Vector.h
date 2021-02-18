#pragma once
#include <iostream>

using namespace std;


template <class T>
class  Vector{
private:
	int size;
	int capacity;
	T* buffer;

	int nearestPowerOfTwo(int n){  // Return the nearest(and strictly greater than) number to "n" which is a power of 2..
		return 1ULL << (static_cast<int>(log2(n)) + 1);
	}
	public:
	Vector(){
		this->buffer = nullptr;
		this->size = 0;
		this->capacity = 0;
	}

	Vector(const T* arr, unsigned int length){
		this->buffer = nullptr;
		this->size = 0;
		this->capacity = 0;
		this->reserve(length);
		this->size = length;

		for(int i = 0; i < length; i++){
			this->buffer[i] = arr[i];
		}
	}

	Vector(const Vector<T>& other){
		this->size = other.size;
		this->capacity = other.capacity;
		this->buffer = new T[this->capacity];

		int currentSize = this->size;
		for(int i = 0; i < currentSize; i++){
			this->buffer[i] = other.buffer[i];
		}
	}

	~Vector(){
		delete[] this->buffer;
	}

	Vector<T>& operator=(const Vector<T> & other){
		if(this == &other){
			return *this;
		}

		delete[] this->buffer;

		this->size = other.size;
		this->capacity = other.capacity;
		this->buffer = new T[this->capacity];

		int currentSize = this->size;
		for(int i = 0; i < currentSize; i++){
			this->buffer[i] = other.buffer[i];
		}
			
		return *this;
	}

	T& operator[](unsigned int index){
		return this->getAt(index);
	}

	void reserve(unsigned int newCapacity){
		newCapacity = nearestPowerOfTwo(newCapacity);
		if(newCapacity > this->capacity){
			T* temp = new T[newCapacity];
			int currentSize = this->size;
			for(int i = 0; i < currentSize; i++){
				temp[i] = this->buffer[i];
			}
			
			delete[] this->buffer;
			this->buffer = new T[newCapacity];
			for(int i = 0; i < currentSize; i++){
				this->buffer[i] = temp[i];
			}

			delete[] temp;
			
			this->capacity = newCapacity;
		}
	}

	void resize(unsigned int _size){
		if(_size > this->capacity){
			this->reserve(_size);
		}

		this->size = _size;
	}

	void insertAt(unsigned int pos, const T& val){
		if(pos > this->size){
			this->pushBack(val);
		} else{
			if(this->capacity <= this->size){
				this->reserve(this->size);
			}
			this->size++;

			for(int i = this->size - 1; i > pos; i--){
				this->buffer[i] = this->buffer[i - 1];
			}
			this->buffer[pos] = val;
		}
	}

	T& getAt(unsigned int pos){
		if(pos >= this->size){
			throw out_of_range("Out of range!");
		} else{
			return this->buffer[pos];
		}
	}

	int getCapacity() const{
		return this->capacity;
	}

	int getSize() const{
		return this->size;
	}

	void pushBack(const T &val){
		if(this->capacity <= this->size){
			this->reserve(this->capacity);
		}
			
		this->buffer[this->size++] = val;
	}

	void popBack(){
		if(this->size > 0){
			this->size--;
		}
	}

	void removeAt(unsigned int pos){
		if(pos < size){
			for(int i = pos; i < this->size - 1; i++){
				this->buffer[i] = this->buffer[i + 1];
			}

			this->size--;
		}
	}

	bool empty() const{
		return this->size == 0;
	}

	void clear(){
		delete[] this->buffer;

		this->buffer = nullptr;
		this->size = 0;
		this->capacity = 0;
	}
};