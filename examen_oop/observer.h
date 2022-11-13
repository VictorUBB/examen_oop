#pragma once
//observer class
//clasa pentru sincronizare
class observer
{public:
	virtual void update() = 0;
};
#include <vector>
using std::vector;
//clasa ce controleaza observerii
class observable {
private:
	vector<observer*> obs;
public:
	void addObserver(observer* o) {
		obs.push_back(o);
	}
	void notify() {
		for (auto& el : obs) {
			el->update();
		}
	}
};

