#include "lab3_SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

int SmartStaticArray::Size() const
{
        return m_itemCount; 
}

bool SmartStaticArray::IsFull() const
{
	
	return (m_itemCount == MAX_SIZE);
        //return false; // placeholder
}

bool SmartStaticArray::IsEmpty() const
{
	return(m_itemCount == 0);               // returns true if m_itemCount == 0, and false if it is not
}

string SmartStaticArray::Get( int index ) const
{
	if (index < 0 || index > m_itemCount)
	{
		throw out_of_range("Cannot get at index-out of range");
	}
	else
	return m_data[index];
}

void SmartStaticArray::Pop()
{
	if (m_itemCount > 0)
	{
		m_itemCount--;

	}
}

void SmartStaticArray::ShiftRight( int index ) noexcept
{
	for (int i = m_itemCount; i > index; i--)
	{
		m_data[i] = m_data[i - 1];
	}
}

void SmartStaticArray::ShiftLeft( int index ) noexcept
{
	for (int i = index; i < m_itemCount - 1; i++)
	{
		m_data[i] = m_data[i + 1];
	}
}

void SmartStaticArray::Push( const string& newItem )
{
	if (m_itemCount == IsFull())
	{
		throw length_error("Cannot add new item-array is full!");
	}
	else
	{
		m_data[m_itemCount] = newItem;
		m_itemCount++;
	}
}

void SmartStaticArray::Insert( int index, const string& newItem )
{
	if (index < 0 || index >= MAX_SIZE)
	{
		throw out_of_range("Cannot insert at index-out of range");
	}
	else if (m_itemCount == IsFull())
	{
		throw length_error("Cannot insert new item-array is full!");
	}
	else if (index > m_itemCount)
	{
		throw out_of_range("Cannot insert at index - must be contiguous!");
	}
	else 
	{
		ShiftRight(index);
		m_data[index] = newItem;
		m_itemCount++;
	}


}

void SmartStaticArray::Extend( const SmartStaticArray& other )
{
	if ((m_itemCount + other.m_itemCount) >= MAX_SIZE)
	{
		throw length_error("Cannot append second list - will go out of bounds of array!");
	}
	else
		for (int i = 0; i < other.m_itemCount; i++)
		{
			Push(other.Get(i));
		}
}

void SmartStaticArray::Remove( int index )
{
	if (index < 0 || index >= m_itemCount)
	{
		throw out_of_range("Cannot insert at index - out of range");
	}
	else
		ShiftLeft(index);
	m_itemCount--;
}

SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
        for ( int i = 0; i < other.m_itemCount; i++ )
        {
        m_data[i] = other.m_data[i];
        m_itemCount++;
        }

        return *this;
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
        if ( m_itemCount != other.m_itemCount )
        {
        return false;
        }

        for ( int i = 0; i < m_itemCount; i++ )
        {
        if ( m_data[i] != other.m_data[i] )
        {
            return false;
        }
        }

        return true;
}

bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
        return !( *this == other );
}

string SmartStaticArray::operator[]( int index )
{
    return Get( index );
}
