#include "Repo.h"

void Repo::addTask(Task& t)
{
	all.push_back(t);
}

vector<Task>& Repo::getAll()
{
	return this->all;
}

void Repo::modSt(int id, string st)
{
	for (auto& el : all) {
		if (el.getId() == id) {
			el.setStare(st);
			return;
		}
	}

}

void FileRepo::load_from_file()
{
	std::ifstream f(filename);
	while (!f.eof()) {
		int id;
		string descriere, stare;
		vector<string> program;
		string prog;
		f >> id;
		f >> descriere;
		//f >> prog;
		//while (prog != "/n") {
		//	program.push_back(prog);
		//	f >> prog;
		//}
		//getline(f, prog);
		//string nou_p="";
		//for (auto& el : prog) {
		//	if (el != ' ') {
		//		nou_p += el;
		//	}
		//	else {
		//		program.push_back(nou_p);
		//		nou_p = "";
		//	}
		//}

		f >> prog;
		while (prog != "open" && prog != "inprogress" && prog != "closed") {
			program.push_back(prog);
			if (f.eof()) {
				
				f.close();
				return;
			}
			f >> prog;
		}
		stare=prog;
		Task t{ id,descriere,program,stare };
		Repo::addTask(t);

	}
	f.close();
}

void FileRepo::save_to_file()
{
	std::ofstream f(filename);
	for (auto& el : getAll()) {
		f << el.getId() << endl;
		f << el.getDescriere() << endl;
		for (auto& it : el.getProgramator()) {
			f << it << " ";
		}
		f << endl;
		f << el.getStare() << endl;
	}
	f.close();
}

void testRepo()
{

	Repo rep;
	vector<string> pr;
	pr.push_back("Dan");
	Task t{ 1,"ad",pr,"open" };
	Task t1{ 2,"ad",pr,"closed" };
	rep.addTask(t);
	assert(rep.getAll().size() == 1);
	rep.addTask(t1);
	assert(rep.getAll().size() == 2);
}
