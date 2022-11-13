#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
//using std::vector;

//clasa ce se ocupa cu crearea obiectelor de tip task
//primeste ca parametru un id, o descriere string, o lista de stringuri cu  numele programatorulor si o stare
class Task
{
private:
	int id;
	string descriere;
	vector<string> programator;
	string stare;
public:
	Task(int i, string d, vector<string> p, string s) :id{ i }, descriere{ d }, programator{ p }, stare{ s }{};
	int getId() const;
	string getDescriere() const;
	vector<string> getProgramator() const;
	string getStare() const;
	void setStare(string stare);
};

//functie de compararea a starilor alfabetic
bool cmpStare(const Task& t1, const Task& t2);

//functie ce verifica ddaca stringul st se afla in t1
bool string_in_pr(const Task& t1, string st);

void testCreate();