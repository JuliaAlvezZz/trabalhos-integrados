#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct TipoSociologo{
	int cod;
	char nome[100], biografia[2000];
}TipoSociologo;

typedef struct TipoPensamento{
	int cod;
	char pensamento[1000], interp[2000];
}TipoPensamento;

typedef struct TipoRelacionamento{
	int codSociologo, codPensamento;
}TipoRelacionamento;

typedef struct TipoCelulaF *TipoApontadorF;
typedef struct TipoCelulaP *TipoApontadorP;
typedef struct TipoCelulaR *TipoApontadorR;

struct TipoCelulaF{
	TipoSociologo soc;
	TipoApontadorF ant, prox;
};

struct TipoCelulaP{
	TipoPensamento pen;
	TipoApontadorP ant, prox;
};

struct TipoCelulaR{
	TipoRelacionamento rel;
	TipoApontadorR ant, prox;
};

struct TipoListaF{
	TipoApontadorF primeiro, ultimo;
};

struct TipoListaP{
	TipoApontadorP primeiro, ultimo;
};

struct TipoListaR{
	TipoApontadorR primeiro, ultimo;
};

void LFVazia(TipoListaF *lista){
	lista->primeiro=(TipoApontadorF)malloc(sizeof(TipoCelulaF));
	lista->ultimo=lista->primeiro;
	lista->primeiro->ant=NULL;
	lista->ultimo->prox=NULL;
}

void LPVazia(TipoListaP *lista){
	lista->primeiro=(TipoApontadorP)malloc(sizeof(TipoCelulaP));
	lista->ultimo=lista->primeiro;
	lista->primeiro->ant=NULL;
	lista->ultimo->prox=NULL;
}

void LRVazia(TipoListaR *lista){
	lista->primeiro=(TipoApontadorR)malloc(sizeof(TipoCelulaR));
	lista->ultimo=lista->primeiro;
	lista->primeiro->ant=NULL;
	lista->ultimo->prox=NULL;
}

int vaziaF(TipoListaF lista){
	if (lista.primeiro==lista.ultimo){
		return 1;
	}else{
		return 0;
	}
}

int vaziaP(TipoListaP lista){
	if (lista.primeiro==lista.ultimo){
		return 1;
	}else{
		return 0;
	}
}

int vaziaR(TipoListaR lista){
	if (lista.primeiro==lista.ultimo){
		return 1;
	}else{
		return 0;
	}
}

void inserirF(TipoListaF *lista, TipoSociologo soc){
	lista->ultimo->prox=(TipoApontadorF)malloc(sizeof(TipoCelulaF));
	lista->ultimo->prox->ant=lista->ultimo;
	lista->ultimo=lista->ultimo->prox;
	lista->ultimo->soc=soc;
	lista->ultimo->prox=NULL;
}

void inserirP(TipoListaP *lista, TipoPensamento pen){
	lista->ultimo->prox=(TipoApontadorP)malloc(sizeof(TipoCelulaP));
	lista->ultimo->prox->ant=lista->ultimo;
	lista->ultimo=lista->ultimo->prox;
	lista->ultimo->pen=pen;
	lista->ultimo->prox=NULL;
}

void inserirR(TipoListaR *lista, TipoRelacionamento rel){
	lista->ultimo->prox=(TipoApontadorR)malloc(sizeof(TipoCelulaR));
	lista->ultimo->prox->ant=lista->ultimo;
	lista->ultimo=lista->ultimo->prox;
	lista->ultimo->rel=rel;
	lista->ultimo->prox=NULL;
}

TipoApontadorF buscaSociologo(TipoListaF listaSoc, int codSoc){
	TipoApontadorF aux;
	aux=listaSoc.primeiro->prox;
	while (aux!=NULL){
		if (codSoc==aux->soc.cod){
			return aux;
		}
		aux=aux->prox;
	}
	return NULL;
}

