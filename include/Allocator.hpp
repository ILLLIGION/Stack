#include <cstring>

template <typename T>
class Allocator
{
protected:
	Allocator(size_t size = 0);
	~Allocator();
	Allocator(Allocator const&) = delete;

	auto swap (Allocator& other) -> void;
	auto operator = (Allocator const&) -> Allocator& = delete;
	auto allocate() -> void;

	T* ptr_;
	size_t size_;
	size_t count_;
};

template <typename T>
Allocator<T>::Allocator(size_t size)
{
	size_ = size;
	count_ = 0;
	ptr_ = static_cast<T*>(::operator new(size_ * sizeof(T)));
}

template <typename T>
Allocator<T>::~Allocator()
{
	delete [] ptr_;
}

template <typename T>
auto Allocator<T>::swap(Allocator & other) -> void
{
    std::swap(ptr_, other.ptr_);
    std::swap(size_, other.size_);
}

template <typename T>
auto Allocator<T>::allocate() -> void
{
    if (count_ == size_)
    {
        size_t size;
	if (size_ == 0) size = 1;
	else size =  count_ * 2;
        Allocator<T> a(size);
        std::copy(ptr_, ptr_ + count_, a.ptr_);
        swap(a);
    }
}

