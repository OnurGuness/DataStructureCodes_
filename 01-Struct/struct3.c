#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char takimAdi[30];
	int kurulus;
} takim;

typedef struct{
	char adSoyad[30];
	int yas;
	takim takim;
} futbolcu;

int main(){

    takim tk;
    strcpy(tk.takimAdi,"Samsunspor");
    tk.kurulus=1965;

    futbolcu ft;
    strcpy(ft.adSoyad, "Hamza Akman");
    ft.yas= 19;
    ft.takim = tk;

    printf("Bilgiler: %s %d",ft.takim.takimAdi,ft.takim.kurulus);


    return 1;
}