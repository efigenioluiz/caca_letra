#include <stdio_ext.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define T_PRETO 	printf("\33[30m");
#define T_VERMELHO 	printf("\33[31m");
#define T_VERDE 	printf("\33[32m");
#define T_LARANJA 	printf("\33[33m");
#define T_AZUL 		printf("\33[34m");
#define T_BRANCO 	printf("\33[37m");

#define LIN 		4
#define PEQ 		4
#define MED 		4
#define GRA 		4

typedef struct {
	char nome[50];
	char login[50];
	char senha[50];
	int tipo;
} usuario;

typedef struct {
	char nome[50];
	int pontos;
} ranking;

typedef struct {

} save;


void menuAdmin();
void menuJogador();
int efetuarLogin(char* login, char* senha);
int cadastrarUsuario(int tipo, char* nome, char* login, char* senha);
void alterarUsuarios();
void removerUsuarios();
void verUsuarios();
void Game();

int main (){

	usuario x;
	int inicio=0, retlogin, tipo, ret, flag, retcad, lacoadm=0, lacousuario=0;
	int menuadm, menujogador;
	FILE *fp;
	char *login=malloc(50 * sizeof(char)), *senha=malloc(50 * sizeof(char));


	
	while(inicio == 0){
		system("clear");
		inicio = 0;
	
    fp = fopen("usuario.bin", "r");
    
  	if(fp == NULL) {
  		printf("\n\tAdministrador nao encontrado, registre-se como administrador\n");
  		
  		fp = fopen("usuario.bin", "a+");
		printf("\t______ _____ _____ _____ _____ ___________  ___  ______\n"); 
		printf("\t| ___ \\  ___|  __ \\_   _/  ___|_   _| ___ \\/ _ \\ | ___ \\\n");
		printf("\t| |_/ / |__ | |  \\/ | | \\ `--.  | | | |_/ / /_\\ \\| |_/ /\n");
		printf("\t|    /|  __|| | __  | |  `--. \\ | | |    /|  _  ||    / \n");
		printf("\t| |\\ \\| |___| |_\\ \\_| |_/\\__/ / | | | |\\ \\| | | || |\\ \\ \n");
		printf("\t\\_| \\_\\____/ \\____/\\___/\\____/  \\_/ \\_| \\_\\_| |_/\\_| \\_|\n");
		printf("	\t\tDigite NOME: ");
		__fpurge(stdin);
		gets(x.nome);
		printf("\t\t\tLOGIN: ");
		__fpurge(stdin);
		gets(x.login);
		printf("\t\t\tSENHA: ");
		__fpurge(stdin);
		T_PRETO
		gets(x.senha);
		T_BRANCO
		fwrite(&x, sizeof(usuario), 1, fp);
		fclose(fp);
    }
    
    else{
	
			lacoadm = 0;
			lacousuario = 0;
			printf(" 	    _     _____ _____ _____ _   _  \n");
			printf(" 	   | |   |  _  |  __ \\_   _| \\ | |\n"); 
			printf(" 	   | |   | | | | |  \\/ | | |  \\| |\n"); 
			printf(" 	   | |   | | | | | __  | | | . ` |\n"); 
			printf(" 	   | |___\\ \\_/ / |_\\ \\_| |_| |\\  |\n"); 
			printf("   	   \\_____/\\___/ \\____/\\___/\\_| \\_/\n");
 
    		printf("\t\tLOGIN: ");
			__fpurge(stdin);
			gets(login);
			printf("\t\tSENHA: ");
			__fpurge(stdin);
			T_PRETO
			gets(senha);
			T_BRANCO
			fclose(fp);
			retlogin = efetuarLogin(login, senha);
			
			if(retlogin == 1){
				fp=fopen("usuario.bin","a+");
				while(lacousuario==0){

					ret=1;
					while(ret==1){
						ret=fread(&x,sizeof(usuario),1,fp);
						if(ret==1){
							if(strcmp(login,x.login)==0){
								system("clear");
								printf("\t\tSeja Bem-Vindo %s\n\n",x.nome);
								ret=0;
							}
						}
					}
				menuJogador();
				scanf("%i", &menujogador);

				if(menujogador == 1){
					Game();
									
				}
				else if(menujogador == 2 ){
					
				}
				else if(menujogador == 3 ){
					alterarUsuarios();
				}
				else if(menujogador == 4 ){
					
				}
				else if(menujogador == 5 ){
					
				}
				else if(menujogador == 6 ){
					lacousuario=1;
					
				}
				else if(menujogador == 7 ){
					return 0;
				}
				
				}
			}
			
			else if(retlogin == 2){
				fp=fopen("usuario.bin","a+");
				while(lacoadm == 0){
				
				ret=1;
				while(ret==1){
					ret=fread(&x,sizeof(usuario),1,fp);
					if(ret==1){
						if(strcmp(login,x.login)==0){
							system("clear");
							printf("\t\tSeja Bem-Vindo %s\n",x.nome);
							ret=0;
						}
					}
				}				

				menuAdmin();
				scanf("%i", &menuadm);
											
				if(menuadm == 1){
					fp=fopen("usuario.bin","a+");
					__fpurge(stdin);
					printf("\n\tDigite nome: ");
					__fpurge(stdin);
					gets(x.nome);
					printf("\n\tDigite login: ");
					__fpurge(stdin);
					gets(x.login);
					printf("\n\tDigite senha: ");
					__fpurge(stdin);
					gets(x.senha);
					retcad = cadastrarUsuario(tipo,x.nome,x.login,x.senha);
					
					if(retcad == 1) {
							
							fwrite(&x, sizeof(usuario), 1, fp);
							fclose(fp);
							printf("\tUsuario cadastrado com sucesso");
							getchar();
							system("clear");
						}
					
					 	else {			
						  
			                printf("\tUsuario ja existente, tente novamente");
			                fclose(fp);
			                getchar();
			                system("clear");
			        	}
						
				}
				else if(menuadm == 2){
					system("clear");
					verUsuarios();
					
					
				}
				else if(menuadm == 3){
					removerUsuarios();
					
					
				}
				else if(menuadm == 4){
					lacoadm=1;
	
				}
				else if(menuadm == 5){
					return 0;
				}
				

				}
			}
		
			else{
				system("clear");
				printf("\n\n\t\tLogin ou senha errado !! Tente novamente.\n\n");
				getchar();
			}
		}
	
	}	
}

