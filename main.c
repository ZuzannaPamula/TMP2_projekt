#include <aduc834.h>
#include <intx_t.h>
#include <lab2_board.h>
#include <stdio.h>

unsigned int a = 5;
unsigned int b = 10;
unsigned int c = 30;
unsigned int L = 0;
unsigned int X = 0;
unsigned int t_przerwy = 20;
char nr_portu = 0;


int main ()
{		
	TCON = (1<<4)|(1<<0);
	TMOD = (1<<0);
	while(1){
		TF0 = 0;
		X = a * 131;
		L = 65536 - 1 - X;
		P2|= (1<<nr_portu);
		TL0 = L%256;
		TH0 = L/256;
		while(TF0 == 0){
			};
		TF0 = 0;
		P2&= ~(1<<nr_portu);
	
		TF0 = 0;
		X = t_przerwy * 131;
		L = 65536 - 1 - X;
		TL0 = L%256;
		TH0 = L/256;
		while(TF0 == 0){
			};
		TF0 = 0;
		}
}