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
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int main()
{

    //Iniciacao da variaveis, criacao da lista
    tlista lista;
    tlista *plista =&lista; 
    criar(plista);
    
    int opcao = 0;
    
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
    
    //Menu - Laco de repeticao do while para permanecer no menu
    
    do{
        //Menu de opcoes
        printf("\n<<< SISTEMA DE CODIGOS NUMERICOS >>>\n");
	    printf("Escolha um opcao:\n");
	    printf("1 - Consultar\n");
	    printf("2 - Inserir\n");
	    printf("3 - Remover\n");
	    printf("4 - Listar\n");
	    printf("5 - Teste Funcionamento")
	    printf("0 - Sair\n");
	    
	    if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");
            while (getchar() != '\n'); 
            opcao = -1;
            continue;
        }
        getchar();
	    
	    switch(opcao){
	        
	        //OPCAO CONSULTA DE CODIGO
	        case 1:
	            consultar(lista, ocupados);
	            exibe_lista(lista, ocupados, tamanho);
                break;
	           
		    //OPCAO INSERCAO DE CODIGO
		    case 2:
		        ocupados = inserir(lista, ocupados);
		        exibe_lista(lista, ocupados, tamanho);
		      break;
		      
		    // OPCAO EXCLUIR
		    case 3:
		        ocupados = excluir(lista, ocupados);
                exibe_lista(lista, ocupados, tamanho);
                break;
		    //OPCAO EXIBIR      
		    case 4:
		        exibe_lista(lista, ocupados, tamanho);
		        printf("Tamanho total da lista: %d\n", tamanho);
		        break;
		    case 5:
		        //implementar
		        break;
		    default:
		    printf("Opção inválida.\n");
		    
		    
		    
	    }//switch(opcao)
	    
	    
        
        
    }while(opcao!=0);
    
    
   






    return 0;
}//main
