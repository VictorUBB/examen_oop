#pragma once
#include "Task.h"
#include <vector>
#include <fstream>
using std::vector;
//clasa se ocupa cu gestiunea memoriei si cu operatile pe elemnete
class Repo
{
private:
	//vectorul unde tinem toate taskurile
	vector<Task> all;
public:
	Repo() = default;//constructor
	//functie ce adauga un nou task in lista
	virtual void addTask(Task& t);
	//functie ce retuneaza toate taskurile sub forma de vector
	vector<Task>& getAll();
	//functie ce modifica starea unui task / taskul cu id ul dat ca parametru
	virtual void modSt(int id,string st);
};

//clasa ce se ocupa cu leagturad intre memorie si fisiere
class FileRepo :public Repo {
private :
	//numele fisierului unde vrem sa salvam datele
	string filename;
	//functie ce aduce datele din fisier
	void load_from_file();
	//functie ce salveaza datele in fisier
	void save_to_file();
public:
	//constructor
	FileRepo(string f) :Repo(), filename{ f }{
		load_from_file();
	}
	virtual void addTask(Task& t) override {
		Repo::addTask(t);
		save_to_file();
	}
	virtual void modSt(int id, string st) override {
		Repo::modSt(id, st);
		save_to_file();
	}
};

void testRepo();

