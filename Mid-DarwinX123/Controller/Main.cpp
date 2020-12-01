#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patients {
  char name[255], month[255], ;
  int date, year;
  Patients *next, *prev;
} *head, *tail, *curr;

Patients *createPatients(char *name, char *month, int date, int year) {
  Patients *temp = (Patients*)malloc(sizeof(Patients));
  temp->value = value;
  temp->next = temp->prev = NULL;
  return temp;
}

void pushHead(char *name, char *month, int date, int year) {
  Patients *temp = createNode(name, month, date, year);

  if(!head) { 
    head = tail = temp;
  } else {
    head->prev = temp;
    temp->next = head;
    head = temp;
  }
}

void pushTail(char *name, char *month, int date, int year) {
  Patients *temp = createNode(name, month, date, year);

  if(!head) { 
    head = tail = temp;
  } else { 
    tail->next = temp; 
    temp->prev = tail; 
    tail = temp;  
  }
}

void pushMid(char *name, char *month, int date, int year) {
  if(!head) { 
    Patients *temp = createNode(name, month, date, year);
    head = tail = temp;
  } else if(name < head->name && month< head->month && date < head->date && year < head->year) {
    pushHead(name, month, date, year);
  } else if(name > head->name && month> head->month && date > head->date && year > head->year) { 
    pushTail(name, month, date, year);
  } else { 

    Patients *temp = createNode(name, month, date, year);
    curr = head;

    while(curr->value < name, month, date, year) {
      curr = curr->next;
    }
    
    temp->prev = curr->prev; 
    temp->next = curr; 
    
    curr->prev->next = temp;
    curr->prev = temp;
  }
}

void popHead() {
  if(head && head == tail) { 
    head = tail = NULL;
    free(head);
  } else { 
    Patients *newHead = head->next; 
    head->next = newHead->prev = NULL; 
    free(head); 
    head = newHead; 
  }
}

void popTail() {
  if(head && head == tail) { 
    head = tail = NULL;
    free(head);
  } else {
    Patients *newTail = tail->prev; 
    tail->prev = newTail->next = NULL; 
    free(tail); 
    tail = newTail; 
  }
}

void popMid(char *name, char *month, int date, int year) {
  if(!head) {
    return;
  } else if(head->name == name &&  head->month == month && head->date == date && head->year == year) {
    popHead(); 
  } else if(tail->name == name &&  tail->month == month && tail->date == date && tail->year == year) {
    popTail(); 
  } else { 
    curr = head;

    while(curr && curr->name != name || curr && curr->month != month || curr && curr->date != date || curr && curr->year != year) {
      curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    curr->prev = curr->next = NULL;
    free(curr);
  }
}

void addPatient(){
    char month[255], name[255];
    int patients, cure;
    int date, year;
    int redo = 0;
    do{
        redo = 0;
        scanf("%d %d", &patients, &cure);
        getchar();
        scanf("%d %[^\n] %d - %[^\n]", &date, &month, &year, &name);
        getchar();
        int len = strlen(name);
        for(int i = 0; i < len; i++){
            if(name[i] >= 'A' && name[i] <= 'Z'){
                redo = 1;
                break;
            }
        }
    }while(redo = 1);
}

int main(){
    int t;
    for(int i = 1; i <= t; i++){
       addPatient();
    }
}