TipoApontadorP buscaPensamento(TipoListaP listaPen, int codPen){
	TipoApontadorP aux;
	aux=listaPen.primeiro->prox;
	while (aux!=NULL){
		if (codPen==aux->pen.cod){
			return aux;
		}
		aux=aux->prox;
	}
	return NULL;
}

int buscaRelacionamento(TipoListaR listaRel, int codSoc, int codPen[]){
	TipoApontadorR aux;
	int i=0;
	aux=listaRel.primeiro->prox;
	while (aux!=NULL){
		if (codSoc==aux->rel.codSociologo){
			codPen[i]=aux->rel.codPensamento;
			i++;
		}
		aux=aux->prox;
	}
	return i;
}

void exibir(TipoListaF listaF, TipoListaR listaR, TipoListaP listaP, int op){
	TipoApontadorF auxF, auxF1;
	TipoApontadorR auxR, auxR1;
	TipoApontadorP auxP;
	TipoSociologo aux;
	int codS, codP[20], i, x, maisP, cont=0, contM=0;
	switch(op){
		case 3:
			auxF=listaF.primeiro->prox;
			while (auxF!=NULL){
				printf("                                  Código do sociólogo: %d\n", auxF->soc.cod);
				printf("                                  Nome do sociólogo: %s\n\n", auxF->soc.nome);
				auxF=auxF->prox;
			}
			system("pause");
			break;
		case 4:
			auxF=listaF.primeiro->prox;
			while (auxF!=NULL){
				auxF1=auxF->prox;
				while (auxF1!=NULL){
					if (auxF1->soc.nome[0]<auxF->soc.nome[0]){
						aux=auxF->soc;
						auxF->soc=auxF1->soc;
						auxF1->soc=aux;
						
					}
					auxF1=auxF1->prox;
				}
				auxF=auxF->prox;
			}
			auxF=listaF.primeiro->prox;
			while (auxF!=NULL){
				printf("                                  Código do sociólogo: %d\n", auxF->soc.cod);
				printf("                                  Nome do sociólogo: %s\n\n", auxF->soc.nome);
				auxF=auxF->prox;
			}
			system("pause");
			break;
		case 5:
			auxF=listaF.primeiro->prox;
			while (auxF!=NULL){
				printf("                                  Código do sociólogo: %d\n", auxF->soc.cod);
				printf("                                  Nome do sociólogo: %s\n\n", auxF->soc.nome);
				printf("                                  Biografia resumida: %s\n\n\n", auxF->soc.biografia);
				x=buscaRelacionamento(listaR, auxF->soc.cod, codP);
				for (i=0; i<x; i++){
					auxP=buscaPensamento(listaP, codP[i]);
					printf("                                  Código do pensamento: %d\n", auxP->pen.cod);
					printf("                                  Pensamento:\n                                  \"%s\"\n\n", auxP->pen.pensamento);
					printf("                                  Interpretação:\n                                  %s\n\n\n", auxP->pen.interp);
				}
				printf("                                  ----------------------------------------------------------------------------------\n\n");
				auxF=auxF->prox;
			}
			system("pause");
			break;
		case 6:
			printf("                                  Digite o código de um sociólogo para ver seus pensamentos: ");
			scanf("%d", &codS);
			auxF=buscaSociologo(listaF, codS);
			if (auxF==NULL){
				printf("\n                                  Não há sociólogo com esse código.");
			}else{
				printf("                                  Nome do sociólogo: %s\n\n\n", auxF->soc.nome);
				x=buscaRelacionamento(listaR, codS, codP);
				for (i=0; i<x; i++){
					auxP=buscaPensamento(listaP, codP[i]);
					printf("                                  Código do pensamento: %d\n", auxP->pen.cod);
					printf("                                  Pensamento:\n                                  \"%s\"\n\n", auxP->pen.pensamento);
					printf("                                  Interpretação:\n                                  %s\n\n\n", auxP->pen.interp);
				}
			}
			system("pause");
			break;
		case 7:
			auxR=listaR.primeiro->prox;
			maisP=auxR->rel.codSociologo;
			while (auxR!=NULL){
				codS=auxR->rel.codSociologo;
				cont=0;
				auxR1=listaR.primeiro->prox;
				while (auxR1!=NULL){
					if (auxR1->rel.codSociologo==codS){
					cont++;
					}
					auxR1=auxR1->prox;
				}
				if (cont>contM){
					maisP=codS;
					contM=cont;
				}
				auxR=auxR->prox;
			}
			auxF=buscaSociologo(listaF, maisP);
			printf("                                  Código do sociólogo: %d\n", auxF->soc.cod);
			printf("                                  Nome do sociólogo: %s\n", auxF->soc.nome);
			printf("                                  Pensamentos cadastrados: %d\n\n", contM);
			x=buscaRelacionamento(listaR, auxF->soc.cod, codP);
			for (i=0; i<x; i++){
				auxP=buscaPensamento(listaP, codP[i]);
				printf("                                  Código do pensamento: %d\n", auxP->pen.cod);
				printf("                                  Pensamento:\n                                  \"%s\"\n\n", auxP->pen.pensamento);
				printf("                                  Interpretação:\n                                  %s\n\n\n", auxP->pen.interp);
			}
			system("pause");
			break;
	}
	
}

