#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��p de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bibliotca respons�vel por cuidar da string

int registro() //Fun��o respons�vel por cadastrar usuarios.
{
	// In�cio da cria��o de vari�veis/string  //string esta entre[]
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando info do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, E ESCREVER COM O "w'
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // coletando info do usu�rio
	scanf("%s",nome);  // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando info do usu�rio
	scanf("%s",sobrenome);  // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); // coletando info do usu�rio
	scanf("%s",cargo); // %s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consulta() //Fun��o respons�vel por cosultar usuarios.
{
	setlocale(LC_ALL, "Portuguese"); // Definir linguaguem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // coletando info do usu�rio
	scanf("%s",cpf);  // %s refere-se a string
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // LER o cpf COM O "R"
	
	if(file==NULL)
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio:"); // coletando info do usu�rio
	printf("%s",conteudo);  // %s refere-se a string
	printf("\n\n");
	
	}
	system("pause");
}

int deletar()  //Fun��o respons�vel por deletar usuarios.
{
		setlocale(LC_ALL, "Portuguese"); // Definir linguaguem
	char cpf[40];
	
	printf("Digitar o CPF do usu�rio ser deletado: "); // coletando info do usu�rio
	scanf("%s", cpf);  // %s refere-se a string
	
	remove(cpf);
	
	FILE*file;   // FILE � da biblioteca
	file = fopen(cpf,"r"); // LER o cpf COM O "R"
	printf("Usu�rio deletado com sucesso!.\n");
	system("pause");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! .\n");
		system("pause");
	}
	
}

int main() 
{
	int opcao=0; // Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system ("cls"); // Respons�vel por limpar a tela

	
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	
		printf("    Cart�rio da EBAC    \n\n"); //Inicio do menu
		printf("     Escolha a op��o desejada do MENU:\n\n"); 
		printf("\t1 - Resgistrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("\t4 - Sair do sistema \n\n");
		
		printf("Op��o: ");//Final do Menu
	
		scanf ("%d", &opcao); //Armazenando Informa��es, escolha do usu�rio

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
		printf ("Op��o Inv�lida\n");
		system("pause");
		break;
	}
	
	
	}	
}
