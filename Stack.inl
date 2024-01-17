//Stack.inl
#include <stdexcept>
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return cur_size;
}

template <typename T>
inline
T Stack <T>::top (void) const
{
	if(cur_size == 0){
		throw std::runtime_error("Empty Stack");
	}
	return st[cur_size - 1];
}

template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if(cur_size == 0){
		return true;
	}else{
		return false;
	}
}
