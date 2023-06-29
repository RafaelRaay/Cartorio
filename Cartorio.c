#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings(conjunto de varíaveis)

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de varíaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de varíaveis/string
 	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE * file; //Cria um novo arquivo no banco de dados
	file = fopen(arquivo, "w"); //Criando o arquivo na pasta onde foi salvo o sistema
	fprintf(file, cpf); //Salva o valor da variável 
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Para atualizar a informação do arquivo já criado
	fprintf(file, ","); //Colocando uma vírgula para o espaçamento 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //Salvando o valor da variável "nome" dentro do arquivo 
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
int consulta() //Função responsável por consultar as informações do usuário 
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Consultando informação do usuário 
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf, "r"); //Para ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //!= "se não for igual a nulo"
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}
int deletar() //Função responsável por deletar as informações do usuário
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Deletando as informações do usuário 
	scanf("%s", cpf); //Salva o valor na varíavel
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu 
		printf("Escola a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:"); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário 
	
		system("cls"); //Deletar mensagens anteriores para a não poluição ao usuário/ Responsável por limpar a tela
	
		switch(opcao) //Início da seleção e implementação da tomada de decisão conforme a alternativa escolhida 
		{
			case 1:
			registro(); //Chamada de funções 
			break;
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;
		} //Fim da seleção
	}
}
