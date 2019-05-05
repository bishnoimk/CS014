#ifndef stack_h
#define stack_h

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class stack {
	private:
		static const int MAX_SIZE = 20;
		T data[MAX_SIZE];
		int size;
	public:
		stack<T>() {
			size = 0;
		}
		
		void push(T val) {
			try {
				if (size >= MAX_SIZE) {
					throw overflow_error("Called push on full stack.");
				}
				else {
					data[MAX_SIZE - size - 1] = val;
					size += 1;
				}
			} catch (overflow_error &exception) {
				cerr << exception.what() << endl;
				exit(1);
			}
		}
		
		void pop() {
			try {
				if (empty()) {
					throw out_of_range("Called pop on empty stack.");
				}
				else {
					size -= 1;
				}
			} catch (out_of_range &exception) {
				cerr << exception.what() << endl;
				exit(1);
			}
		}
		
		T top() {
			T val;
			try {
				if (size > 0) {
					val = data[MAX_SIZE - size];
				}
				else {
					throw underflow_error("Called top on empty stack.");
				}
			} catch (underflow_error &exception) {
				cerr << exception.what() << endl;
				exit(1);
			}
			return val;
		}
		
		bool empty() {
			return size == 0;
		}
};

#endif