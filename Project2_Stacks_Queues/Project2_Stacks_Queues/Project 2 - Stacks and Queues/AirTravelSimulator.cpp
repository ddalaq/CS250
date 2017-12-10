#include "AirTravelSimulator.hpp"

AirTravelSimulator::AirTravelSimulator()
{
	m_timeStamp = 0;
	m_state = WAITING;
}


void AirTravelSimulator::Run()
{
	int maxCapacity;
	cout << "Enter the maximum capacity for the airplane: ";
	cin >> maxCapacity;
	m_airport.SetMaxCapacity(maxCapacity);


    // Display the header (before the main while loop)
	cout << std::left << "TIME \t" << setw(4)
		<< " ID \t" << setw(25)
		<< "NAME" << setw(20)
		<< "ACTION" << setw(10)
		<< " WAIT TIME" << endl;

	while (m_state != FINISHED)
	{
		if (m_state == WAITING)
		{
			m_state = LINEUP;
		}

		 if (m_state == LINEUP)
		{

			if (LineUp() == true)
			{
				m_state = BOARDING;
			}
		}

		 if (m_state == BOARDING)
		{
			if (Board() == true)
			{
				m_state = DISEMBARKING;
			}

		}

		 if (m_state == DISEMBARKING)
		{
			if (Disembark() == true)
			{
				m_state = FINISHED;
			}
		}

		m_timeStamp++;
		m_pplManager.IncreaseWaitingTimes();

	}
	Stats();
}

   
bool AirTravelSimulator::LineUp()
{
	int rIndex = rand() % 1000;
	Traveller* ptrTraveller = m_pplManager.GetTraveller(rIndex);
	m_airport.LineUp(ptrTraveller);

	m_ptrTravellers.PushBack(ptrTraveller);
	ptrTraveller->state = LINEUP;

	DisplayMessage(ptrTraveller, LINEUP);
    return (m_airport.WaitingCount() == m_airport.GetMaxCapacity()); 
}


bool AirTravelSimulator::Board()
{
	Traveller* pT = m_airport.NextInLine();
	m_airplane.Board(pT);

	pT->state = BOARDING;
	DisplayMessage(pT, BOARDING);

    return (m_airport.IsEmpty()); 
}


bool AirTravelSimulator::Disembark()
{
	Traveller* ptrT = m_airplane.Disembark();
	ptrT->state = FINISHED;
	DisplayMessage(ptrT, DISEMBARKING);
    return (m_airplane.IsEmpty());
}

//! Display the statistics on the travellers
/**
    @return <void>
*/
void AirTravelSimulator::Stats()
{
	int totalWeightTime = 0;

	cout << endl << "Passengers..." << endl;
	cout << std::left << setw(30) << "NAME" << setw(20) << "WAIT TIME" << endl;
	for (int i = 0; i < m_ptrTravellers.Size(); i++)
	{
		cout << setw(30) << m_ptrTravellers[i]->name << setw(20) << m_ptrTravellers[i]->waitingTime << endl;
		totalWeightTime += m_ptrTravellers[i]->waitingTime;
	}
	float avgWaitTime = float(totalWeightTime) / float(m_ptrTravellers.Size());

	cout << endl << "Statistics..." << endl;
	cout << "* Total passengers: " << m_ptrTravellers.Size() << endl;
	cout << "* Average wait time: " << avgWaitTime << endl;
}

//! Display updates on each traveller's actions
/**
    @return <void>
*/
void AirTravelSimulator::DisplayMessage(Traveller* ptrPerson, State action)
{
	cout << std::left << "(" << m_timeStamp << ") \t"
		<< setw(4) << " #"
		<< ptrPerson->id << "\t"
		<< setw(25)
		<< ptrPerson->name << setw(20);

	if (action == LINEUP)
	{
		cout << "lines up";
	}
	else if (action == BOARDING)
	{
		cout << "boards";
	}
	else if (action == DISEMBARKING)
	{
		cout << "disembarks";
	}
	cout << setw(10) << " (Wait time: " << ptrPerson->waitingTime << ")" << endl;
}
