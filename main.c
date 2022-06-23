#include <aduc834.h>
#include <intx_t.h>
#include <lab2_board.h>
#include <stdio.h>


void ustawienie_licznika (unsigned int Y){
	unsigned int X = 0, L = 0;
	TF0 = 0;
	X = Y * 131;											//X - iloraz oczekiwanego czasu Y bedacego argumentem funkcji przez czas cyklu maszynowego (131 = 1/0,007629)
	L = 65536 - 1 - X;								//L - poczatkowa wartosc licznika T0 dla danego czasu Y bedacego argumentem funkcji
	TL0 = L%256;											//Wpisanie wartosci licznika do TL0
	TH0 = L/256;											//Wpisanie wartosci licznika do TH0
	return;
}

void ustawianie_i_zerowanie (char nr_portu, unsigned int czas){
	ustawienie_licznika(czas);				//Ustawienie licznika tak, aby odliczal czas rowny agumentowi funkcji "czas"
	P2|= (1<<nr_portu);								//Ustawienie stanu wysokiego na porcie P2."nr_portu", gdzie "nr_portu" jest argumentem funkcji 
		while(TF0 == 0){								//Oczekiwanie na wysoki stan flagi przepelnienia TF0 swiadczacy o uplynieciu czasu "czas"
			};
	P2&= ~(1<<nr_portu);							//Ustawienie stanu niskiego na porcie P2."nr_portu", gdzie "nr_portu" jest argumentem funkcji 
			return;
}

void funkcja_zmiany_stanu(unsigned int a, unsigned int b, unsigned int c){
	unsigned int t_przerwy = 20;
	while(1){
		ustawianie_i_zerowanie(0,a);		//Ustawienie stanu wysokiego na P2.0 na czas a i wylaczenie go
		ustawianie_i_zerowanie(1,b);		//Ustawienie stanu wysokiego na P2.1 na czas b i wylaczenie go
		ustawianie_i_zerowanie(2,c);		//Ustawienie stanu wysokiego na P2.2 na czas c i wylaczenie go
		ustawienie_licznika(t_przerwy);	//Ustawienie licznika na czas t_przerwy
		while(TF0 == 0){								//Utrzymanie stanu niskiego na wszystkich portach przez czas t_przerwy
			};
		}
	return;
}

int main ()
{	
	unsigned int a = 5, b = 10, c = 30;
	TCON = (1<<4)|(1<<0);
	TMOD = (1<<0);
	funkcja_zmiany_stanu(a, b, c);
	return 0; 
}

