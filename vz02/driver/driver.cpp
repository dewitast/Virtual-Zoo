/**	@file driver.cpp
  */

#include "driver.h"
#include <fstream>
#include <iostream>
using namespace std;

Driver::Driver() : P(-1,-1)
{
	ifstream myfile;
	myfile.open("map.txt");
	myfile >> Z;
	myfile.close();
	visited = new bool*[Z.GetBeff()];
	for (int i=0;i<Z.GetBeff();++i)
	{
		visited[i] = new bool[Z.GetKeff()];
		for (int j=0;j<Z.GetKeff();++j)
			visited[i][j] = false;
	}
	Z.ReadAnimal();
}

void Driver::DisplayZoo()
{
	for (int i=0;i<Z.GetJumlahCage();++i)
		Z.GetCage(i).Move();
	cout << Z;
}

void Driver::GetExperience()
{
	Point P1;
	if (P.GetAbsis()>0)
	{
		P1.SetAbsis(P.GetAbsis()-1);
		P1.SetOrdinat(P.GetOrdinat());
		if ((Z.GetElement(P1)).IsHabitat())
			(Z.SearchPoint(P1)).Interact();
	}
	if (P.GetAbsis()<Z.GetBeff()-1)
	{
		P1.SetAbsis(P.GetAbsis()+1);
		P1.SetOrdinat(P.GetOrdinat());
		if ((Z.GetElement(P1)).IsHabitat())
			(Z.SearchPoint(P1)).Interact();
	}
	if (P.GetOrdinat()>0)
	{
		P1.SetAbsis(P.GetAbsis());
		P1.SetOrdinat(P.GetOrdinat()-1);
		if ((Z.GetElement(P1)).IsHabitat())
			(Z.SearchPoint(P1)).Interact();
	}
	if (P.GetAbsis()<Z.GetKeff()-1)
	{
		P1.SetAbsis(P.GetAbsis());
		P1.SetOrdinat(P.GetOrdinat()+1);
		if ((Z.GetElement(P1)).IsHabitat())
			(Z.SearchPoint(P1)).Interact();
	}
}

void Driver::TourZoo()
{
	for (int i=0;i<Z.GetJumlahCage();++i)
		Z.GetCage(i).Move();
	int random;
	bool found = false;
	if ((P.GetAbsis()==-1)&&(P.GetOrdinat()==-1))
	{
		cout << "Welcome to the zoo." << endl;
		while (!found)
		{
			for (int i=0;i<Z.GetBeff();++i)
				for (int j=0;j<Z.GetKeff();++j)
					visited[i][j] = false;
			random = rand() % Z.GetBeff();
			if ((Z.GetElement(0,random)).IsEntrance()) 
			{
				found = true;
				P.SetAbsis(0);
				P.SetOrdinat(random);
			}
			else if ((Z.GetElement(Z.GetBeff()-1,random)).IsEntrance()) 
			{
				found = true;
				P.SetAbsis(Z.GetBeff()-1);
				P.SetOrdinat(random);
			}	
			if (!found)
			{
				random = rand() % Z.GetKeff();
				if ((Z.GetElement(random,0)).IsEntrance()) 
				{
					found = true;
					P.SetAbsis(random);
					P.SetOrdinat(0);
				}
				else if ((Z.GetElement(random,Z.GetKeff()-1)).IsEntrance()) 
				{
					found = true;
					P.SetAbsis(random);
					P.SetOrdinat(Z.GetKeff()-1);
				}
			}
		}
	}
	else
	{
		visited[P.GetAbsis()][P.GetOrdinat()] = true;
		bool b1 = ((P.GetAbsis()>0)&&(!visited[P.GetAbsis()-1][P.GetOrdinat()])&&((Z.GetElement(P.GetAbsis()-1,P.GetOrdinat()))).IsRoad());
		bool b2 = ((P.GetOrdinat()<Z.GetKeff()-1)&&(!visited[P.GetAbsis()][P.GetOrdinat()+1])&&((Z.GetElement(P.GetAbsis(),P.GetOrdinat()+1))).IsRoad());
		bool b3 = ((P.GetAbsis()<Z.GetBeff()-1)&&(!visited[P.GetAbsis()+1][P.GetOrdinat()])&&((Z.GetElement(P.GetAbsis()+1,P.GetOrdinat()))).IsRoad());
		bool b4 = ((P.GetOrdinat()>0)&&(!visited[P.GetAbsis()][P.GetOrdinat()-1])&&((Z.GetElement(P.GetAbsis(),P.GetOrdinat()-1))).IsRoad());
		if ((!b1)&&(!b2)&&(!b3)&&(!b4))
		{
			P.SetAbsis(-1);
			P.SetOrdinat(-1);
			return;
		}
		while (!found)
		{
			random = rand() % 4;
			if (random==0)
			{
				if (b1)
				{
					found = true;
					P.SetAbsis(P.GetAbsis()-1);
				}	
			}
			else if (random==1)
			{
				if (b2)
				{
					found = true;
					P.SetOrdinat(P.GetOrdinat()+1);
				}		
			}
			else if (random==2)
			{
				if (b3)
				{
					found = true;
					P.SetAbsis(P.GetAbsis()+1);
				}	
			}
			else if (random==3)
			{
				if (b4)
				{
					found = true;
					P.SetOrdinat(P.GetOrdinat()-1);
				}	
			}
		}
		GetExperience();
		if ((Z.GetElement(P)).IsExit())
		{
			cout << endl << "Posisi : (" << P.GetAbsis() << ',' << P.GetOrdinat() << ')' << endl << "You've reached the end of this journey." << endl;
			P.SetAbsis(-1);
			P.SetOrdinat(-1);
		}
	}
	if (P.GetAbsis()!=-1)
		cout << endl << "Posisi : (" << P.GetAbsis() << ',' << P.GetOrdinat() <<  ')' << endl;	
}

float Driver::FoodCalc()
{
	float sum = 0;
	for(int i=0;i<Z.GetJumlahCage();i++)
	{
		for(int j=0;j<(Z.GetCage(i)).GetTotalAnimal();j++)
		{
			sum += ((Z.GetCage(i)).GetAnimal(j)).GetFood();
		}
	}
	return sum;
}

void Driver::DisplayMenu() {
  cout << endl;
  cout << "Main Menu:" << endl << "1. Display Zoo" << endl;
  cout << "2. Tour Around Zoo" << endl;
  cout << "3. Animal's Food Calculation" << endl << "4. Exit" << endl << endl;
  cout << "Input your number of choice here: ";
}

Zoo& Driver::GetZoo() {
  return Z;
}

Point& Driver::GetPoint() {
	return P;
}