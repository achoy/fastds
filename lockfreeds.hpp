#pragma once

// working for C++ 17

#include <memory>
#include <experimental/atomic>

template<typename T>
class lock_free_stack
{
private:
	
	struct node
	{
		std::shared_ptr<T> data;
		std::experimental::atomic_shared_ptr<node> next;
		node(T const& data_):
			data(std::make_shared<T>(data_))
		{}
	};

	std::experimental::atomic_shared_ptr<node> head;

public:

	void push(T const& data);
	std::shared_ptr<T> pop();
	~lock_free_stack();
};