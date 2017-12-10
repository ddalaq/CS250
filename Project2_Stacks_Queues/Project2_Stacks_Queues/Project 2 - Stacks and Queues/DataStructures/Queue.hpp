#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include "LinkedList.hpp"

//! A FIFO template data structure; inherits from LinkedList
template <typename T>
class Queue : public LinkedList<T>
{
public:
    //! Initializes the Queue
    /**
        Nothing needs to be added in here;
        it will already call the LinkedList's constructor.
    */
    Queue() : LinkedList<T>()
    {

    }

	void Push(T& newItem)
	{
		PushBack(newItem);
	}

	void Pop()
	{
		PopFront();
	}

   
	T& Front()
	{
		T& front = GetFront();
		return front;
	}
};

#endif
