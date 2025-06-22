/******************************************************************************
Situação problema: Armazenar lista de contatos (Primeiro Nome, Sobrenome, E-mail, Telefone, CPF); Sem quantitativo máximo.
1 - Os dados devem ficar armazenados em uma Lista duplamente Encadeada com Header; 
2 – O usuário irá inserir os contatos, o programa deverá colocar, no momento da inserção, na posição correta; conforme ordem ALFABÉTICA CRESCENTE DO SOBRENOME(string) . Se o sobrenome estiver repetido, deverá verificar o primeiro nome. Considerar que não haverá Sobrenome+ Nome repetidos;
A implementação da lista deverá permitir (pelo menos), através de menu de acesso, realizar as operações:
a- Inserir em qualquer posição (começo, meio ou final), conforme ordem alfabética crescente do Sobrenome+nome. O usuário informa os dados do contato e o programa insere na lista, na posição correta da ordem alfabética.
b- Remover itens de qualquer posição (começo, meio ou final);
c- Consultar itens de qualquer posição; (Consultar por posição);
d- Listar os itens da lista; (Percorrer a lista). Sugestão: quando listar todos os itens, incluir os endereços do item, próximo nodo e nodo anterior para cada item. 
1 - O grupo deverá demonstrar e testar os  processos que deve acontecer em cada um dos itens (a,b,c,d);
2 - descrever quais problemas podem ocorrer nos itens (a,b,c,d); (se houver);
3 - descrever (pelo menos) um caso de teste para cada item (a,b,c,d) que permitam saber se estes estão funcionando adequadamente;
4 – demonstrar inserção de (pelo menos 5 elementos), demonstrando inserções no começo, meio e final;
5 – demonstrar remoção de (pelo menos 3 elementos), demonstrando remoções no começo, meio e final;
6 - demonstrar outras situações com possibilidade de erros.
Enviar os códigos-fonte anexos.
Dicas:
a - não usar atribuição (=) para copiar strings, use strcpy;
b - implemente uma lista que tenha uma função que permita inserir em qualquer posição, indicada pelo número;
c - Sobrenome e Nome devem ser armazenados separadamente, mas para fins de comparação para achar o ponto de inserção, pode-se manipulá-los concatenados;
d - implemente uma função que identifique qual a posição um registro deve ser inserido para manter a ordem alfabética crescente de Sobrenome + Nome, por exemplo int posicao(Lista *l, char sobrenome[]);
e - usando a posição descoberta na dica d, insira o contato na posição correta com a função da dica b;
Material strings, ordem alfabética:
https://docs.google.com/presentation/d/1XlDy5KNN2HrbIcn3nBvt0UjBHLuN7NWWwz3B1D0-Z9Y/edit#slide=id.g3ef17badb0_0_554
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    char nome[100];
    char sobrenome[100];
    char email[150];
    char telefone[15];
    char cpf[15];
}contato;

typedef struct no{
    contato dado;
    struct no* next;
    struct no* prev;
}tno;

typedef struct{
    tno* first;
    tno *last;
    int size;
}tlista;

void criar(tlista *l){
    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}//criar

int empty(tlista *l){
    if(l->first==NULL){
        return 1;
    }
    else{
        return 0;
    }
}//empty

int tamanho(tlista *l){
    return l->size;
}//tamanho


int insert(tlista *l, contato c, int p){
    
    if(p>tamanho(l) || p<0){ ////encontrar posição p; se não existe ou não é a ultima retornar erro
        printf("Posicao invalida!\n");
        return 0;
    }
    
    tno *novo = (tno*)malloc(sizeof(tno));//ALOCAR NOVO NÓ - Verificar se ALOCAÇÃO ocorreu corretamente;
	if (novo != NULL){
	   novo->dado = c;
	   //strcpy(novo->dado.nome,c.nome);
	   //strcpy(novo->dado.sobrenome,c.sobrenome);
	   //strcpy(novo->dado.email,c.email);
	   //strcpy(novo->dado.telefone,c.telefone);
	   //strcpy(novo->dado.cpf,c.cpf);
	   
	   novo->next = NULL;// proximo do novo no aponta inicialmente para null
	   novo->prev = NULL;// anterior do novo no aponta inicialmente para null
	   
	  
	  //condicao lista vazia
	  if(l->size ==0){
	      l->first = novo;
	      l->last = novo;
	  }
	  //condicao inserir no inicio
	  else if(p==0){
	      novo->next = l->first;
	      l->first->prev = novo;
	      l->first = novo;
	  }
	  
	  //condicao inserir no final
	  else if(p==tamanho(l)){
	      novo->prev = l->last;
	      l->last->next = novo;
	      l->last = novo;
	      
	  }
	  
	  //condicao inserir no meio
	  else{
	    tno* aux_next;
	    aux_next = l->first;
	    for (int i = 0; i<p; i++){//laço percorre até o elemento daposição p
	        aux_next = aux_next->next;
	    }
        aux_next->prev->next = novo;//elemento anterior
        novo->prev = aux_next->prev; //elemento anterior
        aux_next->prev = novo;//elemento seguinte
        novo->next = aux_next;//elemento seguinte
	  }
	  
	   (l->size)++;
	   printf("\nContato inserido com sucesso na lista!\n");
	   return 1;
	}
	else{
	   printf("\nErro na alocacao da memoria. Tente novamente.\n");
	   return 0;
	}
    
}//insert

int posicao(tlista *l, contato c) {
    tno* atual = l->first;
    int pos = 0;

    char entrada[200];
    strcpy(entrada, c.sobrenome);
    strcat(entrada, c.nome);

    while (atual != NULL) {
        char comparada[200];
        strcpy(comparada, atual->dado.sobrenome);
        strcat(comparada, atual->dado.nome);
        
        if (strcmp(entrada, comparada) <= 0) {// Se a entrada for menor ou ingual, a posicao de insercoa eh a atual
            return pos;
        }
        
        atual = atual->next;
        pos++;
    }
    return l->size;//se chegar ao final da lista, entra no final.
}

void lerContato(contato* c){
    printf("Informe os dados do novo contato... \n");
    printf("Nome: ");
    scanf("%99s",c->nome);getchar();//limita caracteres para impedir estouro de buffer
    printf("\nSobrenome: ");
    scanf("%99s",c->sobrenome);getchar();
    printf("\nEmail: ");
    scanf("%149s",c->email);getchar();
    printf("\nTelefone: ");
    scanf("%14s",c->telefone);getchar();
    printf("\nCPF: ");
    scanf("%14s",c->cpf);getchar();
}//lerContato

contato criarContato(){
    contato c;
    lerContato(&c);
    return c;
}



void listar(tlista *l){
    tno* aux_next;
    aux_next = l->first;
    if(l->size ==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i=0; i<tamanho(l);i++){
            printf("%d, %s\n",i,aux_next->dado.nome);
            aux_next = aux_next->next;
        }
    }
}//listar


int main()
{

    //Cria lista
    tlista lista;
    tlista *plista =&lista; 
    criar(plista);
    
    //Insere 1ro contato na lista
    contato a = criarContato();
    insert(plista,a,posicao(plista,a));
    listar(plista);
    
    //Insere 2do contato na lista
    contato b = criarContato();
    insert(plista,b,posicao(plista,b));
    listar(plista);
    
    //Insere 3ro contato na lista
    contato c = criarContato();
    insert(plista,c,posicao(plista,c));
    listar(plista);
    
    //Insere 4to contato na lista
    contato d = criarContato();
    insert(plista,d,posicao(plista,d));
    listar(plista);
    
    
    
    
    
    //printf("Criando novo contato...\n");
    //contato* novo = criarContato();  // Cria e preenche novo contato

    //if (novo != NULL) {
   //     insert(&lista, *novo, lista.size); // Insere no final da lista
   //     free(novo);  // Libera memória alocada dinamicamente
   // }

//NÃO IMPLEMENTADO. ISSO É RESTO DO CODIGO DE PILHAS.    
    /*
    //3. REMOVER 2 NÚMEROS, 
    int aux=0;
    int *p_aux = &aux;
    remover(p_fila, p_aux);
    printf("Numero removido da fila: %d\n", aux);
    int aux2=0;
    int *p_aux2 = &aux2;
    remover(p_fila, p_aux2);
    printf("Numero removido da fila: %d\n", aux2);
    
    //4. SOMAR E INSERIR O RESULTADO  NA FILA,
    int soma=0;
    soma = aux + aux2;
    inserir(p_fila,soma);

    //5.REPITA 3 E 4 ATÉ QUE RESTE APENAS 1 ELEMENTO NA FILA.
    while(tamanho(p_fila)>1){
        remover(p_fila,p_aux);
        remover(p_fila,p_aux2);
        soma = aux+aux2;
        inserir(p_fila,soma);
    }
    
    //Validação
    int restante;
    primeiro(p_fila,&restante);
    printf("Primeiro na fila: %d\n",restante);
    printf("Ultimo na fila: %d\n",p_fila->tail->dado);
    */






    return 0;
}//main
