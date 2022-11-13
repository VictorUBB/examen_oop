#include "Gui.h"

void Gui::initGui()
{
	QHBoxLayout* mainLy = new QHBoxLayout;
	this->setLayout(mainLy);
	mainLy->addWidget(taskList);
	QWidget* right = new QWidget;
	QVBoxLayout* rightLy = new QVBoxLayout;
	right->setLayout(rightLy);
	QGroupBox* adaugare = new QGroupBox("Adaugare");
	QFormLayout* addLY = new QFormLayout;
	adaugare->setLayout(addLY);
	QLabel* id = new QLabel("Id:");
	QLabel* stare = new QLabel("Stare:");
	QLabel* descriere = new QLabel("Descriere:");
	QLabel* progra = new QLabel("Programatori:");
	addLY->addRow(id, editid);
	addLY->addRow(descriere, editDescr);
	addLY->addRow(progra, editProgr);
	addLY->addRow(stare, editStare);
	addLY->addWidget(addBtn);
	rightLy->addWidget(adaugare);
	QGroupBox* search = new QGroupBox("Search");
	QVBoxLayout* searchLy = new QVBoxLayout;
	search->setLayout(searchLy);
	searchLy->addWidget(searchProg);
	rightLy->addWidget(search);
	mainLy->addWidget(right);
}

void Gui::reloadList(vector<Task>& vect)
{
	taskList->clear();
	for (auto& el : vect) {
		auto itm = new QListWidgetItem(QString::fromStdString(std::to_string(el.getId()) + " " + el.getDescriere() + " " + el.getStare() + " " +std::to_string( el.getProgramator().size())));
		taskList->addItem(itm);
	}
}

void Gui::connectSlots()
{
	QObject::connect(addBtn, &QPushButton::clicked, [&]() {
		int id = editid->text().toInt();
		string desc = editDescr->text().toStdString();
		string prog = editProgr->text().toStdString();
		string stare = editStare->text().toStdString();
		vector<string> program;
		string nou_p="";
			for (auto& el : prog) {
				if (el != ' ') {
				nou_p += el;
				}
				else {
					program.push_back(nou_p);
					nou_p = "";
				}
			}
			program.push_back(nou_p);
			
		Task t{ id,desc,program,stare };
		if (val.validate(t) == -1) {
			QMessageBox::warning(this, "Invalid", "Invalid!!");
		}
		else
		{
			int ok = 1;
			for (auto& el : serv.getAll()) {
				if (el.getId() == id) {
					ok = 0;
					QMessageBox::warning(this, "Invalid", "Invalid!!");
				}
			}
			if (ok) {
				serv.addTask(t);
				reloadList(serv.sortStare());
			}
		}
		serv.notify();
		});

	QObject::connect(searchProg, &QLineEdit::textChanged, [&]() {
		string text = searchProg->text().toStdString();
		vector<Task> t = serv.filterByString(text);
		reloadList(t);
		
		});

}

void Gui::new_window()
{
	vector<Task> open;
	vector<Task> closed;
	vector<Task> inprogress;
	for (auto& el : serv.getAll()) {
		if (el.getStare() == "open")
			open.push_back(el);
		else if (el.getStare() == "closed")
			closed.push_back(el);
		else inprogress.push_back(el);
	}
	auto openGui=new GuiTask { open ,serv,"open"};
	auto closedGui=new GuiTask { closed ,serv ,"closed"};
	auto inprg =new GuiTask { inprogress ,serv ,"inprogress"};
	openGui->show();
	closedGui->show();
	inprg->show();
}

void GuiTask::initGui()
{
	QVBoxLayout* mainLy = new QVBoxLayout;
	this->setLayout(mainLy);
	mainLy->addWidget(listT);
	QWidget* btns = new QWidget;
	QHBoxLayout* btnsLy = new QHBoxLayout;
	btns->setLayout(btnsLy);
	btnsLy->addWidget(openBtn);
	btnsLy->addWidget(closedBtn);
	btnsLy->addWidget(inprgBtn);
	mainLy->addWidget(btns);
}

void GuiTask::reloadList(vector<Task> vect)
{
	listT->clear();
	for (auto& el : vect) {
		auto itm = new QListWidgetItem(QString::fromStdString(std::to_string(el.getId()) + " " + el.getDescriere() + " " + el.getStare() + " " + std::to_string(el.getProgramator().size())));
		listT->addItem(itm);
	}

}

void GuiTask::connectSlots()
{
	QObject::connect(openBtn, &QPushButton::clicked, [&]() {
		int id = tasks.at(getIndex()).getId();
		serv.modStare(id, "open");
		serv.notify();
		});
	QObject::connect(closedBtn, &QPushButton::clicked, [&]() {
		int id = tasks.at(getIndex()).getId();
		serv.modStare(id, "closed");
		serv.notify();
		});
	QObject::connect(inprgBtn, &QPushButton::clicked, [&]() {
		int id = tasks.at(getIndex()).getId();
		serv.modStare(id, "inprogress");
		serv.notify();
		});

}
