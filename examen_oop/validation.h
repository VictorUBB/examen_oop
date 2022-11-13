#include "Task.h"

//clasa pentru validaarea datelor de intrare
class Validation {
public:
	//functie ce valideaza
	//return -1 daca nu e valid
	//return 1 daca e valid
	int validate(Task t) {
		if (t.getDescriere() == "")
			return -1;

		if (t.getProgramator().size() > 4)
			return -1;		
		if (t.getStare() == "open" || t.getStare() == "inprogress" || t.getStare()== "closed") {
			return 1;
		}
		return -1;
	}

};