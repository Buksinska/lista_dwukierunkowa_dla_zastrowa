#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct rekord               //tworzenie rekordu
{

	string key;
	rekord* next;
	rekord* prev;

	rekord();
};

rekord::rekord()
{
	next = 0;
	prev = 0;
}

struct list
{
	rekord* head;
	rekord* tail;

	list();
	void display();
	void displayBack();
	void newRekordFront();
	void newRekordBack();
	void newRekordIn();
	void newRekord(string data);
	void load();
	void save();
	int ile();

};

list::list()
{

	head = 0;
	tail = 0;
}

void list::newRekordFront()
{

	rekord* nowy = new rekord;

	cout << "Prosze wpisac dane: ";
	cin >> nowy->key;

	if (head == 0)
    {
																						//string input;
                                                                                        //getline(cin, input, '|');
		head = nowy;                                                                    // = wkazuje a nie STAJE SIE
		tail = nowy;
	}
	else
        {
		head->next = nowy;                                                              //head jest wskaznikiem listy na element
		nowy->prev = head;
		nowy->next = 0;
		head = nowy;
	}
}
void list::newRekordBack()
{
	rekord* nowy = new rekord;

	cout << "Prosze wpisac dane: ";
	cin >> nowy->key;

	if (head == 0)
    {
																						//string input;
                                                                                        //getline(cin, input, '|');
		head = nowy;                                                                    // = wkazuje a nie STAJE SIE
		tail = nowy;
	}
	else

    {
		tail->prev = nowy;                                                              //head jest wskaznikiem listy na element
		nowy->next = tail;
		nowy->prev = 0;
		tail = nowy;
	}
}

void list::newRekordIn()
{

	if (head == 0)
    {
		rekord* nowy = new rekord;

        cout << "Prosze wpisac dane: ";
        cin >> nowy->key;																				//string input;
                                                                                        //getline(cin, input, '|');
		head = nowy;                                                                    // = wkazuje a nie STAJE SIE
		tail = nowy;
	}
	else
    {
        int wybor;
        cout << "Na ktorej pozycji chcesz wstawic element? ";
        cin >> wybor;
        if (wybor == 0)
        {
            newRekordBack();
        }
        else if (wybor>0&&wybor<ile())
        {
            rekord* nowy = new rekord;

            cout << "Prosze wpisac dane: ";
            cin >> nowy->key;

            nowy->next = tail;

            for (int i = 0; i<ile(); i++)
            {
                nowy->next = nowy->next->next;

            }

            nowy->prev = nowy->next->prev;
            nowy->prev->next = nowy;
            nowy->next->prev = nowy->prev;
        }
        else if (wybor == ile())
        {
            newRekordFront();
        }
        else
        {
            cout << "Musisz wybrać miejsce na liscie (0 - " << ile() << ")";
        }

	}
}

void list::newRekord(string data)
{                                                      //tworzenie funkcji

	rekord* nowy = new rekord;

	nowy->key = data;

	if (head == 0)
    {
		head = nowy;
		tail = nowy;
	}
	else
	{
		head->next = nowy;
		nowy->prev = head;
		nowy->next = 0;
		head = nowy;
	}
}

void list::display()
{
	if (head == 0)
		cout << "\nERROR: Lista jest pusta. \nNie mam nic do wyswietlwnia\n";
	else
    {
		rekord* temp = tail;
		while (temp)
		{
			cout << temp->key << endl;

			temp = temp->next;
		}
	}
}

void list::displayBack()
{
	if (head == 0)
		cout << "\nERROR: Lista jest pusta. \nNie ma nic do wyswietlenia?\n";
	else
    {
		rekord* temp = head;
		while (temp)
		{
			cout << temp->key << endl;

			temp = temp->prev;
		}
	}
}

void list::load()
{													// tworzymy obiekt do operowania na plikach


	fstream plik;

	plik.open("dane_listy.txt", ios::in);                       // plik sam siê tworzy przy zapisie, tylko do odczytu dla progemu
	if (plik.good() == true)
	{
	    cout << "\n\n loaded saved list :) \n\n";
		string line;

		while (getline(plik, line)) {
			newRekord(line);
		}

	}
	else {
		cout << "\nFailed to open dane_listy.txt file \n";               //wyœwietli sie kiedy plik tekstowy nie istnieje
	}

    plik.close();

}

void list::save() {												       	// ZAPIS

	fstream plik;

	plik.open("dane_listy.txt", ios::out);

	if (head == 0)
		cout << "\n Lista jest pusta. \n";
	else {
		rekord* temp = tail;
		while (temp)
		{
			plik << temp->key << endl;

			temp = temp->next;
		}
	}
	plik.close();

}

int list::ile()
{
    rekord* temp = new rekord;
    temp = tail;
    int licznik = 0;
    while (temp)
    {
        temp=tail->next;
        licznik++;
    }
    return licznik;
}

int main()
{
	list my_list;

	int wybor;
	do {
		system("cls");
		cout << "   ---------------------------------------------   " << endl;
		cout << "   ----=======>> - Zadanie domowe - <<=======---  " << endl;
		cout << "   ---------------------------------------------   " << endl;
		cout << "   1. Dodaj element na poczatku listy.  " << endl;
		cout << "   2. Dodaj element na koncu listy.  " << endl;
		cout << "   3. Dodaj element w wybranym miejscu listy. " << endl;
		cout << "   4. Usuń element z poczatku listy.  " << endl;
		cout << "   5. Usuń element z konca listy.  " << endl;
		cout << "   6. Usuń element z wybranego miejsca listy. " << endl;
		cout << "   7. Zapisz liste.  " << endl;
		cout << "   8. Wyswietl liste.  " << endl;
		cout << "   9. Wyświetl liste od konca.  " << endl;
		cout << "   0. Wyjście  " << endl;
		cout << "   ---------------------------------------------   " << endl;
        cout << "   ----==== - Made by Agata Buksinska - ====----   " << endl;
		cout << "\n   Wybierz numer polecenia :";

		wybor = _getch();                                                     //jak cin ale bez potwierdzenia,
                                                                              //cyferki maj¹ odpowiedzni kod z tablicy ASCII

		if (wybor == 49)    //1
		{
			system("cls");
			my_list.newRekordBack();
		}
		else if (wybor == 50)   //2
		{
		    system("cls");
			my_list.newRekordFront();
		}
		else if (wybor == 51)    //3
		{
		    system("cls");
			my_list.newRekordIn();

		}
		else if (wybor == 52)   //4
		{

		}
		else if (wybor == 53)   //5
		{



        }
		else if (wybor == 54)   //6
		{


		}
		else if (wybor == 55)   //7
		{
            cout << "\n\n Twoja lista zosta³a zapisana jako dane_listy.txt \n\n";
			my_list.save();
			system("pause");
		}
		else if (wybor == 56)   //8
		{
            system("cls");
			my_list.display();
			system("pause");
		}
		else if (wybor == 54)   //9
		{
            system("cls");
			my_list.displayBack();
			system("pause");

		}
		}while (wybor != 48); //0

        cout << endl << "Thanks, I hope you enjoyed :)" << endl << endl;

	system("pause");
	return 0;
}
