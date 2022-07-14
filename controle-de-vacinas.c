#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Cadastro {
char cpf[100];
char nome[100];
char vacina[100];
char data[10];
char numeroLote[100];
};

struct Cadastro cadastrarVacinado() {
 
 	struct Cadastro vacinado;
 	
 	//cpf
	printf("Digite o CPF do paciente:\n");
	fflush(stdin);
	gets(vacinado.cpf);
	//nome
	printf("Digite o nome do paciente:\n");
	fflush(stdin);
	gets(vacinado.nome);
	//vacina
	printf("Digite a vacina aplicada:\n");
	fflush(stdin);
	gets(vacinado.vacina);
	//data
	printf("Digite a data de aplicação no formato (dd/mm/aaaa):\n");
	fflush(stdin);
	gets(vacinado.data);
	//lote
	printf("Digite o numero do lote da vacina: \n");
	fflush(stdin);
	gets(vacinado.numeroLote);
	
	return vacinado;
			
 }
 
void listaAplicacoes(struct Cadastro cadastrados[999], int cont) {
 
int i;
for (i = 0; i < cont; i++) {

printf("Código = %d\n", i);
printf("Cpf = %s\n", cadastrados[i].cpf);
printf("Nome = %s\n", cadastrados[i].nome);
printf("Vacina = %s\n", cadastrados[i].vacina);
printf("Data = %s\n", cadastrados[i].data);
printf("Lote = %s\n", cadastrados[i].numeroLote);
printf("========================================\n");
};
 	
 };
 
void consultaCpf(struct Cadastro consulta[999], int cont2) {
	
	int j;
	char cpfConsulta[100];
	
		printf("Digite o CPF para consulta:\n");
		fflush(stdin);
		gets(cpfConsulta);
		
		for (j = 0; j < cont2; j++){
		if (strcmp(cpfConsulta, consulta[j].cpf) == 0){
			cont2 = j;
			
		 printf("========================================\n");	
		 printf("Código = %d\n", j);
         printf("Cpf = %s\n", consulta[j].cpf);
         printf("Nome = %s\n", consulta[j].nome);
         printf("Vacina = %s\n", consulta[j].vacina);
         printf("Data = %s\n", consulta[j].data);
         printf("Lote = %s\n", consulta[j].numeroLote);
         printf("========================================\n");	   
	}
	
	};		
  };



void main() {
	
setlocale(LC_ALL, "Portuguese");

int opcao = 0;
int codigo = 0;
struct Cadastro cadVacinado[999];

do{
		printf("\nControle de vacinação contra a Covid-19\n\n");
		printf("                MENU\n\n");
		printf("Digite a opção desejada:\n\n 1 - Cadastrar Vacina\n 2 - Listar Aplicações\n 3 - Consulta por CPF\n 4 - Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
		
		case 1: {
		printf("\nCadastro de Vacina\n\n");
			cadVacinado[codigo] = cadastrarVacinado();
			codigo++;
			break;
		}
		case 2: {
		printf("\nLista de aplicacões\n\n");
			listaAplicacoes(cadVacinado, codigo);
			break;
		}
		case 3: {
		printf("\nConsulta por CPF\n");
			consultaCpf(cadVacinado, codigo);
			break;
		}
		case 4: {
		printf("\nSair");
			break;
		}
		default : {
			printf("\nOpção Invalida\n");
			break;
		}
	}
	} while (opcao != 4);

}