void alterar(TipoListaF *listaSoc, TipoListaP *listaPen, int op){
	int codS, codP;
	TipoApontadorF auxF;
	TipoApontadorP auxP;
	if (op==1){
		printf("                                  Digite o código do sociólogo que deseja alterar: ");
		scanf("%d", &codS);
		auxF=buscaSociologo(*listaSoc, codS);
		printf("                                  Digite o novo nome do sociólogo: ");
		fflush(stdin);
		gets(auxF->soc.nome);
	}
	if (op==2){
		printf("                                  Digite o código do sociólogo cujo pensamento deseja alterar: ");
		scanf("%d", &codS);
		auxF=buscaSociologo(*listaSoc, codS);
		printf("                                  Digite o código do pensamento que deseja alterar: ");
		scanf("%d", &codP);
		auxP=buscaPensamento(*listaPen, codP);
		printf("                                  Digite o novo pensamento: ");
		fflush(stdin);
		gets(auxP->pen.pensamento);
	}
	if (op!=1 && op!=2){
		printf("                                  Opção inválida.");
	}
}

void retirarF(TipoApontadorF p, TipoListaF *lista){
	p->ant->prox=p->prox;
	p->prox->ant=p->ant;
	free(p);
}

void retirarP(TipoApontadorP p, TipoListaP *lista){
	p->ant->prox=p->prox;
	p->prox->ant=p->ant;
	free(p);
}

void retirarR(TipoApontadorR p, TipoListaR *lista){
	p->ant->prox=p->prox;
	p->prox->ant=p->ant;
	free(p);
}

void excluirRelacionamento(TipoListaR *listaRel, int codPen, int codSoc, int x){
	TipoApontadorR auxR;
	auxR=listaRel->primeiro->prox;
	if (x==0){
		while (auxR!=NULL){
			if (codPen==auxR->rel.codPensamento){
				retirarR(auxR, listaRel);
				return;
			}
			auxR=auxR->prox;
		}
		printf("                                  Pensamento não encontrado.");
	}
	if (x==1){
		while (auxR!=NULL){
			if (codSoc==auxR->rel.codSociologo){
				retirarR(auxR, listaRel);
			}
			auxR=auxR->prox;
		}
	}
}

void excluirPensamento(TipoListaP *listaPen, TipoListaR listaRel){
	int codP, codS, x=0;
	TipoApontadorP auxP;
	printf("                                  Digite o código do sociólogo: ");
	scanf("%d", codS);
	printf("                                  Digite o código do pensamento: ");
	scanf("%d", &codP);
	auxP=buscaPensamento(*listaPen, codP);
	retirarP(auxP, listaPen);
	excluirRelacionamento(&listaRel, codP, codS, x);
}

