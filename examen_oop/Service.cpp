#include "Service.h"

vector<Task>& Service::getAll()
{   
    return repo.getAll();
}

vector<Task>& Service::sortStare()
{
    vector<Task>& all = repo.getAll();
    sort(all.begin(), all.end(), cmpStare);
    return all;
}

void Service::addTask(Task t)
{
    repo.addTask(t);
}

vector<Task> Service::filterByString(string st)
{
    vector<Task>& all = repo.getAll();
    vector<Task> new_list;
    string alex{ "alex" };

    auto ok = alex.find("la");
    copy_if(all.begin(), all.end(), std::back_inserter(new_list), [st](const Task& t1) {return string_in_pr(t1,st); });
    return new_list;
}

vector<Task> Service::filterStare(string stare)
{
    vector<Task>& all = repo.getAll();
    vector<Task> new_list;
    copy_if(all.begin(), all.end(), std::back_inserter(new_list), [stare](const Task& t) {return t.getStare() == stare; });
    return new_list;
}

void Service::modStare(int id, string stare)
{
    repo.modSt(id, stare);
}

void testService()
{

    Repo rep;
    Service serv{ rep };
    vector<string> pr;
    pr.push_back("Dan");
    Task t{ 1,"ad",pr,"open" };
    Task t1{ 2,"ad",pr,"closed" };
    serv.addTask(t);
    assert(serv.getAll().size() == 1);
    serv.addTask(t1);
    assert(serv.getAll().size() == 2);

    
    

}
