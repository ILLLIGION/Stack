#include <exception>
#include <cstring>
#include <iostream>
#include <exception>

struct l_error : public std::logic_error
{
public:
	l_error(const std::string& data): logic_error(data) {}
};

template <typename T>
class Stack
{
public:
	Stack(): array_(nullptr), array_size_(0), count_(0) {}
	size_t count() const
	{
		return count_;
	}
	void push(T const& elem_)
	{
		if (count_ == array_size_)
		{
			if (array_size_ == 0) array_size_ = 1;
			else array_size_*=2;
			T* new_array_ = new T[array_size_];
			for (int i=0; i<count_; i++)
			{
				new_array_[i] = array_[i];
			}
			delete[] array_;
			array_ = new_array_; 
		}
		array_[++count_] = elem_;
	}	
	T pop()
	{
		if(count_) return array_[count_--];
		if(count_ == 0) throw l_error("stack is empty"); 
	}
	~Stack()
	{
		delete[] array_;
	}
private:
	T* array_;
	size_t array_size_;
	size_t count_;
};