int cadastrarUsuario(int tipo, char* nome, char* login, char* senha) {
	
	int ret=1,h=0;
 	FILE *fp;
 	usuario x;
 	
 	fp = fopen("usuario.bin", "a+");
 	ret=1;
	
	while(ret == 1) {
		
		ret = fread(&x, sizeof(usuario), 1, fp);
		
		if(ret == 1 && h == 0) {
			
			if (strcmp(login,x.login) == 0 ) {
				fclose(fp);			
		 		return 0;
		 	}
		 	
		 	else {	
				fclose(fp);
		 		return 1;

		 	}
		}
	}
 	
}

int efetuarLogin(char* login, char* senha) {
 	int ret=1, g=0, h=0;
 	FILE *fp;
 	usuario x;
 	
 	fp = fopen("usuario.bin", "a+");
 	g=0;
 	h=0;
	
	while(ret == 1) {
		
		ret = fread(&x, sizeof(usuario), 1, fp);
		
		if(ret == 1 && h == 0) {
			
			if(strcmp(login,x.login) == 0) {
				
		 		g++;
		 	}
		 	
		 	if(strcmp(senha,x.senha) == 0) {
		 		
		 		g++;
		 	}
		 	
		 	if(g == 2) {
		 		
		 		printf("\n\tLogado com Sucesso\n");
		 		getchar();
		 		return 2;
		 	}
			 	
		 	if(g == 0 || g == 1) {
		 		
		 		h=1;
		 	}
		}
		
		while(ret == 1) {
			
			ret = fread(&x, sizeof(usuario), 1, fp);
			
			if(ret == 1 && h == 1) {
	
			 	g=0;
	
			 	if (strcmp(login,x.login) == 0) {
			 		g++;
	
			 	}
			 	
			 	if (strcmp(senha,x.senha) == 0) {
			 		g++;
	
			 	}
			 	
			 	if (g == 2) {
	
			 		printf("\n\tLogado com Sucesso\n\n");
			 		getchar();
			 		fclose(fp);
			 		system("clear");
			 		return 1;
			 	}	
			}
		}
	}
	
}
void alterarUsuarios() {

	int ret=1, flag;
	FILE *fp, *fpa;
	usuario x;
	char busca[50];
	
	fp = fopen("usuario.bin", "a+");
	fpa = fopen("grr.bin", "a+");

	if(fp != NULL && fpa != NULL) {

		printf("\tDigite o nome do Usuario: ");
		__fpurge(stdin);
		gets(busca);
		flag=0;
		ret=1;
		
		while(ret == 1) {

			ret = fread(&x, sizeof(usuario), 1, fp);
			
			if(ret == 1) {
				
				if(strcmp(busca, x.nome) == 0){
	
					printf("Digite o novo usuario: ");
					gets(x.login);
					__fpurge(stdin);
					printf("Digite a nova senha: ");
					gets(x.senha);
					
					fwrite(&x, sizeof(usuario), 1, fpa);
					flag = 1;
				}
					
				else {
		
					fwrite(&x, sizeof(usuario), 1, fpa);
				}		
			}
		}

		fclose(fp);
		fclose(fpa);
		remove("usuario.bin");
		rename("grr.bin", "usuario.bin");

		if(flag == 1) {
			
			printf("\n\tUsuario alterado com sucesso");
		}
		
		else {
			
			printf("\n\tUsuario não encontrado");
		}
	
		__fpurge(stdin); 
		getchar();
		system("clear");
	}			
	
}

