#pragma once


namespace stack {
	template <class T>
	class Stack {
	private:
		int size_ = 0, capacity_ = 0;
		T *values_;

	public: 
		Stack(int c);
		~Stack();
		bool Push(T value);
		T Pop(void);
		void Print(void);

	};


	// Stack Functions Definitions


	template <class T> Stack<T>::Stack(int c) : capacity(c), size(0) {

		if (capacity_ < 1) throw "Negative Size Stack";

		values_ = new T[capacity_]{}; // Heap memory allocated array
		std::cout << "Stack created with size " << capacity_ << std::endl;
	}

	template <class T> Stack<T>::~Stack() {
		delete[] values_;
		std::cout << "Stack destroyed" << std::endl;
	}

	template <class T> bool Stack<T>::Push(T value) {
		if (size_ == capacity_) return false;

		values_[size_++] = value;
		return true;
	}

	template <class T> T Stack<T>::Pop(void) {
		T value;
		if (size >= 0)
		{
			value = values_[--size_];
		}

		return values_;
	}
	template <class T> void Stack<T>::Print(void) {
		using namespace std;

		// Example: stack: [1, 2, 3,}

		if (size_ == 0) {
			cout << "stack empty" << endl;
			return;
		}	

		//if not empty 

		count << "stack: {";
		for (int i = 0; i < size_; i++) {
			cout << values_[i] << ", ";
		}
		count << value_[size_ -1] << "}" << endl;
	}
}
