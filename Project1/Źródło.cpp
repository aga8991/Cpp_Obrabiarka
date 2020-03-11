// èrÛd≥o.cpp

#include <iostream>
#include "Czas.h"
#include "Obrabiarka.h"

void wypisz_poczatek();
int idioto_ochrona_menu();
void uruchom_menu(Obrabiarka _test);
int od_uzytkownika(int _flaga);
void wypisz_kopie(Obrabiarka _test);

int main()
{
	//Przykladowe czasy:
	Czas czas1;
	Czas czas2(50, 15, 1);
	Czas czas3 = czas2;
	Czas czas4 = czas3 + czas1;

	//Przykladowa obrabiarka:
	Obrabiarka obr2;
	obr2.dodaj_czas(12345);
	obr2.dodaj_czas(450, 15, 1);
	obr2.dodaj_czas(234, 140, 2);
	obr2.dodaj_czas(23421);
	obr2.dodaj_czas(2345);
	obr2.dodaj_czas(czas3);
	obr2.dodaj_czas(czas2);

	while (1)
	{
		uruchom_menu(obr2);
	}
}

void uruchom_menu(Obrabiarka _test)
{
	wypisz_poczatek();
	int x = idioto_ochrona_menu();
	int n;
	Obrabiarka nowa;
	//_test.wypisz_czasy();

	switch (x)
	{
	case 1:
		system("cls");
		std::cout << "Podaj liczbe czasow: ";
		n = od_uzytkownika(0);
		//nowa.kopia_n_czasow(n, _test);
		nowa = _test.kopia_n_czasow(n);
		wypisz_kopie(nowa);
		break;
	case 2:
		system("cls");
		int h, m, s;
		std::cout << "Podaj czas do ktorego kopiowac: " << std::endl;
		h = od_uzytkownika(1);
		m = od_uzytkownika(2);
		s = od_uzytkownika(3);
		Czas granica(s, m, h);
		nowa = _test.kopia_do_czasu(granica);
		wypisz_kopie(nowa);
		break;
	}
}

int idioto_ochrona_menu()
{
	int x;
	while (1)
	{
		std::cin >> x;
		if (x == 1 || x == 2)	break;
	}
	return x;
}

int od_uzytkownika(int _flaga)
{
	int _x;
	while (1)
	{
		if(_flaga == 1)	std::cout << "\tGodziny: ";
		if(_flaga == 2)	std::cout << "\tMinuty: ";
		if(_flaga == 3)	std::cout << "\tSekundy: ";
		std::cin >> _x;
		if (_x >= 0) break;
	}
	return _x;
}

void wypisz_poczatek()
{
	system("CLS");
	std::cout << "Menu uzytkownika:" << std::endl;
	std::cout << "\t1. Skopiuj n czasow z obrabiarki." << std::endl;
	std::cout << "\t2. Skopiuj wszystkie czasy obrabiarki, nieprzekraczajace wybranego czasu" << std::endl;
}

void wypisz_kopie(Obrabiarka _test)
{
	std::cout << "Kopia: " << std::endl;
	_test.wypisz_czasy();
	system("pause");
}