void removerUsuarios() {
	
	int ret=1, flag;
	FILE *fp, *fpa;
	usuario x;
	char busca[50];
	
	fp = fopen("usuario.bin", "a+");
	fpa = fopen("grr.bin", "a+");

	if(fp != NULL && fpa != NULL) {

		printf("\n\tDigite o nome do Usuario: ");
		__fpurge(stdin);
		gets(busca);
		flag=0;
		ret=1;
		
		while(ret == 1) {

			ret = fread(&x, sizeof(usuario), 1, fp);
			
			if(ret == 1) {
				
				if(strcmp(busca, x.nome) == 0) {
					
					flag = 1;
				}	
				
				else {
					
					fwrite(&x, sizeof(usuario), 1, fpa);
				}		
			}
		}

		fclose(fp);
		fclose(fpa);
		remove("usuario.bin");
		rename("grr.bin", "usuario.bin");
	
		if(flag == 1) {
		
			printf("\n\tUsuario removido com sucesso");
		}
	
		else {
		
			printf("\n\tUsuario não encontrado");
		}
	
		__fpurge(stdin); 
		getchar();
		system("clear");
	}			
}

void verUsuarios () {
	
	int ret=1;
	FILE *fp;
	usuario x;
 	
 	fp = fopen("usuario.bin", "a+");
				
	if(fp != NULL) {
		
		ret = 1;
		
		while(ret == 1) {
						
			ret = fread(&x, sizeof(usuario), 1, fp);
						
			if(ret == 1) {
				
				printf("Nome: %s\nLogin: %s\nSenha: %s\n\n", x.nome, x.login, x.senha);
			}
		}

		fclose(fp);
		__fpurge(stdin);
		getchar();
	} 
	
	system("clear");
}
void menuAdmin() {
			
printf("	$$\\      $$\\$$$$$$$\\$$$\\   $$\\$$\\   $$\\\n");
printf("	$$$\\    $$$ $$  _____$$$\\  $$ $$ |  $$ |\n");
printf("	$$$$\\  $$$$ $$ |     $$$$\\ $$ $$ |  $$ |\n");
printf("	$$\\$$\\$$ $$ $$$$$\\   $$ $$\\$$ $$ |  $$ |\n");
printf("	$$ \\$$$  $$ $$  __|  $$ \\$$$$ $$ |  $$ |\n");
printf("	$$ |\\$  /$$ $$ |     $$ |\\$$$ $$ |  $$ |\n");
printf("	$$ | \\_/ $$ $$$$$$$$\\$$ | \\$$ \\$$$$$$  |\n");
printf("	\\__|    \\__\\________\\__|  \\__|\\______/ \n");			
			printf("\n\t============================");
			printf("\n\t=                          =");
			printf("\n\t= 1 - Cadastrar Jogador    =");
			printf("\n\t= 2 - Visualizar Jogadores =");
			printf("\n\t= 3 - Remover Jogador      =");
			printf("\n\t= 4 - Efetuar 'Logoff'     =");
			printf("\n\t= 5 - Sair                 =");
			printf("\n\t============================\n");
			printf("\n\tEscolha uma opcao: ");
}

