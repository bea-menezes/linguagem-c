#include <stdio.h>
#include <stdlib.h>

//variaveis globais, 200 para registrar 200 pessoais com 49 caracteres cada
char nome[200][50];
char email[200][50];
int cpf[200];
int op;

void cadastro();
void pesquisa();
void lista();

int main(void){
	
	do{
		system("cls");
		printf("\n---- Menu ---- \n\n1 - Cadastrar\n2- Listar todos\n3 - Pesquisar\n4 - Sair\n");
		scanf("%d", &op);
		
		switch (op){
			case 1:
					cadastro();
				break;
			case 2:
					lista();
				break;
			case 3:
					pesquisa();
				break;
			case 4:
					system("exit");
				break;
			default:
					printf("Opcao invalida!\n");
					system("pause");
				break;
		}
	}while(op!=4);
	
	return 0;
}

void lista(){
	int i;
	
		for(i=0;i<200;i++){
			if(cpf[i] > 0){
			printf("\nNome: %s\nEmail: %s\nCPF: %d\n", nome[i], email[i], cpf[i]);
		}
	}
	
	system("pause");
}

void cadastro() {
	//variavel estatica: continua valendo o mesmo valor
	static int linha; 
	
	do{
		printf("Insira o nome: \n");
		scanf("%s", &nome[linha]);
		scanf("%c"); //limpar o buff de memoria
		printf("Insira o email: \n");
		scanf("%s", &email[linha]);
		
		printf("Insira o CPF: \n");
		scanf("%d", &cpf[linha]);
		
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		
		linha++; //armazena os dados na linha 0, rodou, proximo vai ser armazenado na linha 1
		
	}while(op == 1);
}

void pesquisa(){
	int cpf_pesquisa;
	int i;
	
	char email_pesquisa[50];
	
	do{
		printf("\nDigite 1 para pesquisar por CPF ou 2 para pesquisar o E-mail ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
					printf("Digite o CPF: ");
					scanf("%d", &cpf_pesquisa);
					
					for(i=0;i<200;i++){
						if(cpf[i] == cpf_pesquisa){
							printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
						}else{
							break;
						}
					}
				break;
			case 2:
					printf("Digite o E-mail: ");
					scanf("%s", &email_pesquisa);
					
					for(i=0;i<200;i++){
						if(strcmp(email[i], email_pesquisa) == 0){
							printf("\nNome: %s\nEmail: %s\nCPF: %d", nome[i], email[i], cpf[i]);
						}
					}
				break;
			default:
					printf("Opcao invalida!");
				break;
		}
		
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		
	}while(op == 1);
}














