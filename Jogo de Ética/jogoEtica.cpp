#include<stdio.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

int sleep = 30;

int resposta(int res, int resJ){	//fun��o para verificar se a resposta est� correta
	
	int pt=0;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //fun��o para mudar a cor
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	//salva a cor inicial da letra
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
	
	if(res == resJ){
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n Muito Bem, resposta correta\n\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		pt++;
	}else{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  //faz o texto ficar vermelho
		printf("\n Resposta incorreta, a correta seria a %d\n\n",res);
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
	}
	
	return pt;		//retorna um se a resposta estiver correta, ou zero se estiver incorreta
}

int mostraFile(char nome[], char pessoa[10]){	//fun��o para importar o arquivo
	
	FILE *testFile;
	char c;

	testFile = fopen(nome,"r");		//abre o arquivo para leitura

	if ((testFile == NULL))  // Se houve erro na abertura
 	 {
  	   printf("Problemas na abertura do arquivo\n");
		return 0;
 	 }

	setlocale(LC_ALL,"Portuguese");

	rewind(testFile);	//coloca o cursor no inicio do arquivo

	while(!feof(testFile)){		//continua escrevendo enquanto n�o chegar no final do arquivo
		c = fgetc(testFile);
	
		if(c == '@' ){
			printf("\n");		//pula linha se encontrar "@" no arquivo
		}else if(c == '�'){
			break;
		}else if(c == '$'){		
			printf("\n\n");		//pula duas linhas se encontrar "$" no arquivo
			system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar se encontrar "$" no arquivo
			system("cls");		//apaga a tela do programa se encontrar "$" no arquivo
		}else if(c == '#'){
			printf("\n\t<%s>", pessoa);
		}else{
			printf("%c",c);		//escreve os caracteres presentes no arquivo
		}
		Sleep(sleep);		//mostra um caractere de cada vez
	}
}

int menu(){		//fun��o para executar o menu do jogo
	int num, aux;
	char ins[] = "instrucoes.txt", cre[] = "creditos.txt", nome[10];
	printf("################################################################################\n");
	printf("########                                                                ########\n");
	printf("########                           �TICA:                               ########\n");
	printf("########                     FIL�SOFOS ENTRE N�S                        ########\n");
	printf("########                                                                ########\n");
	printf("########                                                                ########\n");
	printf("################################################################################\n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                               1. Jogar                                         \n");
	printf("                               2. Instru��es                                    \n");
	printf("                               3. Cr�ditos                                      \n");
	printf("                               4. Sair                                          \n");
	printf("                                                                                \n");
	printf("Digite o n�mero que corresponde ao que voc� deseja fazer: ");
	scanf("%d", &num);
	switch(num){		
		case 1:					//se o jogador digitar 1 inicia o jogo
			aux=0;
			system("cls");		
			return 1;	
			break;
		case 2:					//se o jogador digitar 2 mostra as instru��es do jogo
			aux=0;
			system("cls");
			mostraFile(ins, nome);
			system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
			break;
		case 3:					//se o jogador digitar 3 mostra os cr�ditos do jogo
			aux=0;
			system("cls");
			mostraFile(cre, nome);
			system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
			break;
		case 4:					//se o jogador digitar 4 acaba o jogo
			aux=0;
			return 0;
			break;
		default:				//se o jogador digitar algo inv�lido o programa solicita que o jogador digite novamente
			system("cls");			//apaga a tela do programa
			menu();
			break;
	}
	getch();				//o programa s� continua se o usu�rio digitar alguma tecla
	system("cls");			//apaga a tela do programa
	menu();					//busca a fun��o menu
}

