#include "Airplane.hpp"


void Airplane::Board(Traveller* traveller)
{
	ptrSTraveller.Push(traveller);
}

Traveller* Airplane::Disembark()
{
	Traveller * topS = ptrSTraveller.Top();
	ptrSTraveller.Pop();
	return topS;
}

bool Airplane::IsEmpty()
{
	return (ptrSTraveller.Size() == 0);
}

