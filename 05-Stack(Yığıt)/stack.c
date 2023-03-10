/*Stack(Yığıt)
-Doğrusal bir veri yapısıdır.
-Son gelen elemanın ilk önce işlendiği ve listeden çıktığı veri yapısıdır.
-Üst üste koyulan kitaplar,silah şarjörleri,okey oyununda ortaya konulan taşlar,üst üste koyulan tabaklar vs.
-Stack veri yapısı için LIFO yapısı kullanılır.

LIFO
-Last In First Out ifadesinin kısaltmasıdır.Son giren ilk çıkar anlamındadır.
-LIFO yönemine göre listeye son giren eleman ilk olarak işlenir ve listeden çıkar.
-LIFO yöntemi hem array hem de linked-list yapısıyla uygulanabilir.

Kullanım Alanları
-Bellek yönteminde sayfaların swap(takas) işlemlerinde
-Uygulamaların"Geri Al" işlemlerinde
Tarayıcıların Geri-İleri butonlarında
*/

#include<stdio.h>
#include<stdlib.h>

//Stack
struct node{
    int data;
    struct node *next;

};

//Top
struct node *top = NULL;

//Push
int push(int data){
    //Stack is empty
    if(top==NULL){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        top = new;
    }
    //Stcak is empty
    else{
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = top;

        top = new;
    }
    return 0;
}

int display(){
    //Stack is empty
    if(top==NULL){
        printf("Stack is empty.\n");
        return 0;
    }
    struct node *index = top;
    while(index!=NULL){
        printf("%d - ",index->data);
        index = index->next;
    }
    printf("\n");
    return 0;
}

//Pop
int pop(){
    if(top==NULL){
        printf("Stack is empty.\n");
        return 0;
    }
    struct node *temp = top;

    top = top->next;

    free(temp);
    return 0;
}
//Main
int main(){

    push(1);
    push(2);
    push(4);
 
    display();

    pop();
    pop();
    display();

    pop();
    display();
    push(7);
    push(9);
    push(13);
    display();
    return 0;
}