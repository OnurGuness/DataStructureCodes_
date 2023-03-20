#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient{
	int priority;
	char name[30];
	struct patient *next;
} Patient;

void addPatient(Patient **head, Patient **tail, int priority, char *name) {
	Patient *newPatient = (Patient*)malloc(sizeof(Patient));
	newPatient->priority = priority;
	strcpy(newPatient->name,name);
	newPatient->next = NULL;
	
	// Boþ bir dairesel baðlý liste ise
	if(*head == NULL){
		*head = newPatient;
		*tail = newPatient;
		(*tail)->next = *head;
	}
	else{
		//Öncelik deðerine göre yerleþtirme yapýlýr
		Patient *current = *head;
		if(current->priority > priority){
			while(current->next != *head && current->next->priority<priority){
				current = current->next;
			}
			newPatient->next = current->next;
			current->next = newPatient;
			if(newPatient->next == *head){
				*tail = newPatient;
			}
		}
		else{
			newPatient->next = *head;
			*head = newPatient;
			(*tail)->next = *head;
		}
	}
}

void removePatient(Patient **head, Patient **tail, char *name){
	Patient *current = *head;
	Patient *prev = NULL;
	//Ýlk hasta silinirse
	if(strcmp((*head)->name,name) == 0){
		*head = (*head)->next;
		(*tail)->next = *head;
	}
	else{
		while(current != *head && strcmp(current->name,name) != 0){
			prev = current;
			current = current->next;
		}
		//Hasta bulunmadýysa
		if(current == *head){
			printf("Patient not found\n");
			return;
		}
		//Hasta bulunduysa
		prev->next = current->next;
		if(current == *tail){
			*tail = prev;
		}
	}
	free(current);
}

Patient* getNextPatient(Patient **head,Patient **tail){
	Patient *nextPatient = *head;
	*head = (*head)->next;
	*tail = (*tail)->next;
	return nextPatient;
}

void listPatients(Patient *head){
	Patient *current = head;
	printf("Patient list:\n");
	do{
		printf("%s (priority: %d)\n",current->name,current->priority);
		current = current->next;
	}while(current!=head);
}

int main(){
	Patient *head = NULL;
	Patient *tail = NULL;
	
	//Yeni hastalar ekleme
	addPatient(&head, &tail, 2, "Ahmet");
	addPatient(&head, &tail, 1, "Mehmet");
	addPatient(&head, &tail, 3, "Ali");
	addPatient(&head, &tail, 4, "Veli");
	
	//Hasta sýrasý takibi
	Patient *nextPatient = getNextPatient(&head,&tail);
	printf("Next patient: %s\n", nextPatient->name);
	free(nextPatient);
	
	//Hastalarý listeleme
	listPatients(head);
	
	//Hasta silme
	removePatient(&head,&tail, "Ahmet");
	
	return 0;
}
