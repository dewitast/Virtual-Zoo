/**	@file cage.cpp
  */

#include "../cage/cage.h"
#include "../zoo/zoo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Cage::Cage()
{
	size = MaxSize;
	Loc = new Point [size];
	TotalAnimal = 0;
	a = new Animal*[size];
}

Cage::Cage(int s)
{
	size = s;
	Loc = new Point [size];
	TotalAnimal = 0;
	a = new Animal*[size];
}

Cage::Cage(int i, int j)
{
	size = 1;
	Loc = new Point [size];
	Point P;
	P.SetAbsis(i);
	P.SetOrdinat(j);
	Loc[0] = P;
	TotalAnimal = 0;
	a = new Animal*[size];
}

Cage::Cage(const Cage& c)
{
	size = c.size;
	Loc = new Point [size];
	for (int i = 0; i < size; ++i)
		Loc[i] = c.Loc[i];
	TotalAnimal = c.TotalAnimal;
	a = new Animal*[size];
	for (int i=0;i<TotalAnimal;++i)
		a[i] = (c.a[i])->Clone();
}

Cage& Cage::operator=(const Cage& c)
{
	size = c.size;
	delete [] Loc;
	Loc = new Point [size];
	for (int i = 0; i < size; ++i)
		Loc[i] = c.Loc[i];
	TotalAnimal = c.TotalAnimal;
	for (int i=0;i<TotalAnimal;++i)
		a[i] = (c.a[i])->Clone();
	return *this;
}

Cage::~Cage()
{
	delete [] Loc;
	for (int i=0;i<TotalAnimal;++i)
		delete a[i];
	delete [] a;
}

void Cage::AdoptAnimal(Animal& A)
{
	if (IsFull()) cout << "Kandang penuh." << endl;
	else if (IsInCage(A)==-1)
	{
		int random = rand() % size;
		while (IsOccupied(random))
			random = rand() % size;
		A.SetPoint(GetPoint(random));
		a[TotalAnimal] = A.Clone();
		++TotalAnimal;
	}
}

void Cage::ReleaseAnimal(int i)
{
	delete a[i];
	for (int j = i+1;j<TotalAnimal;++j)
		a[j-1] = a[j];
	--TotalAnimal;
}

bool Cage::IsOccupied(int i) const
{
	bool found = false;
	int ind = 0;
	while ((!found)&&(ind<TotalAnimal))
	{
		if (((*(a[ind])).GetPos()).IsSame(Loc[i])) found = true;
		else ++ind;
	}
	return found;
}

bool Cage::IsOccupied(const Point& p) const
{
	int i = 0;
	while (!(Loc[i].IsSame(p))) ++i;
	return IsOccupied(i);
}

int Cage::IsInCage(const Animal &A) const
{
	bool found = false;
	int i = 0;
	while ((!found)&&(i<TotalAnimal))
	{
		if (A.IsSame(*a[i])) found = true;
		else ++i;
	}
	if (found) return i;
	else return -1;
}

bool Cage::IsInCage(const Point& P) const
{
	bool found = false;
	int i=0;
	while ((!found)&&(i<size))
	{
		if (P.IsSame(Loc[i])) found = true;
		else ++i;
	}
	return found;
}

void Cage::Interact() const
{
	for (int i=0;i<TotalAnimal;++i)
		cout << a[i]->Interact() << endl;
}

void Cage::AddPoint(Point P)
{
	Point* temp = new Point[size+1];
	for (int i=0; i<size; i++)
	{
		temp[i] = Loc[i];
	}
	temp[size] = P;
	delete [] Loc;
	Loc = temp;
	++size;
}