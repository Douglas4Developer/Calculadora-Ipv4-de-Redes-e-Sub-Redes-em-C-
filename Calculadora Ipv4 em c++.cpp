/*====================================
*     Calculadora de rede e sub-rede
* ====================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <stdint.h>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <conio.h>

using namespace std;

void printarInfosubrede(unsigned int* octetosEndereco, int* CIDR);
int verificaIP(char* ip,  unsigned char* octetoArr);
void cabecalho();
void calculoIPSemclassCIDR();
void calculoIPSemclassDecimal();
void calculoIPNormal();
void menu();


int main() {
	system("color B4");
    cabecalho();
	menu();
	return 0;
}



void menu ( ){
          int op = -1;
          
    while(op!=5){		
   		  cout<<"\n";
   		  cout<<" ______________________________"<<endl;
		  cout<< "       --------------------         Menu Principal      --------------------            "<<endl;
		  cout<< "Digite a opcao desejada para calcular o IPV4:"<<endl;
          cout<< "1. Para calcular um IPv4:  "<<endl;
          cout<< "2. Para calcular um Ipv4 sem classe e mascara decimal: "<<endl;          
          cout<< "3. Para calcular IPv4 Sem classe e mascara CIDR: "<<endl;          
          cout<< "4. Limpar a Tela: "<<endl;      
          cout<< "5. Sair da calculadora de ip: "<<endl;      
          cout<<" ______________________________"<<endl;
          cin>> op;

          switch ( op )

                  {
                      case 1: 
                      calculoIPNormal();
                      
                      break;
                      
                      case 2:
                      calculoIPSemclassDecimal();
                      break;
                      
                      case 3:
                      calculoIPSemclassCIDR();
                      break;
                
                      case 4:
                      system("clear||cls");
                      break;
                        
                      case 5:
                      system("clear||cls");
          			  cout<<"Obrigado por ultilizar a calculadora de IPv4... fechando programa...\n"<<endl;
		              sleep(3000); // Aqui ele dorme por 3 segundos depois continua o código
		              exit(0);
                                            
                      default:
                      cout<<"Operacao invalida, tente novamente ou digite '5' e tecle enter para sair: \t"<<endl;
                      break;          
                 }
           }
       }
	
	
	


void calculoIPSemclassDecimal(){
   
	char ip[18];
	string masc;
	string operar;
	char buffer[4];	
	char bufferMasc[18];
    unsigned char* octetoArr;
    octetoArr= (unsigned char*) malloc(4 * sizeof(char));
	int CIDR,  i, tempo=clock();
	unsigned int octetosEndereco;	 
	

   
	while (1) {  //Pega o endereço
		cout<<"Agora, digite o endereco IPv4: \n"<<endl;
			if (fgets(ip, sizeof ip, stdin) == NULL){ //tratamento do fgets
		    break;
			}
			//leitura do Ipv4
		fgets(ip, 17, stdin);
		ip[strlen(ip)-1] = '\0';
		

		cout<<"Verificando se ip esta correto: ... "
		<<"Seu Ipv4 eh "<<ip<<endl;
		
	//Verifica // FAZ VALIDAÇÃO
		if (verificaIP(ip,  octetoArr) == 0) {
				cout<<"\nO IP que digitou eh invalido. Tente novamente!"<<endl;
				return;          
		} else {
			cout<<"\nEndereco verificado! Endereco valido\n"<<endl;
			break;
		}
	}
	while(1){
		//PEGA A MASCARA EM DECIMAL	
	    cout<<"Digite a mascara no formato decimal:\n ex.:(255.0.0.0):"<<endl;
	
		cin>> masc;
	
		cout<<"Verificando se a mascara esta correto: ... "<<masc<<endl;
		
		if (masc !="255.255.0.0" && masc !="255.128.0." && masc !="255.192.0.0"
		&& masc !="255.224.0.0" && masc !="255.240.0.0" && masc !="255.248.0.0" && masc !="255.252.0.0" && masc !="255.254.0.0" &&	masc !="255.255.0.0" && masc !="255.255.128.0"
		&&  masc !="255.255.192.0" && masc !="255.255.224.0" && masc !="255.255.240.0" && masc !="255.255.248.0"&& masc !="255.255.252.0" 
		&&masc !="255.255.254.0" && masc !="255.255.255.0" && masc !="255.255.255.128" && masc !="255.255.255.192" && masc !="255.255.255.224"
		&& masc !="255.255.255.240"&& masc !="255.255.248" && masc !="255.255.255.252" && masc !="255.255.255.254" && masc!="255.255.255.255"){
			
			cout<<"Mascara decimal invalida"<< endl;
			break;
		}
		else
		cout<<"Mascara decimal valida" << endl;		
		
	
		if (masc=="255.0.0.0"){
			CIDR = 8;
		}else if(masc=="255.128.0.0"){
			CIDR = 9;			
		}else if(masc=="255.192.0.0"){
			CIDR = 10;	
		}else if(masc=="255.192.0.0"){//
			CIDR = 11;
		}else if(masc=="255.224.0.0"){
			CIDR = 12;
		}else if(masc=="255.240.0.0"){
			CIDR = 13;
		}else if(masc=="255.248.0.0"){
			CIDR = 14;
		}else if(masc=="255.250.0.0"){
			CIDR = 15;
		}else if(masc=="255.255.0.0"){
			CIDR = 16;
		}else if(masc=="255.255.128.0"){
			CIDR = 17;
		}else if(masc=="255.255.192.0"){
			CIDR = 18;
		}else if(masc=="255.255.224.0"){
			CIDR = 19;
		}else if(masc=="255.255.240.0"){
			CIDR = 20;
		}else if(masc=="255.255.248.0"){
			CIDR = 21;
		}else if(masc=="255.255.252.0"){
			CIDR = 22;
		}else if(masc=="255.255.254.0"){
			CIDR = 23;
		}else if(masc=="255.255.255.0"){
			CIDR = 24;
		}else if(masc=="255.255.255.128"){
			CIDR = 25;
		}else if(masc=="255.255.255.192"){
			CIDR = 26;
		}else if(masc=="255.255.255.224"){
			CIDR = 27;
		}else if(masc=="255.255.255.240"){
			CIDR = 28;
		}else if(masc=="255.255.255.248"){
			CIDR = 29;
		}else if(masc=="255.255.255.252"){
			CIDR = 30;
		}else if(masc=="255.255.255.254"){
			CIDR = 31;
		}else if(masc=="255.255.255.255"){
			CIDR = 32;
	}


	// Empacota bits do endereço IP em um inteiro
	octetosEndereco = (octetoArr[0] << 24) | (octetoArr[1] << 16) | (octetoArr[2] << 8) | (octetoArr[3]);

	// Chama a função subnetinfo para a rede
	if (octetoArr[0] < 224){
		printarInfosubrede(&octetosEndereco, &CIDR);
	} 
	
	
	cout<<" Se Deseja calcular mais um IP sem classe, com mascara decimal, no menu selecione(2)..."<<endl;
	free(octetoArr);
	return;
}
}

void calculoIPSemclassCIDR(){	
	char ip[18];
	char buffer[4];
	string operar;	
    unsigned char* octetoArr;
    octetoArr= (unsigned char*) malloc(4 * sizeof(char));
	int CIDR,  i; 
	unsigned int octetosEndereco;	 
                
	while (1) {  //Pega o endereço
		cout<<"Por favor, digite o endereco IPv4: \n"<<endl;
		if (fgets(ip, sizeof ip, stdin) == NULL){ //tratamento do fgets
		    break;
			}
		fgets(ip, 17, stdin);
		ip[strlen(ip)-1] = '\0';
		
		
		cout<<"Verificando se ip esta correto: ... "<<ip<<endl;

	//Verifica // FAZ VALIDAÇÃO
		if (verificaIP(ip,  octetoArr) == 0) {
			cout<<"\nO IP que digitou eh invalido. Tente novamente!"<<endl;
			//return;
			
		} else {
			cout<<"\nEndereco verificado! Endereco valido\n"<<endl;
			break;
		}
	}
 
	// Obtém o número CIDR // 
	while (1) {
		cout<<"Agora, digite a mascara de sub-rede na notacao (CIDR): "<<endl;
		fgets(buffer, 4, stdin);//lê um número máximo especificado de caracteres do fluxo de arquivos dado.

		CIDR = atoi(buffer);//converter um valor de string em um valor inteiro. 

		if (CIDR > 0 && CIDR < 32) {
			break;//Se o CIDR for valido sai do while e continua
		} else {
			cout<<"CIDR inserido eh invalido, por favor tente novamente...\n"<<endl;
		}
	}


	if (octetoArr[0] > 239)
    {
		cout<<"(Classe E, reservado para uso futuros)\n"<<endl;
	}
    else
	    if (octetoArr[0] > 223) 
		{
			cout<<"(Classe D, reservado para multicast)\n"<<endl;
		} 
		else 
			 if (octetoArr[0] > 191) 
			 {
				cout<<"(Classe C)\n"<<endl;
	         }else 
				if (octetoArr[0] > 127) 
				{
					cout<<"(Classe B)\n"<<endl;
				} else {
					cout<<"(Classe A)\n"<<endl;
				}
				
	    
	// Empacota bits do endereço IP em um inteiro
	octetosEndereco = (octetoArr[0] << 24) | (octetoArr[1] << 16) | (octetoArr[2] << 8) | (octetoArr[3]);

	// Chama a função subnetinfo para a rede
	if (octetoArr[0] < 224){
		printarInfosubrede(&octetosEndereco, &CIDR);
	} 
	
	//Mascaras
	
	if(CIDR == 9){
		cout<<"Mascara de rede: 255.128.0.0"<<endl;
	}
	else if(CIDR == 10){
		cout<<"Mascara de rede: 255.192.0.0"<<endl;
	}else if(CIDR == 11){
    	cout<<"Mascara de rede: 255.224.0.0"<<endl;
	}else if(CIDR == 12){
		cout<<"Mascara de rede: 255.240.0.0"<<endl;
	}else if(CIDR == 13){
		cout<<"Mascara de rede: 255.248.0.0"<<endl;
	}else if(CIDR == 14){
		cout<<"Mascara de rede: 255.252.0.0"<<endl;
	}else if(CIDR == 15){
		cout<<"Mascara de rede: 255.254.0.0"<<endl;
	}else if(CIDR == 16){
		cout<<"Mascara de rede: 255.255.0.0"<<endl;
	}else if(CIDR == 17){
		cout<<"Mascara de rede: 255.255.128.0"<<endl;
	}else if(CIDR == 18){
		cout<<"Mascara de rede: 255.255.192.0"<<endl;
	}else if(CIDR == 19){
		cout<<"Mascara de rede: 255.255.224.0"<<endl;
	}else if(CIDR == 20){
		cout<<"Mascara de rede: 255.255.240.0"<<endl;
	}else if(CIDR == 21){
		cout<<"Mascara de rede: 255.255.248.0"<<endl;
	}else if(CIDR == 22){
		cout<<"Mascara de rede: 255.255.252.0"<<endl;
	}else if(CIDR == 23){
		cout<<"Mascara de rede: 255.255.252.0"<<endl;
	}else if(CIDR == 24){
		cout<<"Mascara de rede: 255.255.255.0"<<endl;
	}else if(CIDR == 25){
		cout<<"Mascara de rede: 255.255.255.128"<<endl;
	}else if(CIDR == 26){
		cout<<"Mascara de rede: 255.255.255.192"<<endl;
	}else if(CIDR == 27){
		cout<<"Mascara de rede: 255.255.255.224"<<endl;
	}else if(CIDR == 28){
		cout<<"Mascara de rede: 255.255.255.240"<<endl;
	}else if(CIDR == 29){
		cout<<"Mascara de rede: 255.255.255.248"<<endl;
	}else if(CIDR == 30){
		cout<<"Mascara de rede: 255.255.255.252"<<endl;
	}else if(CIDR == 31){
		cout<<"Mascara de rede: 255.255.255.254"<<endl;
	}
	

	
	cout<<"Se deseja calcular mais um IP sem classe, com mascara CIDR, no menu selecione(3)..."<<endl;
	free(octetoArr);
	return;

}
 
void calculoIPNormal(){
	
	char ip[18];
	char buffer[4];	
    string operar;
	unsigned char* octetoArr;
    octetoArr= (unsigned char*) malloc(4 * sizeof(char));
	int CIDR,  i; 
	unsigned int octetosEndereco;	 
                
	while (1) {  //Pega o endereço
		cout<<"Por favor, digite o endereco IPv4: \n"<<endl;
		if (fgets(ip, sizeof ip, stdin) == NULL){ //tratamento do fgets
		    break;
			}
		fgets(ip, 17, stdin);
		ip[strlen(ip)-1] = '\0';
		
		cout<<"Verificando se ip esta correto: ... "<<ip<<endl;

	//Verifica // FAZ VALIDAÇÃO
		if (verificaIP(ip,  octetoArr) == 0) {
					cout<<"\nO IP que digitou eh invalido. Tente novamente!"<<endl;
		return;
		} else {
			cout<<"\nEndereco verificado! Endereco valido\n"<<endl;
			break;
		}
	}
  
	if (octetoArr[0] > 239)
    {
		cout<<"(Classe E, reservado para uso futuros)\n"<<endl;
	}
    else
	    if (octetoArr[0] > 223) 
		{
			cout<<"(Classe D, reservado para multicast)\n"<<endl;
		} 
		else 
			 if (octetoArr[0] > 191) 
			 {
			     CIDR = 24;
				cout<<"(Classe C)\n"<<endl;
	         }else 
				if (octetoArr[0] > 127) 
				{
				    CIDR = 16;
					cout<<"(Classe B)\n"<<endl;
				} else {
				    CIDR = 8;
					cout<<"(Classe A)\n"<<endl;
				}
							
	// Empacota bits do endereço IP em um inteiro
	octetosEndereco = (octetoArr[0] << 24) | (octetoArr[1] << 16) | (octetoArr[2] << 8) | (octetoArr[3]);

	// Chama a função subnetinfo para a rede
	if (octetoArr[0] < 224) 
		{
		printarInfosubrede(&octetosEndereco, &CIDR);
	} 
	//Mascaras
	if(CIDR == 8){
		cout<<"Mascara de rede: 255.0.0.0"<<endl;
	}else if(CIDR == 9){
		cout<<"Mascara de rede: 255.128.0.0"<<endl;
	}
	else if(CIDR == 10){
		cout<<"Mascara de rede: 255.192.0.0"<<endl;
	}else if(CIDR == 11){
    	cout<<"Mascara de rede: 255.224.0.0"<<endl;
	}else if(CIDR == 12){
		cout<<"Mascara de rede: 255.240.0.0"<<endl;
	}else if(CIDR == 13){
		cout<<"Mascara de rede: 255.248.0.0"<<endl;
	}else if(CIDR == 14){
		cout<<"Mascara de rede: 255.252.0.0"<<endl;
	}else if(CIDR == 15){
		cout<<"Mascara de rede: 255.254.0.0"<<endl;
	}else if(CIDR == 16){
		cout<<"Mascara de rede: 255.255.0.0"<<endl;
	}else if(CIDR == 17){
		cout<<"Mascara de rede: 255.255.128.0"<<endl;
	}else if(CIDR == 18){
		cout<<"Mascara de rede: 255.255.192.0"<<endl;
	}else if(CIDR == 19){
		cout<<"Mascara de rede: 255.255.224.0"<<endl;
	}else if(CIDR == 20){
		cout<<"Mascara de rede: 255.255.240.0"<<endl;
	}else if(CIDR == 21){
		cout<<"Mascara de rede: 255.255.248.0"<<endl;
	}else if(CIDR == 22){
		cout<<"Mascara de rede: 255.255.252.0"<<endl;
	}else if(CIDR == 23){
		cout<<"Mascara de rede: 255.255.254.0"<<endl;
	}else if(CIDR == 24){
		cout<<"Mascara de rede: 255.255.255.0"<<endl;
	}else if(CIDR == 25){
		cout<<"Mascara de rede: 255.255.255.128"<<endl;
	}else if(CIDR == 26){
		cout<<"Mascara de rede: 255.255.255.192"<<endl;
	}else if(CIDR == 27){
		cout<<"Mascara de rede: 255.255.255.224"<<endl;
	}else if(CIDR == 28){
		cout<<"Mascara de rede: 255.255.255.240"<<endl;
	}else if(CIDR == 29){
		cout<<"Mascara de rede: 255.255.255.248"<<endl;
	}else if(CIDR == 30){
		cout<<"Mascara de rede: 255.255.255.252"<<endl;
	}else if(CIDR == 31){
		cout<<"Mascara de rede: 255.255.255.254"<<endl;
	}
	
   cout<<"Se deseja calcular mais um IP, no menu selecione(1)..."<<endl;
   free(octetoArr);
	return;
}


void cabecalho()
{
	cout<<endl;
	cout<<" ________________________________________________________________________________________"<<endl;
    cout<<"| Calculadora Ipv4                                                                      | "<<endl; 
    cout<<"| AED de CMP1074 | Redes de Computadores 2| Prof(a) Angelica da Silva Nunes             | "<<endl;
    cout<<"| Aluno: Douglas Soares de Souza Ferreira |Matricula: 20191002800283                    |  "<<endl;
    cout<<"|_______________________________________________________________________________________|"<<endl; 
}

int verificaIP(char* ip,  unsigned char* octetoArr) {
	
	// A função verifica se um IP válido foi inserido e em seguida, atualiza 
	//a matriz octal com os octetos validados
	char* token; 
	int i = 0, j = 0, 
	contador = 0;

	// Continuaremos pegando tokens
	// enquanto não for nulo
	token = strtok(ip, ".");
	while (token != NULL) {

		// Percorre cada caractere e verifica se é um dígito
       // Se não for estourar. Usamos j para ver se ele repetiu a quantidade certa de vezes  
		for (j=0; j<strlen(token); j++) 
		{
			if (isdigit(token[j]) == 0) 
			{
				break;
			}
		}

		// Se a quantidade correta de dígitos foi inserida,
		// confirme o octeto como validado e adicione ao array
		if (strlen(token) > 0 && strlen(token) < 4 && j == strlen(token)
				&& atoi(token) < 256 && atoi(token) >= 0) 
				{
			contador++;
			octetoArr[i] = atoi(token);
		} else {
			// Não adianta continuar se mesmo um octeto falhar no teste
			break;
		}

		i++;
		token = strtok(NULL, ".");
	}

	if (contador != 4) {
		return 0;
	} else {

		return 1;
	}
}

void printarInfosubrede(unsigned int* octetosEndereco, int* CIDR) {
    // Imprime informações sobre a sub-rede fornecida.
   // Leva ponteiros para os dados necessários, porém não altera nada dentro deles.
  // Qualquer manipulação necessária é feita com variáveis locais
	unsigned int enderecoRede;
	unsigned int mascaraRede;
	
	mascaraRede = (0xFFFFFFFF << (32 - (*CIDR )) & 0xFFFFFFFF);
	enderecoRede = *octetosEndereco & mascaraRede;

	// Descompacte e exiba o endereço de rede
	printf("\nEndereco de rede: %d.%d.%d.%d/%d\n",
	(enderecoRede >> 24) & 0xFF, (enderecoRede >> 16) & 0xFF,
	(enderecoRede >> 8) & 0xFF, (enderecoRede) & 0xFF, *CIDR);

	// Subtrai o endereço de rede do endereço de broadcast e tira um do resultado para o total de hosts
	printf("Numero total de Hosts: %d\n", ((enderecoRede | ~mascaraRede) - enderecoRede) - 1);

	// Exibe o primeiro endereço do host adicionando a cada um de nossos octetos descompactados
	printf("IP inicial: %d.%d.%d.%d\n",
	 ((enderecoRede + 1) >> 24) & 0xFF, ((enderecoRede + 1) >> 16) & 0xFF,
	 ((enderecoRede + 1) >> 8) & 0xFF, (enderecoRede + 1) & 0xFF);
	
	// Bitwise OR o endereço int com a máscara negada para obter o endereço de broadcast na variável
	enderecoRede = enderecoRede | ~mascaraRede;

	// Subtrai do endereço de broadcast para o endereço final do host
	printf("IP final: %d.%d.%d.%d\n",
	 ((enderecoRede - 1) >> 24) & 0xFF, ((enderecoRede - 1) >> 16) & 0xFF,
	 ((enderecoRede - 1) >> 8) & 0xFF, (enderecoRede - 1) & 0xFF);
	
	// Descompacte e exiba o endereço de broadcast
	printf("Endereco de broadcast: %d.%d.%d.%d\n",
    (enderecoRede >> 24) & 0xFF, (enderecoRede >> 16) & 0xFF,
	(enderecoRede >> 8) & 0xFF, (enderecoRede) & 0xFF);
}
