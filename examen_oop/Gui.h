#pragma once
#include <Qt>
#include <qwidget.h>
#include <QListWidget>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qformlayout.h>
#include "Service.h"
#include "Validation.h"
#include <qpushbutton.h>
#include<qmessagebox.h>
//ui 
class Gui:public QWidget,public observer
{
private:
	Service& serv;
	Validation val;
	QListWidget* taskList = new QListWidget;
	QLineEdit* editid = new QLineEdit;
	QLineEdit* editStare = new QLineEdit;
	QLineEdit* editDescr = new QLineEdit;
	QLineEdit* editProgr = new QLineEdit;
	QLineEdit* searchProg = new QLineEdit;
	QPushButton* addBtn = new QPushButton("Adauga");
	//clasa de initializare a interfetei
	void initGui();
	//clasa ce reincarca elemtele in lista dupa o schimbare
	void reloadList(vector<Task>& vect);
	void connectSlots();
	//clasa ce activeaza cele 3 noi ferestre
	void new_window();
	virtual void update() {
		reloadList(serv.sortStare());
	}
public:
	Gui(Service& s) :serv{ s } {
		initGui();
		connectSlots();
		reloadList(serv.sortStare());
		new_window();
		serv.addObserver(this);
	}
};
//  clasa pentrul ui -ul celor 3 tabele
class GuiTask :public QWidget,public observer{
private:
	Service& serv;
	string nume;
	vector<Task> tasks;
	QListWidget* listT = new QListWidget;
	QPushButton* openBtn = new QPushButton("Open");
	QPushButton* closedBtn = new QPushButton("Closed");
	QPushButton* inprgBtn = new QPushButton("Inprogress");
	void initGui();
	void reloadList(vector<Task> vect);
	void connectSlots();
	virtual void update() {
		reloadList(serv.filterStare(nume));
	}
public:
	GuiTask(vector<Task> t, Service& s, string nume) :tasks{ t }, serv{ s }, nume{ nume }{
		initGui();
		connectSlots();
		reloadList(tasks);
		serv.addObserver(this);
		
	}
	int getIndex() {
		auto ind = listT->selectionModel()->currentIndex();
		return ind.row();
	}
};

