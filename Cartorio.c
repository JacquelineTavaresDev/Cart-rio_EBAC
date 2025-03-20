#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o �w� � para escrever "write"
	fprintf(file,"CPF: "); //informa��o para o usu�rio
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); 
		
	file = fopen(arquivo,"a"); //Abrindo o arquivo e o �a� � para atualizar o arquivo
	fprintf(file,"\nNome Completo: "); 
	fprintf(file,nome);  
	fclose(file); 
	
	file = fopen(arquivo,"a");
	fprintf(file," "); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome); 
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s",cargo); 
		
	file = fopen(arquivo,"a"); 
	fprintf(file,"\nCargo: "); 
	fprintf(file,cargo); 
	fclose(file); 
	
	file = fopen(arquivo,"a"); //Abrindo o arquivo e o �a� � para atualizar o arquivo
	fprintf(file,"\n\n"); //Separando informa��es no sistema
	fclose(file); //fecha o arquivo
	
	system("pause");
		
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	//Inicio da cria��o de vari�veis/string
	char cpf[40]; 
	char conteudo[200]; //Todas as informa��es coletadas do usu�rio
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Escolha do usu�rio
	scanf("%s",cpf); 
	printf("\n"); //Separando informa��es no sistema
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrir o arquivo e "r" � para ler o arquivo
	
	if(file == NULL) //Se o sistema receber uma informa��o que n�o possui, segue mensagem
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
		printf("\n");
	}
	
	if(file) //Mostrando ao usu�rio as informa��es do arquivo
	{
		printf("Essas s�o as informa��es do usu�rio:\n\n");
		printf("%s",conteudo);
	}
	
	while(fgets(conteudo, 200,file) != NULL) //Mostrando ao usu�rio as informa��es do arquivo
	{
		printf("%s",conteudo);
	}		
	
	system("pause");
	
	fclose(file); //fecha o arquivo
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistem
{
	//Inicio da cria��o de vari�veis/string
	char cpf[40]; //char tamb�m pode receber n�meros e para gerenciamento de strings ele funciona melhor
	char conteudo[200]; //Todas as informa��es coletadas do usu�rio
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser deletado: "); //Escolha do usu�rio
	scanf("%s",cpf); 
		
	remove(cpf); //fun��o que deleta os usu�rios
	
	FILE *file; 
	file = fopen(cpf,"r"); 
	fclose(file); 
	
	if(file == NULL) //Se o sistema receber uma informa��o que n�o possui, segue mensagem
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0; //definindo as vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); //fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls"); 
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consultar(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
						
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
					
		} // fim da sele��o
	
	}
}

