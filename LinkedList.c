#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void init(LinkedList *list){
    if(list!=NULL){
    list->first=NULL;
    list->size=0;
    }
}

int enqueue(LinkedList *list, void *data){
    Node *newNode = (Node*)malloc(sizeof(Node));//reservar espaço na memória para um nó
    if (newNode==NULL){//se nao houver espaço, retorna -1
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;//o nó que será inserido será o último da lista (sem próximo)
    if (isEmpty(list)){
        list->first = newNode;//se a lista estiver vazia ele será o primeiro elemento da lista.
    }
    else {
        Node *aux = list->first; //aux aponta para o primeiro
        while (aux->next != NULL) //enquanto não for o último nó
            aux = aux->next; //aux avança para o nó seguinte
        aux->next = newNode; //último nó aponta para o novo nó
    }
        list->size++;
    return 1;
}

void* dequeue(LinkedList *list);

void* first(LinkedList *list){
    void* first(LinkedList *list) {//descobrir qual dado é o primeiro da lista
    return (isEmpty(list))?NULL:list->first->data;
}
void* last(LinkedList *list){
    void *data = NULL;
    if (!isEmpty(list)) { //Se a lista não estiver vazia
        Node *aux = list->first; //aux aponta para o primeiro nó
        while (aux->next != NULL) //enquanto não for o último nó
      aux = aux->next; //aux avança para o nó seguinte
    data = aux->data; //endereço de memória do dado no último nó
  }
  return data;
}
int push(LinkedList *list, void *data);
void* pop(LinkedList *list);
void* top(LinkedList *list);
bool isEmpty(LinkedList *list);
int indexOf(LinkedList *list, void *data, compare equal);
void* getPos(LinkedList *list, int pos);
Node* getNodeByPos(LinkedList *list, int pos);
int add(LinkedList *list, int pos, void *data);
int addAll(LinkedList *listDest, int pos, LinkedList *listSource);
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);
