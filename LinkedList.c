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

int enqueue(LinkedList *list, void *data) { //"enfileira" inserção de elementos
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

void* dequeue(LinkedList *list);{// "desinfileira" remover o primeiro elemnto da lista
     if (isEmpty(list)) return NULL;//verifica se existe na lista, senao retorna NULL
    //a lista tendo elementos, remove o primeiro e o segundo passa a ser o primeiro
    Node *trash = list->first; //variável que guarda o endereço do nó que será removido
    list->first = list->first->next; //primeiro elemento passa a ser o segundo da lista
    void *data = trash->data; //dado do nó removido
    free(trash);              //libera memória
    list->size--;             //decrementa a quantidade de elementos
    return data;             //retornar o dado que foi removido.


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
int push(LinkedList *list, void *data){//Ao invés de inserir no final da lista, a inserção é feita no início da lista(diferente do enqueue)
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(list)) //se a lista estiver vazia
        list->first = newNode; //novo nó é o primeiro
    else {
        newNode->next = list->first; //o topo atual será o segundo da lista
        list->first = newNode; //o novo nó será o topo
  }
  list->size++;
  return 1;
}

}
void* pop(LinkedList *list){
    return dequeue(list);
}
void* top(LinkedList *list){
    return first(list);
}
bool isEmpty(LinkedList *list);
int indexOf(LinkedList *list, void *data, compare equal);
void* getPos(LinkedList *list, int pos){//igual a getNodeByPos, a diferença é que retornamos o dado e não o endereço do nó.
   Node *aux = getNodeByPos(list,pos);
   if (aux==NULL)
        return NULL;
   else
        return aux->data;
}
Node* getNodeByPos(LinkedList *list, int pos){//retornar o endereço do nó (Node) localizado em uma determinada posição da lista
    if (isEmpty(list) || pos>=list->size) return NULL;//condição de parada /contador é igual a posição desejada retornamos o ponteiro do nó em que estamos posicionados.
    Node *aux = list->first;
    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    return aux;
}
int add(LinkedList *list, int pos, void *data){//a função permite a inserção de um único dado em uma determinada posição da lista.
    if(pos <= 0) return push(list, data);//verifica se a posição inserida é o inicio, se for usa a função push
    Node *aux = getNodeByPos(list, (pos-1));//utiliza a função aux getNodeByPos p/ descobrir o nó da posição anterior a posição que queremos inserir (pos-1):
    if(aux==NULL) return -2;//Retornamos -2 para informar que a posição fornecida é inválida
    Node *newNode= (Node*) malloc(sizeof(Node));//Caso a posição seja válida alocamos um novo espaço na memória para receber o novo nó
    if(newNode==NULL) return -1;//memória insuficiente
    newNode->data = data;
    newNode->next = NULL; 
    //agora pode inserir o novo nó dentro da nossa lista:
    newNode->next = aux->next; //Novo nó aponta para a posição seguinte
    aux->next = newNode; //posição do auxiliar aponta para o novo nó
    list->size++;
    return 1;
}
int addAll(LinkedList *listDest, int pos, LinkedList *listSource){//adicionar uma lista (lista de origem) dentro de outra lista (lista de destino), a partir de uma determinada posição.
    if (listDest==NULL || isEmpty(listDest)) return -1;//verificar se essas listas possuem elementos para que faça sentido a inserção de uma em outra.
    if (listSource==NULL || isEmpty(listSource)) return -2;
    
}
void* removePos(LinkedList *list, int pos);
bool removeData(LinkedList *list, void *data, compare equal);
