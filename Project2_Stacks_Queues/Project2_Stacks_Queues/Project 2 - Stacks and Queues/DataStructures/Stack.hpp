#ifndef _STACK_HPP
#define _STACK_HPP

#include "LinkedList.hpp"

//! A LIFO template data structure; inherits from LinkedList
template <typename T>
class Stack : public LinkedList<T>
{
public:
    //! Initializes the Stack
    /**
        Nothing needs to be added in here;
        it will already call the LinkedList's constructor.
    */
	Stack() : LinkedList<T>()
	{
	}

    
	void Push(T& newItem)
	{
		PushBack(newItem);
	}

   
	void Pop()
	{
		PopBack();
	}

   
	T& Top()
	{
		T& top = GetBack();
		return top;
	}
};

#endif
