#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocaçãp de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bibliotca responsável por cuidar da string

int registro() //Função responsável por cadastrar usuarios.
{
	// Início da criação de variáveis/string  //string esta entre[]
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando info do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, E ESCREVER COM O "w'
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // coletando info do usuário
	scanf("%s",nome);  // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando info do usuário
	scanf("%s",sobrenome);  // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // coletando info do usuário
	scanf("%s",cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consulta() //Função responsável por cosultar usuarios.
{
	setlocale(LC_ALL, "Portuguese"); // Definir linguaguem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // coletando info do usuário
	scanf("%s",cpf);  // %s refere-se a string
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // LER o cpf COM O "R"
	
	if(file==NULL)
	{
	printf("Não foi possível abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
	printf("\nEssas são as informações do usuário:"); // coletando info do usuário
	printf("%s",conteudo);  // %s refere-se a string
	printf("\n\n");
	
	}
	system("pause");
}

int deletar()  //Função responsável por deletar usuarios.
{
		setlocale(LC_ALL, "Portuguese"); // Definir linguaguem
	char cpf[40];
	
	printf("Digitar o CPF do usuário ser deletado: "); // coletando info do usuário
	scanf("%s", cpf);  // %s refere-se a string
	
	remove(cpf);
	
	FILE*file;   // FILE é da biblioteca
	file = fopen(cpf,"r"); // LER o cpf COM O "R"
	printf("Usuário deletado com sucesso!.\n");
	system("pause");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! .\n");
		system("pause");
	}
	
}

int main() 
{
	int opcao=0; // Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system ("cls"); // Responsável por limpar a tela

	
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	
		printf("    Cartório da EBAC    \n\n"); //Inicio do menu
		printf("     Escolha a opção desejada do MENU:\n\n"); 
		printf("\t1 - Resgistrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("\t4 - Sair do sistema \n\n");
		
		printf("Opção: ");//Final do Menu
	
		scanf ("%d", &opcao); //Armazenando Informações, escolha do usuário

	system("cls");
	
	switch(opcao)
	{
		case 1: 
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;	
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
		
		default:
		printf ("Opção Inválida\n");
		system("pause");
		break;
	}
	
	
	}	
}
