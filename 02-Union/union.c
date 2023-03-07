#include<stdio.h>
#include<string.h>

union ogrenci{
    char isim[20];
    int no;
    float ort;
};

typedef union{
    char isim[20];
    int yas;
} ogretmen;


int main(){
    printf("Boyut: %ld Byte \n",sizeof(union ogrenci));

    union ogrenci o;

    strcpy(o.isim,"Yucel");
    printf("Isim: %s\n", o.isim);

    o.no = 148;
    printf("No: %d\n", o.no);

  //  printf("Isim: %s\n",o.isim);

    o.ort = 85.5;
    printf("Ortalama: %.2f\n",o.ort);

    // Typedef ile kullanım

    ogretmen ogrt;
    strcpy(ogrt.isim,"Ismail");
    printf("Ogretmen adi: %s\n",ogrt.isim);

    ogrt.yas=45;
    printf("Ogretmenin Yasi: %d",ogrt.yas);



    return 0;
}