#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrPrev = nullptr;
	m_ptrNext = nullptr;
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;

	m_itemCount = 0;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	while (!IsEmpty())
	{
		PopFront();
		PopBack();
	}
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	

	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else if (!IsEmpty())
	{
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
	}
	m_itemCount++;
}

void LinkedList::PushBack( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	

	if (IsEmpty())
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	else if (!IsEmpty())
	{
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
	}
	m_itemCount++;
}

void LinkedList::PopFront() noexcept
{
	if (IsEmpty())
	{
		return;
	}

	else if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecond = m_ptrFirst->m_ptrNext;
		ptrSecond->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}
}

void LinkedList::PopBack() noexcept
{
	if (IsEmpty())
	{
		return;
	}

	else if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
		ptrSecondToLast->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = ptrSecondToLast;
		m_itemCount--;
	}
}

CustomerData LinkedList::GetFront()
{
	if (IsEmpty())
	{
		throw logic_error("list is empty");
	}
	else
	return m_ptrFirst->m_data;
}

CustomerData LinkedList::GetBack()
{
	if (IsEmpty())
	{
		throw logic_error("list is empty");
	}
	else
	return m_ptrLast->m_data;
}

CustomerData& LinkedList::operator[]( const int index )
{
	int Counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("That index is invalid");
	}
	else
	{
		while (Counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			Counter++;
		}
	}
	return ptrCurrent->m_data;

  
}

bool LinkedList::IsEmpty()
{
	return (m_itemCount == 0);
}

int LinkedList::Size()
{
	return m_itemCount;
}

