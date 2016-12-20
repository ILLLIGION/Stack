#include <iostream>
#include <stdexcept>
#include <Allocator.hpp>

template <typename T>
class Stack: private Allocator<T>
{
public:
	Stack(size_t size = 0);
	auto count() const noexcept -> size_t;
	auto push(T const& elem_) noexcept -> void;
	auto pop() noexcept -> void;
	auto top() const /*strong*/ -> T;
	auto empty() const noexcept -> bool;
};

template <typename T>
Stack<T>::Stack(size_t size) : Allocator<T>(size) {}

template <typename T>
auto Stack<T>::count() const noexcept -> size_t
{
    return Allocator<T>::count_;
}

template <typename T>
auto Stack<T>::push(const T & element) noexcept -> void
{
    try
    {
        Allocator<T>::allocate();
        Allocator<T>::ptr_[Allocator<T>::count_] = element;
        Allocator<T>::count_++;
    }
    catch (...) {}
}

template <typename T>
auto Stack<T>::pop() noexcept -> void
{
    if (Allocator<T>::count_)
        Allocator<T>::count_--;
}

template <typename T>
auto Stack<T>::top() const /* strong */ -> T
{
    if (Allocator<T>::count_)
        return Allocator<T>::ptr_[Allocator<T>::count_ - 1];
    else
        throw std::underflow_error("Stack is already empty.");
}

template <typename T>
auto Stack<T>::empty() const noexcept -> bool
{
    return !Allocator<T>::count_;
}

