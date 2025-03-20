#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o “w” é para escrever "write"
	fprintf(file,"CPF: "); //informação para o usuário
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); 
		
	file = fopen(arquivo,"a"); //Abrindo o arquivo e o “a” é para atualizar o arquivo
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
	
	file = fopen(arquivo,"a"); //Abrindo o arquivo e o “a” é para atualizar o arquivo
	fprintf(file,"\n\n"); //Separando informações no sistema
	fclose(file); //fecha o arquivo
	
	system("pause");
		
}

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	//Inicio da criação de variáveis/string
	char cpf[40]; 
	char conteudo[200]; //Todas as informações coletadas do usuário
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Escolha do usuário
	scanf("%s",cpf); 
	printf("\n"); //Separando informações no sistema
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrir o arquivo e "r" é para ler o arquivo
	
	if(file == NULL) //Se o sistema receber uma informação que não possui, segue mensagem
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
		printf("\n");
	}
	
	if(file) //Mostrando ao usuário as informações do arquivo
	{
		printf("Essas são as informações do usuário:\n\n");
		printf("%s",conteudo);
	}
	
	while(fgets(conteudo, 200,file) != NULL) //Mostrando ao usuário as informações do arquivo
	{
		printf("%s",conteudo);
	}		
	
	system("pause");
	
	fclose(file); //fecha o arquivo
	
}

int deletar() //Função responsável por deletar os usuários no sistem
{
	//Inicio da criação de variáveis/string
	char cpf[40]; //char também pode receber números e para gerenciamento de strings ele funciona melhor
	char conteudo[200]; //Todas as informações coletadas do usuário
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser deletado: "); //Escolha do usuário
	scanf("%s",cpf); 
		
	remove(cpf); //função que deleta os usuários
	
	FILE *file; 
	file = fopen(cpf,"r"); 
	fclose(file); 
	
	if(file == NULL) //Se o sistema receber uma informação que não possui, segue mensagem
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0; //definindo as variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: "); //fim do menu
	
		scanf("%d",&opcao); //armazenando a escolha do usuário
	
		system("cls"); 
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consultar(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
						
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
					
		} // fim da seleção
	
	}
}