void excluirSociologo(TipoListaF *listaSoc, TipoListaR listaRel){
	int codS, x=1, codP=0;
	TipoApontadorF auxF;
	printf("                                  Digite o código do sociólogo: ");
	scanf("%d", &codS);
	auxF=buscaSociologo(*listaSoc, codS);
	retirarF(auxF, listaSoc);
	excluirRelacionamento(&listaRel, codP, codS, x);
}

void creditos(){
	printf("                                                         Créditos:                    \n\n");
	printf("                                                    Julia Rezende Alves                 \n");
	printf("                                                  Tiago Henrique da Silva             \n\n");
	printf("                                          Alunos do IFSULDEMINAS - Câmpus Passos        \n");
	system("pause");
}

void titulo(){
	printf("                                  ######################################################\n");
	printf("                                  ##                                                  ##\n");
	printf("                                  ##                TRABALHO INTEGRADO:               ##\n");
	printf("                                  ##                                                  ##\n");
	printf("                                  ##      LISTA DE SOCIÓLOGOS E SEUS PENSAMENTOS      ##\n");
	printf("                                  ##                                                  ##\n");
	printf("                                  ##                                                  ##\n");
	printf("                                  ######################################################\n\n\n");
}

int menu(TipoListaF *listaSoc, TipoListaP *listaPen, TipoListaR *listaRel){
	int op, op2;
	TipoSociologo soc;
	TipoPensamento pen;
	TipoRelacionamento rel;
	system("cls");
	titulo();
	printf("                                                           MENU                                          \n\n");
	printf("                                  1 - Cadastrar sociólogo                                                  \n");
	printf("                                  2 - Cadastrar pensamento                                                 \n");
	printf("                                  3 - Exibir sociólogos                                                    \n");
	printf("                                  4 - Exibir sociólogos em ordem alfabética                                \n");
	printf("                                  5 - Exibir sociólogos e seus pensamentos                                 \n");
	printf("                                  6 - Exibir pensamentos de um sociólogo                                   \n");
	printf("                                  7 - Exibir sociólogo com mais pensamentos cadastrados                   \n");
	printf("                                  8 - Alterar                                                              \n");
	printf("                                  9 - Excluir                                                              \n");
	printf("                                  10 - Créditos                                                            \n");
	printf("                                  0 - Sair                                                               \n\n\n\n");
	printf("                                  Digite o número da operação que deseja realizar: ");
	scanf("%d", &op);
	switch(op){
		case 0:
			exit(0);
			break;
		case 1:
			system("cls");
			titulo();
			printf("                                  Digite o código do sociólogo: ");
			scanf("%d", &soc.cod);
			printf("                                  Digite o nome do sociólogo: ");
			fflush(stdin);
			gets(soc.nome);
			inserirF(listaSoc, soc);
			return NULL;
			break;
		case 2:
			system("cls");
			titulo();
			printf("                                  Digite o código do sociólogo: ");
			scanf("%d", &soc.cod);
			rel.codSociologo=soc.cod;
			printf("                                  Digite o código do pensamento: ");
			scanf("%d", &pen.cod);
			rel.codPensamento=pen.cod;
			printf("                                  Digite o pensamento:\n                                  \"");
			fflush(stdin);
			gets(pen.pensamento);
			inserirP(listaPen, pen);
			inserirR(listaRel, rel);
			return NULL;
			break;
		case 3:
			op2=3;
			system("cls");
			titulo();
			exibir(*listaSoc, *listaRel, *listaPen, op2);
			return NULL;
			break;
		case 4:
			op2=4;
			system("cls");
			titulo();
			exibir(*listaSoc, *listaRel, *listaPen, op2);
			return NULL;
			break;
		case 5:
			op2=5;
			system("cls");
			titulo();
			exibir(*listaSoc, *listaRel, *listaPen, op2);
			return NULL;
			break;
		case 6:
			op2=6;
			system("cls");
			titulo();
			exibir(*listaSoc, *listaRel, *listaPen, op2);
			return NULL;
			break;
		case 7:
			op2=7;
			system("cls");
			titulo();
			exibir(*listaSoc, *listaRel, *listaPen, op2);
			return NULL;
			break;
		case 8:
			system("cls");
			titulo();
			printf("                                  Digite 1 para alterar um sociologo ou 2 para alterar um pensamento: ");
			scanf("%d", &op2);
			alterar(listaSoc, listaPen, op2);
			return NULL;
			break;
		case 9:
			system("cls");
			titulo();
			printf("                                  Digite 1 para excluir um sociologo ou 2 para excluir um pensamento: ");
			scanf("%d", &op2);
			if (op2==1){
				excluirSociologo(listaSoc, *listaRel);
			}else{
				if (op2==2){
					excluirPensamento(listaPen, *listaRel);
				}else{
					printf("                                  Opção inválida.");
				}
			}
			return NULL;
			break;
		case 10:
			system("cls");
			titulo();
			creditos();
			return NULL;
			break;
	}
}

