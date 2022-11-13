#pragma once
#include "Repo.h"
#include <algorithm>
#include "observer.h"
//clasa ce se ocupa cu legatura dintre interfata si memorie
class Service:public observable
{private:
	//repo folosit pentru a folosi functile definite in el
	Repo& repo;
public:
	//constructor
	Service(Repo& r):repo{r}{}
	//functie ce returneaza toate taskurile din meorie
	vector<Task>& getAll();
	//functie de soratrea a taskurilr din memorie in ordne crescatoaer in functie de atre
	vector<Task>& sortStare();
	//fuctie ce adauga un nou task in lista
	void addTask(Task t);
	//functie ce verifica daca un string se afla in lista
	vector<Task> filterByString(string st);
	//functie ce filtreaza dupa o stare
	vector<Task> filterStare(string stare);

	//functie de modificare a sarii unui task dupa id
	void modStare(int id,string stare);
};

void testService();

