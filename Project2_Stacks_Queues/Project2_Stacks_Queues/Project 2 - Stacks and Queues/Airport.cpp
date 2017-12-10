#include "Airport.hpp"


void Airport::LineUp(Traveller* traveller)
{
	ptrQTraveller.PushBack(traveller);
}


Traveller* Airport::NextInLine()
{
	Traveller * frontQ = ptrQTraveller.Front();
	ptrQTraveller.PopFront();
	return frontQ;
}


bool Airport::IsEmpty()
{
	return (ptrQTraveller.Size() == 0);
}

int Airport::WaitingCount()
{
    return ptrQTraveller.Size(); 
}

void Airport::SetMaxCapacity(int size)
{
	m_maxCapacity = size;
}

int Airport::GetMaxCapacity()
{
    return m_maxCapacity;
}