int main(){
	setlocale(LC_ALL, "");
	system("color 4E");
	
	TipoListaF listaSoc;
	TipoListaP listaPen;
	TipoListaR listaRel;
	TipoSociologo soc;
	TipoPensamento pen;
	TipoRelacionamento rel;
	
	LFVazia(&listaSoc);
	LPVazia(&listaPen);
	LRVazia(&listaRel);
	
	soc.cod=0;
	strcpy(soc.nome, "Karl Marx");
	strcpy(soc.biografia, "Karl Marx (1818–1883) foi um\n                                  filósofo e revolucionário socialista alemão. Criou\n                                  as bases da doutrina comunista, onde criticou o\n                                  capitalismo. Sua filosofia exerceu influência em\n                                  várias áreas do conhecimento, tais como Sociologia,\n                                  Política, Direito, Teologia, Filosofia, Economia,\n                                  entre outras. No dia 21 de fevereiro de 1848, com\n                                  base no trabalho de Engels, Os Princípios do\n                                  Comunismo, Marx escreve o Manifesto Comunista, onde\n                                  esboça suas principais ideias com a luta de classe\n                                  e o materialismo histórico. Critica o capitalismo,\n                                  expõe a história do movimento operário, e termina\n                                  com um apelo pela união dos operários no mundo todo.\n                                  Marx aborda ainda uma concepção muito particular\n                                  quanto ao trabalho, e que é importantíssima para\n                                  toda sua teoria. Ele compreende o trabalho enquanto\n                                  atividade fundante da humanidade, e sendo esta a\n                                  centralidade da atividade humana e sendo o homem um\n                                  ser social, essa atividade só pode ser desenvolvida\n                                  socialmente.");
	inserirF(&listaSoc, soc);
	pen.cod=1;
	strcpy(pen.pensamento, "O dinheiro é a essência alienada do trabalho e da \n                                  existência do homem; a essência domina-o e ele adora-a.");
	strcpy(pen.interp, "O dinheiro reflete a alienação do homem, pois faz com\n                                  que ele se importe cada vez menos com o processo do\n                                  qual ele participa de forma que vise apenas uma\n                                  recompensa que sequer representa seu real significado.");
	inserirP(&listaPen, pen);
	rel.codSociologo=soc.cod;
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	pen.cod=2;
	strcpy(pen.pensamento, "A história da sociedade até aos nossos dias é a \n                                  história da luta de classes.");
	strcpy(pen.interp, "Segundo Marx, a luta de classes está sempre presente \n                                  na sociedade, pois é dela que derivam os modelos que\n                                  existiram e existem de economia, cultura, política,\n                                  entre outras coisas.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	
	soc.cod=1;
	strcpy(soc.nome, "Max Weber");
	strcpy(soc.biografia, "Max Weber (1864-1920) foi um\n                                  importante sociólogo e destacado economista alemão.\n                                  Desenvolveu importantes trabalhos na Sociologia, foi\n                                  considerado um dos fundadores da Sociologia Moderna,\n                                  ao lado de Conte, Marx e Durkheim. Sua grande obra\n                                  chama-se Economia e Sociedade, onde traça um quadro\n                                  do poder e da política, ou seja, das relações de \n                                  dominação. Defendia a tese de que a forma de\n                                  legitimação de um poder é decisiva para se compreender\n                                  que tipo de poder é aquele. Em A Ética Protestante e\n                                  o Espírito do Capitalismo, o sociólogo realizou\n                                  importante estudo sobre como a religião, especialmente\n                                  o protestantismo nos EUA, foi um fator importante\n                                  para a consolidação do capitalismo.");
	inserirF(&listaSoc, soc);
	pen.cod=3;
	strcpy(pen.pensamento, "Poder é toda a chance, seja ela qual for, de impor a \n                                  própria vontade numa relação social, mesmo contra a \n                                  relutância dos outros.");
	strcpy(pen.interp, "Weber categoriza poder de três formas: carismática,\n                                  tradicional e racional legal. No entanto, a base para\n                                  essas definições é a de que o poder está na\n                                  oportunidade de mudar o pensamento ou o modo de agir\n                                  das pessoas, mesmo que elas não queiram.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	rel.codSociologo=soc.cod;
	inserirR(&listaRel, rel);
	pen.cod=4;
	strcpy(pen.pensamento, "Há duas maneiras de fazer política. Ou se vive 'para'\n                                  a política ou se vive 'da' política. Nessa oposição\n                                  não há nada de exclusivo. Muito ao contrário, em geral\n                                  se fazem uma e outra coisa ao mesmo tempo, tanto\n                                  idealmente quanto na prática.");
	strcpy(pen.interp, "Um profissional deve se dedicar à sua função. Weber diz\n                                  isso exemplificando a profissão de sociólogo e de\n                                  político, que devem ser vividas em sua plenitude para\n                                  que sejam bem exercidas.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	pen.cod=5;
	strcpy(pen.pensamento, "O homem é um animal amarrado a teias de significados \n                                  que ele mesmo teceu.");
	strcpy(pen.interp, "O ser humano acaba se prendendo muito a tradições que,\n                                  na maioria das vezes, nem se dá conta que foram criadas\n                                  por ele mesmo, fazendo com que muitas coisas percam o\n                                  sentido.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	
	soc.cod=2;
	strcpy(soc.nome, "Emile Durkheim");
	strcpy(soc.biografia, "Émile Durkheim (1858-1917) foi\n                                  um sociólogo francês. É considerado o pai da\n                                  Sociologia Moderna e chefe da chamada Escola\n                                  Sociológica Francesa. É o criador da teoria da\n                                  coesão social. Junto com Karl Marx e Max Weber,\n                                  formam um dos pilares dos estudos sociológicos.\n                                  Durkheim escreveu obras que foram definitivas nos\n                                  rumos dos estudos sociológicos. No livro Da Divisão\n                                  do Trabalho Social (1893), ele estabeleceu as bases\n                                  da sociedade comparando a um organismo vivo, onde\n                                  cada parte funcionava como um órgão biológico que\n                                  agiria de forma dependente. Assim, numa sociedade\n                                  doente, que ele denominava de anomia, a cura para o\n                                  melhor funcionamento social seria a solidariedade\n                                  orgânica");
	inserirF(&listaSoc, soc);
	pen.cod=6;
	strcpy(pen.pensamento, "É fato social toda maneira de agir, fixa ou não,\n                                  suscetível de exercer sobre o indivíduo uma coerção\n                                  exterior; ou então ainda, que é geral na extensão\n                                  de uma sociedade dada, apresentando existência\n                                  própria, independente das manifestações individuais\n                                  que possa ter.");
	strcpy(pen.interp, "Durkheim criou a ideia de fato social definindo-o\n                                  como externo, coercitivo e geral. Como, por exemplo,\n                                  a ideia de casamento que existe na maioria das\n                                  sociedades independentemente da vontade dos\n                                  indíviduos e há uma pressão para que seja exercido.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	rel.codSociologo=soc.cod;
	inserirR(&listaRel, rel);
	pen.cod=7;
	strcpy(pen.pensamento, "Quando os costumes são suficientes, as leis são\n                                  desnecessárias. Quando os costumes são insuficientes, \n                                  é impossível fazer respeitar as leis.");
	strcpy(pen.interp, "Muitas vezes algumas ideias tomadas como leis estão\n                                  embutidas nos costumes de uma sociedade, fazendo com\n                                  que uma formalização das leis seja desnecessária,\n                                  pois já existem como fatos sociais. Já na falta\n                                  desses costumes, existe uma maior insatisfação quando\n                                  leis externas são impostas. ");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	pen.cod=8;
	strcpy(pen.pensamento, "A religião não é somente um sistema de ideias, ela é \n                                  antes de tudo um sistema de forças.");
	strcpy(pen.interp, "As instituições religiosas, quando crescem, tendem a\n                                  se fortalecer formando elos com outras instituições,\n                                  fazendo com que se torne um sistema de forças que se\n                                  sustentam.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	
	soc.cod=3;
	strcpy(soc.nome, "Auguste Comte");
	strcpy(soc.biografia, "Auguste Comte (1798-1857) foi\n                                  um filósofo francês. Considerado o fundador do\n                                  positivismo, corrente que propõe uma nova organização\n                                  social. Foi o fundador da Sociologia. A partir de\n                                  1818, elaborou sua concepção da Ciência Social que\n                                  ele chamou de Sociologia. Sua doutrina considerou\n                                  a ciência positiva, baseada nos fatos, como o único\n                                  fator de estabilidade do universo. O pensamento\n                                  positivista pregava um modelo de sociedade organizada,\n                                  onde o poder espiritual não teria mais importância,\n                                  sendo os sábios e cientistas a primazia nas decisões.");
	inserirF(&listaSoc, soc);
	pen.cod=9;
	strcpy(pen.pensamento, "Amor como princípio, ordem como base e progresso\n                                  como objetivo.");
	strcpy(pen.interp, "Como sociólogo positivista, Comte fala que um Estado\n                                  deve visar a ordem e o progresso para ter um bom\n                                  desenvolvimento e consolidação.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	rel.codSociologo=soc.cod;
	inserirR(&listaRel, rel);
	
	soc.cod=4;
	strcpy(soc.nome, "A Servidão Moderna (Documentário)");
	strcpy(soc.biografia, "O Documentário \"A Servidão Moderna\",\n                                  foi feito como forma de expressar uma indignação diante\n                                  dos atos feitos pelas pessoas diante da ação da classe\n                                  dominante atual, criticando o modo como são as coisas.");
	inserirF(&listaSoc, soc);
	pen.cod=10;
	strcpy(pen.pensamento, "A servidão moderna é uma escravidão voluntária,\n                                  consentida pela multidão de escravos que se arrastam\n                                  pela face da terra.");
	strcpy(pen.interp, "As pessoas, alienadas pela exploração do trabalho e cegas\n                                  pelo desejo do dinheiro, aceitam a submissão de grandes\n                                  empresas e organizações que visam lucrar com essa\n                                  escravidão, como fazendeiros que conduzem o gado para o\n                                  abate.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	rel.codSociologo=soc.cod;
	inserirR(&listaRel, rel);
	pen.cod=11;
	strcpy(pen.pensamento, "À medida que o homem constrói seu mundo com a força do\n                                  trabalho alienado, o cenário deste mundo se converte na\n                                  prisão onde terão que viver. ");
	strcpy(pen.interp, "Involuntariamente, através do trabalho alienante, o ser\n                                  humano transforma o mundo em uma espécie de prisão para\n                                  si mesmo, no entanto, ele não se dá conta disso.");
	inserirP(&listaPen, pen);
	rel.codPensamento=pen.cod;
	inserirR(&listaRel, rel);
	
	
	while (menu(&listaSoc, &listaPen, &listaRel)==NULL){
		menu(&listaSoc, &listaPen, &listaRel);
	}
}
