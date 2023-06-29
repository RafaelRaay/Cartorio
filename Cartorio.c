#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings(conjunto de var�aveis)

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de var�aveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de var�aveis/string
 	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE * file; //Cria um novo arquivo no banco de dados
	file = fopen(arquivo, "w"); //Criando o arquivo na pasta onde foi salvo o sistema
	fprintf(file, cpf); //Salva o valor da vari�vel 
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Para atualizar a informa��o do arquivo j� criado
	fprintf(file, ","); //Colocando uma v�rgula para o espa�amento 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //Salvando o valor da vari�vel "nome" dentro do arquivo 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}
int consulta() //Fun��o respons�vel por consultar as informa��es do usu�rio 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Consultando informa��o do usu�rio 
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf, "r"); //Para ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //!= "se n�o for igual a nulo"
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}
int deletar() //Fun��o respons�vel por deletar as informa��es do usu�rio
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Deletando as informa��es do usu�rio 
	scanf("%s", cpf); //Salva o valor na var�avel
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu 
		printf("Escola a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
		system("cls"); //Deletar mensagens anteriores para a n�o polui��o ao usu�rio/ Respons�vel por limpar a tela
	
		switch(opcao) //In�cio da sele��o e implementa��o da tomada de decis�o conforme a alternativa escolhida 
		{
			case 1:
			registro(); //Chamada de fun��es 
			break;
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		} //Fim da sele��o
	}
}
