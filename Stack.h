//Stack.h
#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_
#include <iostream>
#include <exception>
#include "Array.h"

template <typename T>
class Stack
{
public:
	typedef T type;

	class empty_exception: public std::exception
	{
	public:
		empty_exception(void)
		:std::exception()
		{
			std::cout<<"Stack is empty"<<std::endl;
		}
		empty_exception(const char * msg)
		:std::exception(msg){
			std::cout<<"Stack is empty Error Code: "<<std::endl;
		}
	};
	Stack (void);
	Stack(const Stack & s);
	~Stack(void);
	const Stack & operator = (const Stack & rhs);
	void push(T element);
	void pop(void);
	T top(void) const;
	bool is_empty(void) const;
	size_t size(void) const;
	void clear(void);
private:
	Array<T> st;
	int cur_size;
};

#include "Stack.inl"
#include "Stack.cpp"

#endif
