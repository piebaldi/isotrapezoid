/// @file main.cpp
/// @brief A short test to check the correct behaviour of the classes
#include "IsoTrapezoid.h"
#include "rhombus.h"
#include "rectangle.h"
#include <iostream>

#define MAX_NUM 100

void Menu();
void ErrorMessage(const char* string);

int main() {

	Polygon* P[MAX_NUM] = { 0 };
	char choice = 0;
	int temp;
	int i = 0; //counter
	while (choice != '5') {
		Menu();
		cin >> choice;
		switch (choice) {
		case '1':

			//counter check
			if (i == MAX_NUM) {
				ErrorMessage("Max number of objects reached");
				break;
			}

			P[i] = new Rectangle();
			cout << "Insert length and width (each followed by an enter): ";

			//APPROCCIO SPIEGATO DAL PROF. ZUNINO su richiesta, necessario per utilizzare l'overload 
//dell'operatore ">>" scritto solo per le sottoclassi ma non per la classe base

//puntatore utilizzato per il dynamic casting
			Rectangle* rect;
			rect = dynamic_cast<Rectangle*>(P[i]); //dynamic casting

			//controlla il codice di ritorno di dynamic casting
			if (rect)
				cin >> *rect;
			i++;
			break;
		case '2':
			//counter check
			if (i == MAX_NUM) {
				ErrorMessage("Max number of objects reached");
				break;
			}

			P[i] = new Rhombus();
			cout << "Insert horizontal diagonal and vertical diagonal (each followed by an enter): ";

			//dynamic casting
			Rhombus* rhom;
			rhom = dynamic_cast<Rhombus*>(P[i]);
			if (rhom)
				cin >> *rhom;
			i++;
			break;

		case '3':
			//counter check
			if (i == MAX_NUM) {
				ErrorMessage("Max number of objects reached");
				break;
			}

			P[i] = new IsoTrapezoid();
			cout << "Insert top side, bottom side and height (each followed by an enter): ";
			//dynamic casting
			IsoTrapezoid* iso;
			iso = dynamic_cast<IsoTrapezoid*>(P[i]);
			if (iso)
				cin >> *iso;
			i++;
			break;

		case '4':

			temp = i;
			for (i = 0; i < temp; i++) {
				P[i]->Draw();
				cout << "area: " << P[i]->GetArea() << endl;
				cout << "perimeter: " << P[i]->GetPerimeter() << "\n" << endl;
			}
			break;

		case '5':

			temp = i;
			for (i = 0; i < temp; i++) {
				delete P[i];
			}
			cout << "Closing program..." << endl;
			break;

		default:

			cout << "Invalid argument" << endl;
			break;
		}
	}
	return 0;
}

/// @brief Menu function
void Menu() {
	cout << "Insert 1 to create rectangle: " << endl;
	cout << "Insert 2 to create rhombus: " << endl;
	cout << "Insert 3 to create iso trapezoid: " << endl;
	cout << "Insert 4 to draw: " << endl;
	cout << "Insert 5 to exit the program: ";
}

/// @brief Error message function (for debugging purposes)
void ErrorMessage(const char* string) {
	cout << "ERROR ----- main ------ " << string << endl;
}


