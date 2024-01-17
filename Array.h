//Array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>                                                         
#include <stdexcept>

template <typename T>
class Array{
public:
	typedef T type;

	Array(void);
	Array(size_t length);
	Array(size_t length, T fill);
	Array(const Array & arr);
	~Array(void);
	const Array & operator = (const Array & rhs);
	size_t size(void) const;
	size_t max_size(void) const;
	T & operator [] (size_t index);
	const T & operator [] (size_t index) const;
	T get (size_t index) const;
	void set (size_t index,T value);
	void resize(size_t new_size);
	int find(T element) const;
	int find(T element, size_t start) const;
	bool operator == (const Array & rhs) const;
	bool operator !=(const Array & rhs) const;
	void fill(T element);
private:
	T * data_;
	size_t cur_size_;
	size_t max_size_;
};

#include "Array.inl"
#include "Array.cpp"

#endif

