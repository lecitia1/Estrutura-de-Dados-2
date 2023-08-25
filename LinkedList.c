#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

void init(LinkedList *list){     //inicializando a estrutura
    log_info("inicializando a lista");
    log_trace("init->");
    if(list!=NULL){
    list->first=NULL;
    list->size=0;
    log_debug("list->first: %p", list->first);
	log_debug("list->size: %d", list->size);
	log_trace("init <-");
    }
}

int enqueue(LinkedList *list, void *data) { //inserção de elementos
    Node *newNode = (Node*)malloc(sizeof(Node)); //reserva espaço novo na memória para caber um nó da lista
    if (newNode==NULL) return -1; //se não houver espaço, avisa o usuário retornando -1
    newNode->data = data;         //inicializamos as variáveis do novo nó
    newNode->next = NULL;        //o nó que será inserido será o último da lista, sem próximo.
    if (isEmpty(list))            //verifica se a lista estiver vazia
        list->first = newNode;    //novo nó é o primeiro
    else {                        //caso nao seja o ultimo, mostrar qual é
        Node *aux = list->first;  //aux aponta para o primeiro
        while (aux->next != NULL) //enquanto não for o último nó
            aux = aux->next;      //aux avança para o nó seguinte
        aux->next = newNode;      //último nó aponta para o novo nó
    }
    list->size++;
    return 1;
}

void* dequeue(LinkedList *list);{





}

void* first(LinkedList *list) {//descobrir qual dado é o primeiro da lista
    log_info("Buscando o primeiro elemento da lista");
	log_trace("first ->");
    if (isEmpty(list)){
		log_warn("Lista vazia");
		log_trace("first <-");
		return NULL;
	} else {
		log_debug("first: %p", list->first);
		log_trace("first <-");
		return list->first;
	}
}
}
void* last(LinkedList *list){
	log_info("Buscando o último elemento da lista");
	log_trace("last ->");
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