main(){				
	
//para abrir em fullscreen	
keybd_event ( VK_MENU, 0x36, 0, 0 ); 
keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

//salva a cor inicial da letra
GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
saved_attributes = consoleInfo.wAttributes;
    
setlocale(LC_ALL,"Portuguese");//para poder usar acento nas palavras

int i,tam=0,right=0,cav,title,res1, x;
float pontos=0, aproveitamento;
char alt,title2[20],nome[10],meioConversa[]=" Agora sim, ",intro[] = "intro.txt",caverna[]="caverna.txt",conversa[]="conversaGarota.txt",dpconver[]= "depoisConversa.txt",rio[]="rioConversa.txt",ari[]="aristoteles.txt",
	platao[]="platao.txt",dpPlatao[]="depoisPlatao.txt",agostinho[]="agostinho.txt",marx[]="marx.txt",eti[]="etica.txt",etiFim[]="eticaFim.txt";

if (menu()==0){			//busca a fun��o menu
	return 0;
}

mostraFile(intro, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);  //faz o texto do printf ficar verde
printf("\n Voc� sabe que caverna � essa?\n ");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Caverna do drag�o\n ");
printf("2.Caverna de Plat�o\n ");
printf("3.Caverna de Arist�teles\n ");
printf("4.Outra Caverna\n \n R:");
scanf("%d",&cav);

if(resposta(2,cav) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;

mostraFile(caverna, nome);   //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
printf(" Qual o seu nome?\n ");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
fflush(stdin);   //limpa buffer

gets(nome);  //pega o nome do jogador

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
printf("\n <%s> %s. E o seu?\n\n",nome,nome); 
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal


mostraFile(conversa, nome);   //busca a fun��o mostraFile e insere o arquivo no programa

do{
system("cls");		//apaga a tela do programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
printf("<Garotinha> - Ent�o qual � a sua corrente �tica?\n ");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Kantiana\n");
printf(" 2.Das virtudes\n");
printf(" 3.Utilitarista\n");
printf(" 4.Egoismo\n");
printf(" 5.Crist�\n \n R:");
scanf("%d",&title);//pega a corrente �tica

switch(title){//decide o titulo de acordo com a corrente �tica
	case 1:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n\tVoc� ser� %s, O(A) Kantiano(a)",nome);
		x=1;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		strcpy(title2,"O(A) Kantiano(a)");
		break;
	case 2:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n\tVoc� ser� %s, O(A) Virtuoso(a)",nome);
		x=1;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		strcpy(title2,"O(A) Virtuoso(a)");
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n\tVoc� ser� %s, O(A) Utilitarista",nome);
		x=1;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		strcpy(title2,"O(A) Utilitarista");
		break;
	case 4:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n\tVoc� ser� %s, O(A) Egoista",nome);
		x=1;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		strcpy(title2,"O(A) Egoista");
		break;
	case 5:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //faz o texto ficar verde
		printf("\n\tVoc� ser� %s, A(O) Crist�(o)",nome);
		x=1;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		strcpy(title2,"A(O) Crist�(o)");
		break;
	default:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //faz o texto ficar vermelho
		printf("\n Op��o Inv�lida, tente novamente.\n");
		x=0;
		SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
		system("pause");		//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
		break;
}
}while(x == 0);		//repete a pergunta caso a resposta seja invalida

mostraFile(dpconver, nome);   //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);    //faz o texto ficar verde
printf("Qual corrente �tica defende que deve-se buscar o melhor para o maior numero de pessoas?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Utilitarista\n");
printf(" 2.Kantiana\n");
printf(" 3.Crist�\n");
printf(" 4.N.D.A\n \n R:");
scanf("%d",&res1);

if(resposta(1,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;

mostraFile(rio, nome);     //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);     //faz o texto ficar verde
printf(" Segundo Arist�teles, como a virtude � encontrada?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);    //volta o texto para a cor normal

printf("\n 1.A virtude � encontrada entre o mundo sens�vel e o mundo intelectual\n");
printf(" 2.A virtude � encontrada, com o uso da raz�o, no meio termo entre extremos\n");
printf(" 3.A virtude � encontrada na religi�o, seguindo os mandamentos de Deus\n");
printf(" 4.A virtude � encontrada na ideologia da classe dominante\n \n R:");
scanf("%d",&res1);

if(resposta(2,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;
	
mostraFile(ari, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf(" \"Os sistemas morais s�o fixos e imut�veis, pois n�o est�o relacionados com as transforma��es hist�rico-sociais.\"\n");
SetConsoleTextAttribute(hConsole, saved_attributes);    //volta o texto para a cor normal
printf("\n A afirma��o acima � Verdadeira(v) ou Falsa(f)?\n R:");
fflush(stdin);          
scanf("%c",&alt);

if((alt == 'v')||(alt == 'V')){
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  //faz o texto ficar vermelho
	printf("\n Resposta incorreta!\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);   //volta o texto para a cor normal
	printf("\n\t<Sujeito> - Mesmo voc� respondendo incorretamente, deixarei voc� se alimentar.\n");
}else if((alt == 'f')||(alt == 'F')){
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);  //faz o texto ficar verde
	printf("\nMuito bem, resposta correta!\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);   //volta o texto para a cor normal
	pontos++;
}else{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);  //faz o texto ficar vermelho
	printf("\nAlternativa inv�lida!\n");
	SetConsoleTextAttribute(hConsole, saved_attributes);   //volta o texto para a cor normal
	printf("\n<Sujeito> - Mesmo voc� respondendo incorretamente, deixarei voc� se alimentar\n");
}

mostraFile(platao, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

mostraFile(dpPlatao, nome);   //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);  //faz o texto ficar verde
printf("\nSegundo a �tica agostiniana qual o modo de alcan�ar a felicidade?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);   //volta o texto para a cor normal

printf("\n 1.Agindo com base apenas na raz�o\n");
printf(" 2.Aceitando as coisas do jeito que elas s�o\n");
printf(" 3.Fazendo tudo o que quiser, sendo certo ou errado\n");
printf(" 4.Buscando conhecimento e fazendo o bem visando o encontro com Deus\n \nR:");
scanf("%d",&res1);

if(resposta(4,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
pontos++;

mostraFile(agostinho, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf("\n Segundo Marx, a �tica corresponde a qual ideologia?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);    //volta o texto para a cor normal

printf("\n 1.Ideologia da maioria das pessoas\n");
printf(" 2.Ideologia de cada pessoa\n");
printf(" 3.Ideologia da classe dominante\n");
printf(" 4.ideologia da classe religiosa\n \nR:");
scanf("%d",&res1);

if(resposta(3,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
pontos++;

mostraFile(marx, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf("\n Escolha um lado para acabar logo com essa discuss�o e continuar seu caminho: \n");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Immanuel Kant\n");
printf(" 2.Georg Hegel.\n \nR:");
scanf("%d",&res1);

if(res1 == 1)
printf("\n\t<Kant> - Est� vendo, Hegel? � um(a) estranho(a) sensato(a)!\n");
if(res1 == 2)
printf("\n\t<Hegel> - Voc� � mais inteligente do que parece!\n");

mostraFile(eti, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);  //faz o texto ficar verde
printf("Como podemos diferenciar �moral� e ��tica�?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);   //volta o texto para a cor normal

printf("\n 1.N�o podemos diferenciar, s�o palavras sin�nimas\n");
printf(" 2.Moral � um conjunto de valores, e �tica � a reflex�o sobre esses valores\n");
printf(" 3.Moral � a pr�tica da �tica no nosso dia a dia\n");
printf(" 4.Moral � sin�nimo de ��tica aplicada�\n \n R:");
scanf("%d",&res1);

if(resposta(2,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;
	
printf("\n\n");      //pula duas linhas
system("pause");    //pausa o programa e pede para o jogador apertar qualquer tecla para continuar
system("cls");      //apaga a tela do programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf("Do que se trata o Imperativo Categ�rico e quem desenvolveu este conceito?\n");
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Kant - Se trata de um conjunto de deveres, que devem ser seguidos visando a consequ�ncia de cada a��o\n");
printf(" 2.Hegel - Se trata de uma moralidade, que se modifica ao longo da hist�ria e das sociedades\n");
printf(" 3.Kant - Se trata de uma determina��o da a��o moralmente correta, que deve ser seguida sempre, caso possa ser universalizada\n");
printf(" 4.Hegel - Se trata de uma �tica, que se constroi a partir de uma argumenta��o que leva a um entendimento entre os individuos\n \n R:");
scanf("%d",&res1);

if(resposta(3,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;

printf("\n\n");		//pula duas linhas
system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
system("cls");		//apaga a tela do programa

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf("Do que se trada a �tica do Discurso e quem desenvolveu este conceito?\n"); 
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

printf("\n 1.Habermas - Se trata de uma raz�o comunicativa, a qual se constroi por uma argumenta��o entre sujeitos que cooperam na busca pela verdade\n");
printf(" 2.Marx - Se trata de um conjunto de regras religiosas, que foram definidas atrav�s do discurso de l�deres religiosos.\n");
printf(" 3.Marx - Se trata de uma raz�o comunicativa, a qual se constroi por uma argumenta��o entre sujeitos que cooperam na busca pela verdade\n");
printf(" 4.Habermas - Se trata de um conjunto de regras, que foram definidos a partir da ideologia da classe dominante\n \n R:");
scanf("%d",&res1);

if(resposta(1,res1) == 1)	//verifica se a resposta esta certa usando a fun��o "resposta"
	pontos++;
	
printf("\n\n");		//pula duas linhas
system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
system("cls");		//apaga a tela do programa

mostraFile(etiFim, nome);    //busca a fun��o mostraFile e insere o arquivo no programa

aproveitamento=(pontos/9)*100; //Calcula o aproveitamento do jogador

SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
printf("\n\tFIM\n");												
printf("\n\t%s %s, voc� acertou %.0f perguntas.\n", nome, title2,  pontos); //Mostra o nome e a quantidade de acertos do jogador
SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal

if(aproveitamento >= 60){
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);   //faz o texto ficar verde
	printf("\n\tAproveitamento = %.2f %%", aproveitamento); //Mostra essa mensagem se o aproveitamento for maior que 60%
	printf("\n\tVoc� recebeu o t�tulo de %s, o(a) �tico(a)!!!", nome);
	SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
}else{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);    //faz o texto ficar vermelho
	printf("\n\tAproveitamento = %.2f %%", aproveitamento);//Mostra essa mensagem se o aproveitamento for menor que 60%
	printf("\n\tVoc� recebeu o t�tulo de %s, o(a) Anti�tico(a)! Estude mais sobre a �tica!\n", nome);
	SetConsoleTextAttribute(hConsole, saved_attributes);  //volta o texto para a cor normal
}

system("pause");	//pausa o programa e pede para o jogador apertar qualquer tecla para continuar
system("cls");		//apaga a tela do programa

menu();		//volta para o menu

}