void menuJogador() {

printf("	$$\\      $$\\$$$$$$$\\$$$\\   $$\\$$\\   $$\\\n");
printf("	$$$\\    $$$ $$  _____$$$\\  $$ $$ |  $$ |\n");
printf("	$$$$\\  $$$$ $$ |     $$$$\\ $$ $$ |  $$ |\n");
printf("	$$\\$$\\$$ $$ $$$$$\\   $$ $$\\$$ $$ |  $$ |\n");
printf("	$$ \\$$$  $$ $$  __|  $$ \\$$$$ $$ |  $$ |\n");
printf("	$$ |\\$  /$$ $$ |     $$ |\\$$$ $$ |  $$ |\n");
printf("	$$ | \\_/ $$ $$$$$$$$\\$$ | \\$$ \\$$$$$$  |\n");
printf("	\\__|    \\__\\________\\__|  \\__|\\______/ \n");
                                       
	
			printf("\n\t=================================");
			printf("\n\t=                               =");
			printf("\n\t= 1 - JOGAR!	                =");
			printf("\n\t= 2 - *****************         =");
			printf("\n\t= 3 - Modificar Dados           =");
			printf("\n\t= 4 - ************              =");
			printf("\n\t= 5 - Ranking                   =");
			printf("\n\t= 6 - Efetuar 'Logoff'          =");
			printf("\n\t= 7 - Sair                      =");
			printf("\n\t===============================\n");
			printf("\n\tEscolha uma opcao: ");
}
int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}
void Game(){

	int tam=0,botao=0,botao2=0,control=0,g=0,j=0,p=0,y=0;
	int a,b,i=0,l, c,c_aux,l_aux, final=0,config_tam=4;
	char jogada, resp='S', tab[GRA][GRA],tab2[GRA][GRA],peca[16],veri[8];
	int px, py,destacar=0,pxx=0,pyy=0,pxxx=0,pyyy=0;
	int click=0, pontos=0;

	do {
			system("clear");
			srand(time(NULL));

		peca[0]='A';
		peca[1]='B';
		peca[2]='C';
		peca[3]='D';
		peca[4]='E';
		peca[5]='F';
		peca[6]='G';
		peca[7]='H';
		peca[8]='A';
		peca[9]='B';
		peca[10]='C';
		peca[11]='D';
		peca[12]='E';
		peca[13]='F';
		peca[14]='G';
		peca[15]='H';		
		
		veri[0]='A';
		veri[1]='B';
		veri[2]='C';
		veri[3]='D';
		veri[4]='E';
		veri[5]='F';
		veri[6]='G';
		veri[7]='H';

		// Geração da matriz 
		for(l=0; l<LIN; l++) {
			for(c=0; c<config_tam; c++) {
				tab2[l][c]=' ';	
			
				tab[l][c]='#'; 
			}
		}

		p=0;
		y=0;
		for(a=0;a <16;a++){
			p=rand()%5;
			y=rand()%5;
			if(tab2[p][y]== ' '){
				tab2[p][y]=peca[a];
			}
			else{
				do{
					p=rand()%5;
					y=rand()%5;	
				}while(tab2[p][y] !=' ');
					
				if(tab2[p][y]== ' '){
						tab2[p][y]=peca[a];
				}				
			}
		}
		// Inicio do jogo
		pxx=0;
		pyy=0;
		final = 0;
		px = py = 0;	

		while(final==0) { 
			if(botao2==0){
				printf("\n\t\t");
				for(a=0; a<4;a++){
					for(b=0;b <4;b++){
						printf(" %c",tab2[a][b]);
					}
				printf("\n\t\t");
				}
				printf("\n\t5 Segundos para Memorizar!!");
				for(a=0+1;a <=5;a++){				
					sleep(1);					
					printf("\n\t\t%i",a );
				}
				system("clear");
				system("\n\n");
				botao2=1;
			}
			system("clear");
			// Apresenta matriz

			printf("\n\t\t");
			for(a=0; a<config_tam*2; a++) { T_BRANCO printf("-"); }
			
			printf("\n\t\t");
			for(l=0; l<LIN; l++) {
				for(c=0; c<config_tam; c++) {

					if(px == l && py == c) {
						T_VERDE
						printf("%c ",tab[l][c]);
						fflush(stdout);
						T_BRANCO
					}
				 	else if( botao ==1 && (pxx==l)&&( pyy==c)){	
							T_AZUL;				
							printf("%c ", tab2[l][c]);
							fflush(stdout); 
							T_BRANCO
					}
				 	else if( click ==1 && (pxxx==l)&&( pyyy==c)){	
							T_VERMELHO;				
							printf("%c ", tab2[l][c]);
							fflush(stdout);	
							T_BRANCO
					}							
					else{	
						if(tab[l][c] != '#'){
							T_LARANJA;			
							printf("%c ", tab[l][c]);
							fflush(stdout);
						}else{
							T_BRANCO;			
							printf("%c ", tab[l][c]);
							fflush(stdout);							
						}
					}
				}
				printf("\n\t\t");
			}
			// verifica os pontos
			if( (pxx != pxxx) || (pyy != pyyy) ){	
				if( (tab2[pxx][pyy]==tab2[pxxx][pyyy]) && (click ==1) && (botao ==1) ){
					for(i=0;i<8;i++){
						if(veri[i]== tab2[pxx][pyy]){
							veri[i]=' ';
							pontos++;
						}
					}
					//A tab mascara recebe a peca encontrada
					tab[pxx][pyy]=tab2[pxx][pyy];
					tab[pxxx][pyyy]=tab2[pxxx][pyyy];
					botao=0;
					click=0; 
				}
			}

			printf("\n");
			T_BRANCO
			printf("\tPONTOS: %i\n",pontos);

			// CAPTURA TECLA
			jogada = getch();

			// TECLA ESPECIAL
			if(jogada == 27) {
				jogada = getch(); 

				if(jogada == 91) {      
					jogada = getch();
		
					// CIMA
					if(jogada == 65) {
						if(px > 0) {
							px--;
						}
					}		
		  			// BAIXO
					else if(jogada == 66) {
			    			if(px < LIN-1) {
							px++;
						}
					}
					// DIREITA
					else if(jogada == 67) {
						if(py < config_tam-1) {
							py++;
						}
				    }
					// ESQUERDA
					else if(jogada == 68) {
						if(py > 0) {
							py--;
						}
					}
				
				}
			}
			// MARCA A PALAVRA 
			else if(jogada == 'f' || jogada == 'F' ) {		
					botao=1;	
					pxx=px;
					pyy=py; 
				}else if(jogada == 'd' || jogada == 'D'){
					click=1;	
					pxxx=px;
					pyyy=py;		
				}
				else if(jogada == 'R' || jogada == 'r'){
					Game();	
				}
				else if(jogada == 'h' || jogada == 'H'){
						printf("\n\t\t");	
					for(a=0; a<4;a++){
						for(b=0;b <4;b++){
							printf(" %c",tab2[a][b]);
						}
						printf("\n\t\t");
					}
					getchar();					
				}							
			// SAIR
			else if(jogada == 'S' || jogada == 's') {
				//resp='s';
			}
		
			if(pontos==8){
				system("clear");
				printf("\n\n\t\tPARABÉNS VOCÊ GANHOU O JOGO !!");
				getchar();
				system("clear");
				final=1;
				resp='n';

			}						
		} 
	} while(resp == 's' || resp == 'S');

	printf("\n");
}