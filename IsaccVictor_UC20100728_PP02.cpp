//Nome completo: Isacc Victor de Siqueira Santos
//Matrícula: UC20100728
//Curso: Engenharia de Software

#include <stdio.h> //BIBLIOTECA PARA SCANF, PRINTF...
#include <locale.h> //BIBLIOTECA PARA PRINTAR CARACTERES ESPECIAIS
#include <stdlib.h> //BIBLIOTECA PARA O SYSTEM("CLS")
#include <string.h> //BIBLIOTECA PARA STRING
#include<windows.h> //BIBLIOTECA PARA AS CORES

 enum DOS_COLORS{ //DECLARAÇÃO DAS CORES
 preto, azul, verde, CYAN, vermelho, MAGENTA, castanho,
 cizento_claro, cizento_escuro, azul_claro, verde_claro, CYAN_claro,
 vermelho_claro, MAGENTA_claro, amarelo, branco
 };


 void textcolor(int iColor){
 HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
 bufferInfo.wAttributes &= 0x00F0;
 SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
 }
int main(void){ //INICIO DO ALGORITMO
	 setlocale(LC_ALL, "Portuguese");
	 char destino[20], confirmarReserva[2]; //DECLARAÇÃO DAS VARIÁVEIS
	 int assentos, menu, reserva, passagemCliente[500], idadeCliente[500], passagem, teste, contador, i, id, j, k, local[10][20];
	 int reservaTotal, confirmadoTotal, disponivelTotal, montanteTotal;
	 char letra[10][20];
	 
	 k=0;
	 j=0;
	 contador=0;
     i=0;
	 assentos=0;
	 menu=0;
	 idadeCliente[500]=0;
	 passagem=0;
	 passagemCliente[500]=0;
	 reservaTotal=0;
	 confirmadoTotal=0;
	 disponivelTotal=0;
	 montanteTotal=0;
	 
	 printf("\n===========Bem Vindo ao controle de passagens da SALUMAR LINHAS AEREAS===========\n");
	 printf("\nPara prosseguir digite o nome do destino do voo: ");
	 fgets(destino, 20, stdin);
	 fflush(stdin);
	 while (strcmp(destino, "\n") == 0 || strcmp(destino, "vazio\n") == 0 || destino[0]==' ' ){ //WHILE PARA O NOME DO DESTINO NÃO SER NULO
	  	printf("Digite um destino válido: ");
	  	fgets(destino, 40, stdin);
	  	fflush(stdin);
	 }
	 
	 printf("\nDigite a quantidade de assentos existentes para o avião: ");
	 scanf("%d", &assentos);
	 fflush(stdin);
	 while (assentos<90 || assentos>200){ //WHILE PARA O NÚMERO DE ASSENTOS SER MAIOR IGUAL A 90 E MENOR IGUAL A 200
	 	printf("\nDigite uma quantidade entre 90 e 200 assentos: ");
	 	scanf("%d", &assentos);
	 	fflush(stdin);
	 }
	    printf("\nDigite o valor cheio da passagem: ");
	    scanf("%d", &passagem);
	    fflush(stdin);
	    system("cls");
	    
	    while (passagem>=1){ //WHILE PARA O MENU PRINCIPAL
	    	
	 system("cls"); //FUNÇÃO PARA LIMPAR A TELA	
	 printf("\n=========== MENU DE RESERVAS ===========\n");
	 printf("\n[1]=== Consultar o mapa do avião\n");
	 printf("\n[2]=== Efetuar uma reserva\n");
	 printf("\n[3]=== Confirmar uma reserva\n");
	 printf("\n[4]=== Cancelar uma reserva\n");
	 printf("\n[5]=== Relatório de reservas\n");
	 printf("\n=========== MENU DE RESERVAS ===========\n");
	 printf("\nDigite a opção que deseja realizar: ");
	 scanf("%d", &menu);
	 fflush(stdin);
	 
	 switch(menu){ //SWITCH CASE PARA AS OPÇÕES DO MENU

case 1: //CASE PARA CONSULTAR O MAPA

  system("cls");
            for ( k = 0; k < 10; k++)
            {
            for ( j = 0; j < 20; j++)
            {
            contador++;
            local[k][j]=contador;
            }
            }
            for ( k = 0; k < 10; k++)
            {
            for ( j = 0; j < 20; j++)
            {
            if (local[k][j] <= assentos)
            {
            letra[k][j] = 'D';
            }
            }
            }
  
        printf("\n=========== MAPA DE RESERVAS ===========\n");
        textcolor(amarelo);
        printf("Lugares disponiveis\n");
        for(j=0;j<20;j++){
        for(k=0;k<10;k++){
            if(local[k][j]<=contador && (letra[k][j]=='D' || letra[k][j]=='R' || letra[k][j]=='C')){
                if (letra[k][j]=='R')
                {
                    textcolor(vermelho);
                    printf("%.3d ", local[k][j]);
                    printf("%c ", letra[k][j]);
                    textcolor(verde_claro);
                } else if (letra[k][j]=='D'){
                    textcolor(verde_claro);
                    printf("%.3d ", local[k][j]);
                    printf("%c ", letra[k][j]);
                    textcolor(branco);
                } else if (letra[k][j]=='C')
                {
                    textcolor(azul);
                    printf("%.3d ", local[k][j]);
                    printf("%c ", letra[k][j]);
                    textcolor(amarelo);
                }

                } 
            } 
        printf("\n");
        }
        k=0;
        j=0;
        printf("\n");
        textcolor(vermelho);
        printf("reservado  ");
        textcolor(azul);
        printf("confirmado  ");
        textcolor(verde);
        printf("disponivel  \n");
        textcolor(amarelo);

        system("pause"); //FUNÇÃO ENTER PARA CONTINUAR
        
  
    break;
    
case 2: //CASE PARA EFETUAR UMA RESERVA
	if (i<assentos){
	    i++;
  	    system("cls");
  	  	printf("\n=========== RESERVAR ASSENTOS ===========\n");
  		printf("\nQual a idade do cliente?: ");
		scanf("%d", &idadeCliente[500]);
		fflush(stdin);   
		printf("\nSeu id de reserva é: %d\n\n", i);	    
		printf("=========== RESERVAR ASSENTOS ===========\n\n");
		reservaTotal++;
		system("\npause");
	}
	else {
		printf("\n===========================================================\n");
		printf("===========TODOS OS ASSENTOS JÁ FORAM RESERVADOS===========\n");
		printf("===========================================================\n\n");
		system("\npause");
	}
		break;        
		            
case 3: //CASE PARA CONFIRMAR UMA RESERVA
        system("cls");
        printf("\n=========== CONFIRMAR RESERVA ===========\n\n");
        printf("Você quer confirmar a reserva de qual id?: ");
        scanf("%d", &id);
		fflush(stdin); 
		  
		while (id>i){
			printf("Digite um id válido: ");
			scanf("%d", &id);
		    fflush(stdin); 
	     	}
		     
			 if (idadeCliente[id]<5){
		         passagemCliente[id] = passagem * 0.5;
			 }
		     else {
		     	 passagemCliente[id] = passagem;
			 }
			  
		     printf("\nO valor total da passagem será de R$%d", passagemCliente[id]);
  			 printf("\nDeseja CONFIRMAR a reserva? (USE [S] PARA CONFIRMAR): ");
  			 fgets(confirmarReserva, 2, stdin);
  			 fflush(stdin);
  			 system("cls");
  				if (strcmp(confirmarReserva, "s") == 0 || strcmp(confirmarReserva, "S") == 0 ){	
					printf("\n=========== RESERVA CONFIRMADA ===========\n");
					printf("\nValor total da passagem: %d\n", passagemCliente[id]);
					printf("\n=========== RESERVA CONFIRMADA ===========\n"); 
					reservaTotal = reservaTotal - 1;
					confirmadoTotal++;
					disponivelTotal = assentos - (reservaTotal + confirmadoTotal);
					montanteTotal = montanteTotal + passagemCliente[id]; 		
					system("pause");
				    }
  					else {
					printf("\n=========== RESERVA NÃO CONFIRMADA ===========\n");
  					printf("\n============= REFAÇA A RESERVA =============\n");
					system("pause");
		            }
					break;
case 4: //CASE PARA CANCELAR UMA RESERVA
	         system("cls");
	         printf("\n=========== CANCELAMENTO DE RESERVA ===========\n\n");
             printf("\nDigite o id da sua reserva para o CANCELAMENTO: ");
             scanf("%d", id);
             fflush(stdin);
             printf("Você tem certeza que deseja a reserva: \n");
             printf("id: %d", id);
             printf("idade: %d", idadeCliente[id]);
             printf("Valor: %d", passagemCliente[id]);
             system("cls");			 
			 printf("\nSua reserva já foi confirmada?(Use S para SIM, ou qualquer letra para NÃO): ");
  			 fgets(confirmarReserva, 2, stdin);
  			 fflush(stdin);
  			 system("cls");
  				if (strcmp(confirmarReserva, "s") == 0 || strcmp(confirmarReserva, "S") == 0 ){	//IF PARA RESERVAS JÁ CONFIRMADAS
					printf("\n=========== RESERVA CANCELADA ===========\n");
                    printf("=========== RESERVA CANCELADA ==========="); 
					printf("\n=========== RESERVA CANCELADA ===========\n"); 
					confirmadoTotal = confirmadoTotal - 1;
					disponivelTotal = assentos + 1;
					montanteTotal = montanteTotal - passagemCliente[id]; 		
					system("pause");
				    }
  					else {
				    printf("\n=========== RESERVA CANCELADA ===========\n");
                    printf("=========== RESERVA CANCELADA ==========="); 
					printf("\n=========== RESERVA CANCELADA ===========\n"); 
					reservaTotal = reservaTotal - 1;
					disponivelTotal = assentos + 1;
					montanteTotal = montanteTotal - passagemCliente[id]; 		
					system("pause");
					system("pause");
		            }
			 
					break;
					
case 5: //CASE PARA VER O RELATÓRIO DE RESERVAS    
             system("cls");
             printf("\n=========== RELATÓRIO ===========\n\n");
             printf("Total de RESERVAS: %d\n", reservaTotal);
             printf("Total de reservas CONFIRMADAS: %d\n", confirmadoTotal);
             printf("Total de assentos DISPONÍVEIS: %d\n", disponivelTotal);
             printf("Total arrecadado: %d\n", montanteTotal);
             printf("\n=========== RELATÓRIO ===========\n");
			 system("pause");
					
					break;
					
					
					
	}}		 		        
	 return 0;
}
