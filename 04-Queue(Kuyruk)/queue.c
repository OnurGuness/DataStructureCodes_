/*QUEUE
-DOğrusal bir veri yapısıdır.
-İlk gelen eleman ilk önce işlendiği ve kuyruktan çıktığı veri yapısıdır.
Ex.Bankamatik kuyruğu vs.

FIFO
-First In First Out
-İlk giren ilk çıkar demektir.
-FIFO yöntemi hem array(dizi) hem de linked-list(bağlı liste) yapısıyla uygulanabilir.

Kullanım Alanları
-PIPE yani boru hattı yapılarında
-Disk yönetiminde giriş/çıkış isteklerini planlamada
-Switch,router gibi network yapılarındaki veri paketlerinde
-Elektronik devrelerde yazılım ve donanım arası buffer işlemlerinde

Front ve rear
*/
#include<stdio.h>
#include<stdlib.h>

//Queue Node
struct node {
    int data;
    struct node *next;
};

//Front & Rear 
struct node *front = NULL;
struct node *rear = NULL;

int enqueue(int data){
    //Queue is empty
    if(front == NULL){
        struct node *new =(struct node*)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        front = rear = new;
    }
    //Queue is empty
    else{
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        rear->next = new;
        rear = new;

    }
}
//Display Queue
int display(){
    //Queue is empty
    if(front==NULL){
        printf("Queue is empty\n");
        return 0;
    }

    printf("Queue:");
    struct node *index = front;
    while(index!=NULL){
        
        printf("%d - ",index->data);
        index=index->next;
    }
    printf("\n");
    return 0;
}

//Dequeue
int dequeue(){
    //Queue is empty
    if(front==NULL){
        printf("Queue is empty\n");
        return 0;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
    return 0;
}


int main(){

    enqueue(5);
    enqueue(6);
    enqueue(8);
    enqueue(10);
    
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();

    enqueue(1);
    enqueue(3);
    display();
    return 0;
}


