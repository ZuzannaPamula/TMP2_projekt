#include <aduc834.h>
#include <intx_t.h>
#include <lab2_board.h>
#include <stdio.h>


void ustawienie_licznika (unsigned int Y){
	unsigned int X = 0, L = 0;
	TF0 = 0;
	X = Y * 131;
	L = 65536 - 1 - X;
	TL0 = L%256;
	TH0 = L/256;
	return;
}

void funkcja_zmiany_stanu(unsigned int a, unsigned int b, unsigned int c){
	unsigned int t_przerwy = 20;
	char nr_portu = 0;
	while(1){
		ustawienie_licznika(a);
		P2|= (1<<nr_portu);
		while(TF0 == 0){
			};
		ustawienie_licznika(t_przerwy);
		P2&= ~(1<<nr_portu);
		while(TF0 == 0){
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