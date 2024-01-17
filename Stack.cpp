//Stack.cpp
#include <stdexcept>
template <typename T>
Stack <T>::Stack (void)
	:st(Array<T>(0)),cur_size(0)
{

}

template <typename T>
Stack <T>::Stack(const Stack & stack)
	:st(Array<T>(stack.size())),cur_size(stack.size())
{
	T arr[stack.size()];
	for(int i = 0; i < stack.size(); i++){
		arr[i] = stack.top();
		stack.pop();
	}
	for(int j = 0; j < cur_size; j++){
		st.set(j,arr[cur_size - 1 -j]);
	}
}

template <typename T>
Stack <T>::~Stack(void)
{

}

template <typename T>
void Stack <T>::push (T element)
{
	st.resize(cur_size + 1);
	st.set(cur_size,element);
	cur_size++;
}

template <typename T>
void Stack <T>::pop(void)
{
	if(cur_size == 0){
		throw std::runtime_error("Empty Stack");
	}
	else{
		st.resize(cur_size - 1);
		cur_size--;
	}
}

template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(rhs->size() == cur_size){
		for(int i = cur_size - 1; i >=0; i--){
			if(st.get(i) == rhs.top()){
				rhs.pop();
			}
			else{
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}

template <typename T>
void Stack <T>::clear (void)
{
	st.resize(0);
	cur_size = 0;
}
