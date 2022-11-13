#include "Task.h"

int Task::getId() const
{
    return this->id;
}

string Task::getDescriere() const
{
    return this->descriere;
}

vector<string> Task::getProgramator() const
{
    return this->programator;
}

string Task::getStare() const
{
    return this->stare;
}

void Task::setStare(string stare)
{
    this->stare = stare;
}

bool cmpStare(const Task& t1, const Task& t2)
{
    return t1.getStare() < t2.getStare();

}

bool string_in_pr(const Task& t1, string st)
{
    for (auto& el : t1.getProgramator()) {
        if (el.find(st) == 0)
            return 1;
    }
    return 0;
}

void testCreate()
{
    vector<string> pr;
    pr.push_back("Dan");
    Task t{ 1,"ad",pr,"open" };
    assert(t.getDescriere() == "ad");
    assert(t.getId() == 1);
    assert(t.getStare() == "open");
    t.setStare("closed");
    assert(t.getStare() == "closed");

}
