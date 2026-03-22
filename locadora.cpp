//PARTICIPANTES
//GUSTAVO MEDEIROS SCHEIDEGGER LOPES
//FILIPPO LIMEIRA TOLOMEI
//HEITOR MARTINEZ ARRUDA CAMPOS


#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>

struct TpCliente 
{
	char CPF[15], Nome[20], Telefone[11];
	int Status;
};

struct TpCarro 
{
	int CodCar, Status;
	char Modelo[15], Categoria[15];
	float PrecoDiaria;
};

struct TpLocacao 
{
	char CPF[15];
	int CodCar, QtdeDias, Status;
	float ValorLocacao;
};

void Moldura (int x1, int y1, int x2, int y2, int cor)
{
	textcolor(cor);
	gotoxy(x1,y1);
	printf("%c", 218);
	gotoxy(x1,y2);
	printf("%c", 192);
	gotoxy(x2,y1);
	printf("%c", 191);
	gotoxy(x2,y2);
	printf("%c", 217);
	for(int i=x1+1; i<x2; i++)
	{
		gotoxy(i, y1);
		printf("%c", 196);
		gotoxy(i,y2);
		printf("%c", 196);
	}
	for(int i=y1+1; i<y2; i++)
	{
		gotoxy(x1, i);
		printf("%c", 179);
		gotoxy(x2, i);
		printf("%c", 179);
	}
	printf("\n");
}

void Interface()
{
	system("cls");
	Moldura(1,1,80,25,7);
	Moldura(2,2,79,4,7);
}

char MenuCCL()
{
	gotoxy(30,7);
	printf("[A] Cliente");
	gotoxy(30,8);
	printf("[B] Carro");
	gotoxy(30,9);
	printf("[C] Locacao");
	gotoxy(30,10);
	printf("[ESC] Sair");
	gotoxy(30,11);
	printf("Opcao: ");
	return toupper(getche());
}

char MenuGeral()
{
	Interface();
	gotoxy(30,3);
	printf("### LOCADORA ###");
	gotoxy(30,7);
	printf("[A] Manutencao Completa");
	gotoxy(30,8);
	printf("[B] Relatorios");
	gotoxy(30,9);
	printf("[ESC] Sair");
	gotoxy(30,10);
	printf("Opcao: ");
	return toupper(getche());
}

char MenuManutencao()
{
	Interface();
	gotoxy(30,3);
	printf("### Manutencao Geral ###");
	gotoxy(30,7);
	printf("[A] Cadastrar");
	gotoxy(30,8);
	printf("[B] Excluir");
	gotoxy(30,9);
	printf("[C] Alterar");
	gotoxy(30,10);
	printf("[D] Listar");
	gotoxy(30,11);
	printf("[ESC] Sair");
	gotoxy(30,12);
	printf("Opcao: ");
	return toupper(getche());
}

char MenuRelatorio()
{
	Interface();
	gotoxy(30,3);
	printf("### Relatorios ###");
	gotoxy(30,7);
	printf("[A] Clientes +3 Locacoes");
	gotoxy(30,8);
	printf("[B] Carros por Categoria");
	gotoxy(30,9);
	printf("[C] Locacao com Valor > Limite");
	gotoxy(30,10);
	printf("[D] Locacoes por CPF");
	gotoxy(30,11);
	printf("[E] Completo");
	gotoxy(30,12);
	printf("[ESC] Sair");
	gotoxy(30,13);
	printf("Opcao: ");
	return toupper(getche());
}

char MenuCarro()
{
	Interface();
	gotoxy(30,3);
	printf("### Ordenar Carros ###");
	gotoxy(30,7);
	printf("[A] Por Codigo");
	gotoxy(30,8);
	printf("[B] Por Modelo");
	gotoxy(30,9);
	printf("[ESC] Sair");
	gotoxy(30,10);
	printf("Opcao: ");
	return toupper(getche());
}

int VerifCPF(char CPF[], int x, int y)
{
	int soma, mult, i, aux, num;
	if (CPF[3] == '.')
	{
		if(CPF[7] == '.')
		{
			if(CPF[11] == '-')
			{
				soma=0;
				for(i=0, mult=10; mult>=2; i++)
				{
					if(i!=3 && i!=7 && i!=11)
					{
						num = CPF[i] - '0';
						soma += num * mult;
						mult--;
					}
				}
					
				aux = soma*10%11;
				if(aux==10)
					aux=0;
				
				soma=0;
				if (aux==CPF[12]-'0')
				{
					for(i=0, mult=11; mult>=2; i++)
					{
						if(i!=3 && i!=7 && i!=11)
						{
							num = CPF[i] - '0';
							soma += num * mult;
							mult--;
						}
					}
							
					aux = soma*10%11;
					if(aux==10)
						aux=0;
					
					if(aux!=CPF[13]-'0')
					{
						gotoxy(x, y);
						printf("Esse CPF nao existe!");
						return 0;
					}
					
					return 1;
				}
				else
				{
					gotoxy(x, y);
					printf("Esse CPF nao existe!");
					getch();
					return 0;
				}
					
			}
			else
			{
				gotoxy(x, y);
				printf("CPF Invalido!");
				getch();
				return 0;
			}
				
				
		}
		else
		{
			gotoxy(x, y);
			printf("CPF Invalido!");
			getch();
			return 0;
		}
			
	}		
	else
	{
		gotoxy(x, y);
		printf("CPF Invalido!");
		getch();
		return 0;
	}
}

int VerifTelefone (char Telefone[], int x, int y)
{
	int i=0, flag=0;
	if(Telefone[5]=='-')
	{
		if(strlen(Telefone) == 10)
		{
			while(i<strlen(Telefone))
			{
				if(i!=5)
				{
					if(Telefone[i]<48 || Telefone[i]>57)
						flag=1;
				}
				i++;
					
			}
			if(flag==1)
			{
				gotoxy(x,y);
				printf("Telefone Invalido!");
				return 0;
			}
			
			return 1;
		}
		else
			{
				gotoxy(x,y);
				printf("Telefone com tamanho errado!");
				return 0;
			}		
	}
	else
		{
			gotoxy(x,y);
			printf("Telefone estruturado incorretamente!");
			return 0;
		}
}

void VerifString (char String[], int x, int y)
{
	while(strcmp(String, "\0") == 0)
	{
		gotoxy(x, y);
		fflush(stdin);
		gets(String);
	}
}

int BuscaClienteSeqIndex(char CPF[], FILE *PtrBusca)
{
	TpCliente Cliente;
	rewind(PtrBusca);
	fread(&Cliente, sizeof(TpCliente), 1, PtrBusca);
	while(!feof(PtrBusca) && (strcmp(CPF, Cliente.CPF) > 0 || Cliente.Status != 1))
		fread(&Cliente, sizeof(TpCliente), 1, PtrBusca);
					
	if(!feof(PtrBusca) && (strcmp(CPF, Cliente.CPF) == 0 && Cliente.Status == 1))
		return ftell(PtrBusca) - sizeof(TpCliente);
	
	return -1;
}

int BuscaLocacaoExaust(char CPF[], int Cod, FILE *PtrLoc)
{
	TpLocacao Locacao;
	rewind(PtrLoc);
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc) && (strcmp(CPF, Locacao.CPF)!=0 || Cod!=Locacao.CodCar || Locacao.Status != 1))
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	
	if(!feof(PtrLoc))
		return ftell(PtrLoc) - sizeof(TpLocacao);
		
	return -1;
}


void InsercaoCliente(TpCliente ClienteA, FILE *Ptr)
{
	TpCliente ClienteB;
	int pos;
	fseek(Ptr, 0, 2);
	fwrite(&ClienteA, sizeof(TpCliente), 1, Ptr);
	
	pos = ftell(Ptr)/sizeof(TpCliente)-1;
	
	fseek(Ptr, (pos-1)*sizeof(TpCliente), 0);
	fread(&ClienteB, sizeof(TpCliente), 1, Ptr);
	while(pos>0 && stricmp(ClienteA.CPF, ClienteB.CPF)<0)
	{
		fseek(Ptr, pos*sizeof(TpCliente), 0);
		fwrite(&ClienteB, sizeof(TpCliente), 1, Ptr);
		fseek(Ptr, (pos-1)*sizeof(TpCliente), 0);
		fwrite(&ClienteA, sizeof(TpCliente), 1, Ptr);
		pos--;
		
		if(pos>0)
		{
			fseek(Ptr, (pos-1)*sizeof(TpCliente), 0);
			fread(&ClienteB, sizeof(TpCliente), 1, Ptr);
		}
	}	
}

void CadastroCliente()
{
	TpCliente Cliente;
	FILE *PtrCli = fopen("clientes.dat", "rb+");
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Cadastro de Clientes ###");

	gotoxy(30,7);
	printf("CPF [ENTER para sair]: ");
	fflush(stdin);
	gets(Cliente.CPF);
	while(strcmp(Cliente.CPF, "\0")!=0)
	{
		if(VerifCPF(Cliente.CPF, 30, 8))
		{
			pos = BuscaClienteSeqIndex(Cliente.CPF, PtrCli);
			if(pos!=-1)
			{
				gotoxy(30,8);
				printf("Cliente ja cadastrado!");
			}
			else
				{
					gotoxy(30,8);
					printf("Nome: ");
					fflush(stdin);
					gets(Cliente.Nome);
					VerifString(Cliente.Nome, 36, 8);
					gotoxy(30, 9);
					printf("Telefone: ");
					fflush(stdin);
					gets(Cliente.Telefone);
					while(!(VerifTelefone(Cliente.Telefone, 30, 10)))
					{
						gotoxy(40, 9);
						printf("                            ");
						fflush(stdin);
						gotoxy(40, 9);
						gets(Cliente.Telefone);
					}
					gotoxy(30, 10);
					printf("                             ");
					Cliente.Status = 1;
					
					InsercaoCliente(Cliente, PtrCli);
					gotoxy(30, 11);
					printf("Cadastro concluido!");					
				}
		}
		getch();
		Interface();
		gotoxy(30,3);
		printf("### Cadastro de Clientes ###");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Cliente.CPF);
		
	}
	fclose(PtrCli);

}

int PosicaoMaior (FILE *PtrCar, int tam)
{
	int PosMaior, i;
	TpCarro CarroMaior, Carro;
	fseek(PtrCar, 0, 0);
	fread(&CarroMaior, sizeof(TpCarro), 1, PtrCar);
	PosMaior = 0;

    for (i=1; i<tam; i++) 
    {
    	fseek(PtrCar, i*sizeof(TpCarro), 0);
    	fflush(PtrCar);
    	fread(&Carro, sizeof(TpCarro), 1, PtrCar);
    	if (CarroMaior.CodCar < Carro.CodCar) 
        { 
        	fseek(PtrCar, i*sizeof(TpCarro), 0);
        	fread(&CarroMaior, sizeof(TpCarro), 1, PtrCar);
        	PosMaior=i;
	    } 
    }
    
	return PosMaior;
}

void OrdCarrosCod ()
{
	FILE *PtrCar = fopen("carros.dat", "rb+");
	TpCarro CarroMaior, Carro,Senti;
	int posMaior, tam,num=0;
	
	fseek(PtrCar, 0, 0);
	fread(&Senti,sizeof(TpCarro),1,PtrCar);
	while(!feof(PtrCar))
	{
		if(Senti.Status!=2)
		{
			num++;
		}
		fread(&Senti,sizeof(TpCarro),1,PtrCar);
	}
	tam=num;

	while (tam > 0) 
	{ 
		posMaior = PosicaoMaior(PtrCar, tam); 
		if (posMaior < tam-1) 
		{ 
			fseek(PtrCar, posMaior*sizeof(TpCarro), 0);
			fread(&CarroMaior, sizeof(TpCarro), 1, PtrCar);
			fseek(PtrCar, (tam-1)*sizeof(TpCarro), 0);
			fread(&Carro, sizeof(TpCarro), 1, PtrCar);
			
			fseek(PtrCar, posMaior*sizeof(TpCarro), 0);	
			fwrite(&Carro, sizeof(TpCarro), 1, PtrCar);
			fseek(PtrCar, (tam-1)*sizeof(TpCarro), 0);
			fwrite(&CarroMaior, sizeof(TpCarro), 1, PtrCar);
		} 
		tam--; 
	} 
	
	fclose(PtrCar);
}



void OrdCarrosMod()
{
	int i, tam;
	FILE *PtrCar = fopen("carros.dat", "rb+");
	TpCarro CarroA, CarroB;
	
	fseek(PtrCar, 0, 2);
	tam = ftell(PtrCar)/sizeof(TpCarro);
	
   	while(tam>0) 
	{ 
	    for (i=0; i<tam-1; i++) 
	    {
	    	fseek(PtrCar, i*sizeof(TpCarro), 0);
			fread(&CarroA, sizeof(TpCarro), 1, PtrCar);
			fseek(PtrCar, (i+1)*sizeof(TpCarro), 0);
			fread(&CarroB, sizeof(TpCarro), 1, PtrCar);
			if (stricmp(CarroA.Modelo, CarroB.Modelo) > 0) 
	        { 
	        	fseek(PtrCar, i*sizeof(TpCarro), 0);
	        	fwrite(&CarroB, sizeof(TpCarro), 1, PtrCar);
	        	fseek(PtrCar, (i+1)*sizeof(TpCarro), 0);
	        	fwrite(&CarroA, sizeof(TpCarro), 1, PtrCar);
	        }  
	    }
	        
	    tam--; 
	}
	
	fclose(PtrCar);
}

void OrdCliente()
{
	int i, tam;
	FILE *PtrCli = fopen("clientes.dat", "rb+");
	TpCliente ClienteA, ClienteB;
	
	fseek(PtrCli, 0, 2);
	tam = ftell(PtrCli)/sizeof(TpCliente);
	
   	while(tam>0) 
	{ 
	    for (i=0; i<tam-1; i++) 
	    {
	    	fseek(PtrCli, i*sizeof(TpCliente), 0);
			fread(&ClienteA, sizeof(TpCliente), 1, PtrCli);
			fseek(PtrCli, (i+1)*sizeof(TpCliente), 0);
			fread(&ClienteB, sizeof(TpCliente), 1, PtrCli);
			if (stricmp(ClienteA.CPF, ClienteB.CPF) > 0) 
	        { 
	        	fseek(PtrCli, i*sizeof(TpCliente), 0);
	        	fwrite(&ClienteB, sizeof(TpCliente), 1, PtrCli);
	        	fseek(PtrCli, (i+1)*sizeof(TpCliente), 0);
	        	fwrite(&ClienteA, sizeof(TpCarro), 1, PtrCli);
	        }  
	    }
	        
	    tam--; 
	}
	fclose(PtrCli);
}

void OrdLoc()
{
	int i, tam;
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	TpLocacao LocA, LocB;
	
	fseek(PtrLoc, 0, 2);
	tam = ftell(PtrLoc)/sizeof(TpLocacao);
	
   	while(tam>0) 
	{ 
	    for (i=0; i<tam-1; i++) 
	    {
	    	fseek(PtrLoc, i*sizeof(TpLocacao), 0);
			fread(&LocA, sizeof(TpLocacao), 1, PtrLoc);
			fseek(PtrLoc, (i+1)*sizeof(TpLocacao), 0);
			fread(&LocB, sizeof(TpLocacao), 1, PtrLoc);
			if (stricmp(LocA.CPF, LocB.CPF) > 0) 
	        { 
	        	fseek(PtrLoc, i*sizeof(TpLocacao), 0);
	        	fwrite(&LocB, sizeof(TpLocacao), 1, PtrLoc);
	        	fseek(PtrLoc, (i+1)*sizeof(TpLocacao), 0);
	        	fwrite(&LocA, sizeof(TpLocacao), 1, PtrLoc);
	        }  
	    }
	        
	    tam--; 
	}
	fclose(PtrLoc);
}

int BuscaCarroSentinela(int Cod, FILE *PtrCar)
{
	TpCarro Carro, Sentinela;
	int i;
	Sentinela.CodCar = Cod;
	Sentinela.Status = 2;
	fseek(PtrCar, 0, 2);
	i = ftell(PtrCar)/sizeof(TpCarro);
	fwrite(&Sentinela, sizeof(TpCarro), 1, PtrCar);
	rewind(PtrCar);
	fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	while(Carro.CodCar != Cod || Carro.Status < 1)
		fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	
	int p=ftell(PtrCar) - sizeof(TpCarro);
		
	
	if(Carro.Status == 1)
		return p;
	return -1;

}

int BuscaCarroBinaria(int Cod, FILE *PtrBusca)
{
	TpCarro Senti,CarroM;
	int pos,i,f,m,num=0;
	
	fseek(PtrBusca,0,0);
	i = ftell(PtrBusca)/sizeof(TpCarro);
	
	fseek(PtrBusca, 0, 0);
	fread(&Senti,sizeof(TpCarro),1,PtrBusca);
	while(!feof(PtrBusca))
	{
		if(Senti.Status!=2)
		{
			num++;
		}
		fread(&Senti,sizeof(TpCarro),1,PtrBusca);
	}
	f=num;
	
	m = f/2;
	
	fseek(PtrBusca,m*sizeof(TpCarro),0);
	fread(&CarroM,sizeof(TpCarro),1,PtrBusca);
	while(i<f && (Cod!=CarroM.CodCar || CarroM.Status != 1))
	{
		if(Cod>CarroM.CodCar)
		{
			i=m+1;
		}
		else
			{
				f=m-1;
			}
		m=(i+f)/2;
		fseek(PtrBusca,m*sizeof(TpCarro),0);
		fread(&CarroM,sizeof(TpCarro),1,PtrBusca);
	}
	
	if(Cod == CarroM.CodCar && CarroM.Status == 1)
		return m*sizeof(TpCarro);
	else
		return -1;
}


void InsercaoCarro(TpCarro CarroA, FILE *Ptr)
{
	TpCarro CarroB,Senti;
	int pos,num=0;;
	fseek(Ptr, 0, 0);
	fread(&Senti,sizeof(TpCarro),1,Ptr);
	while(!feof(Ptr))
	{
		if(Senti.Status!=2)
		{
			num++;
		}
		fread(&Senti,sizeof(TpCarro),1,Ptr);
	}
	fseek(Ptr,num*sizeof(TpCarro),0);
	fwrite(&CarroA, sizeof(TpCarro), 1, Ptr);
	
	pos = ftell(Ptr)/sizeof(TpCarro)-1;
	
	fseek(Ptr, (pos-1)*sizeof(TpCarro), 0);
	fread(&CarroB, sizeof(TpCarro), 1, Ptr);
	while(pos>0 && CarroA.CodCar<CarroB.CodCar)
	{
		fseek(Ptr, pos*sizeof(TpCarro), 0);
		fwrite(&CarroB, sizeof(TpCarro), 1, Ptr);
		fseek(Ptr, (pos-1)*sizeof(TpCarro), 0);
		fwrite(&CarroA, sizeof(TpCarro), 1, Ptr);
		pos--;
		
		if(pos>0)
		{
			fseek(Ptr, (pos-1)*sizeof(TpCarro), 0);
			fread(&CarroB, sizeof(TpCarro), 1, Ptr);
		}
	}	
}


void CadastroCarro()
{
	TpCarro Carro;
	FILE *PtrCar = fopen("carros.dat", "rb+");
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Cadastro de Carros ###");
	gotoxy(30,7);
	printf("Codigo do Carro [0 para sair]: ");
	scanf("%d", &Carro.CodCar);
	while(Carro.CodCar>0)
	{
		pos = BuscaCarroBinaria(Carro.CodCar, PtrCar);
		if(pos!=-1)
		{
			gotoxy(30,8);
			printf("Carro ja cadastrado!");
		}
		else
			{
				gotoxy(30,8);
				printf("Modelo: ");
				fflush(stdin);
				gets(Carro.Modelo);
				VerifString(Carro.Modelo, 38, 8);
				gotoxy(30, 9);
				printf("Categoria: ");
				fflush(stdin);
				gets(Carro.Categoria);
				VerifString(Carro.Categoria, 41, 9);
				gotoxy(30, 10);
				printf("Preco Diaria: ");
				scanf("%f",&Carro.PrecoDiaria);
				Carro.Status = 1;
				
				InsercaoCarro(Carro, PtrCar);
				gotoxy(30, 12);
				printf("Cadastro concluido!");					
			}
	
		getch();
		Interface();
		gotoxy(30,3);
		printf("### Cadastro de Carros ###");
		gotoxy(30,7);
		printf("Codigo do Carro [0 para sair]: ");
		scanf("%d", &Carro.CodCar);
		
	}
	fclose(PtrCar);

}

void InsercaoLocacao(TpLocacao LocacaoA, FILE *Ptr)
{
	TpLocacao LocacaoB;
	int pos;
	fseek(Ptr, 0, 2);
	fwrite(&LocacaoA, sizeof(TpLocacao), 1, Ptr);
	
	pos = ftell(Ptr)/sizeof(TpLocacao)-1;
	
	fseek(Ptr, (pos-1)*sizeof(TpLocacao), 0);
	fread(&LocacaoB, sizeof(TpLocacao), 1, Ptr);
	while(pos>0 && stricmp(LocacaoA.CPF, LocacaoB.CPF)<0)
	{
		fseek(Ptr, pos*sizeof(TpLocacao), 0);
		fwrite(&LocacaoB, sizeof(TpLocacao), 1, Ptr);
		fseek(Ptr, (pos-1)*sizeof(TpLocacao), 0);
		fwrite(&LocacaoA, sizeof(TpLocacao), 1, Ptr);
		pos--;
		
		if(pos>0)
		{
			fseek(Ptr, (pos-1)*sizeof(TpLocacao), 0);
			fread(&LocacaoB, sizeof(TpLocacao), 1, Ptr);
		}
	}	
}

void CadastroLocacao()
{
	TpLocacao Locacao;
	TpCarro Carro;
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Cadastro de Locacoes ###");

	gotoxy(30,7);
	printf("CPF [ENTER para sair]: ");
	fflush(stdin);
	gets(Locacao.CPF);
	while(strcmp(Locacao.CPF, "\0")!=0)
	{
		if(VerifCPF(Locacao.CPF, 30, 8))
		{
			FILE *PtrCli = fopen("clientes.dat", "rb");
			pos = BuscaClienteSeqIndex(Locacao.CPF, PtrCli);
			fclose(PtrCli);
			if(pos!=-1)
			{
				gotoxy(30,8);
				printf("Codigo do Carro: ");
				scanf("%d", &Locacao.CodCar);
				FILE *PtrCar = fopen("carros.dat", "rb");
				pos = BuscaCarroBinaria(Locacao.CodCar, PtrCar);
				if(pos!=-1)
				{
					fseek(PtrCar, pos, 0);
					fread(&Carro, sizeof(TpCarro), 1, PtrCar);
				}
				fclose(PtrCar);
				if(pos!=-1)
				{
					if(BuscaLocacaoExaust(Locacao.CPF, Locacao.CodCar, PtrLoc)!=-1)
					{
						gotoxy(30,10);
						printf("Locacao ja Cadastrada!");
					}
					else
					{
						gotoxy(30, 9);
						printf("Qtde Dias: ");
						scanf("%d", &Locacao.QtdeDias);
						gotoxy(30,10);
						Locacao.ValorLocacao = Carro.PrecoDiaria*Locacao.QtdeDias;
						printf("Valor Locacao: %.2f", Locacao.ValorLocacao);
						Locacao.Status = 1;
						InsercaoLocacao(Locacao, PtrLoc);
						gotoxy(30, 12);
						printf("Cadastro concluido!");
					}
					
				}
				else
				{
					gotoxy(30,9);
					printf("Carro nao Cadastrado!");
				}
				
			}
			else
				{
					gotoxy(30,8);
					printf("Cliente nao Cadastrado!");				
				}
		}
		getch();
		Interface();
		gotoxy(30,3);
		printf("### Cadastro de Locacoes ###");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Locacao.CPF);
		
	}
	fclose(PtrLoc);

}

void ExclusaoCliLoc(char CPF[])
{
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	TpLocacao Locacao;
	int i=0;
	
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc))
	{
		if(strcmp(Locacao.CPF, CPF)==0)
		{
			Locacao.Status = 0;
			
			fseek(PtrLoc, i*sizeof(TpLocacao), 0);
			fwrite(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
		}
		i++;
		fseek(PtrLoc, i*sizeof(TpLocacao), 0);
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	}
	
	fclose(PtrLoc);
	
}

void ExclusaoCarLoc(int cod)
{
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	TpLocacao Locacao;
	int i=0;
	
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc))
	{
		if(Locacao.CodCar == cod)
		{
			Locacao.Status = 0;
			
			fseek(PtrLoc, i*sizeof(TpLocacao), 0);
			fwrite(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
		}
		i++;
		fseek(PtrLoc, i*sizeof(TpLocacao), 0);
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	}
	
	fclose(PtrLoc);
	
}

void ExclusaoFisica(void)
{
    TpCliente RCli;
    TpCarro RCar;
    TpLocacao RLoc;

    //Exclusao carros.
    FILE *PtrArq = fopen("Carros.dat", "rb");
    rewind(PtrArq);
    FILE *PtrTemp = fopen("Temp.dat", "wb");
    rewind(PtrTemp);
	
	fread(&RCar, sizeof(TpCarro), 1, PtrArq);
    while(!feof(PtrArq))
    {
        if(RCar.Status == 1){
            fwrite(&RCar, sizeof(TpCarro), 1, PtrTemp);
        }
        fread(&RCar, sizeof(TpCarro), 1, PtrArq);
    }
    fclose(PtrArq);
    fclose(PtrTemp);
    remove("Carros.dat");
    rename("Temp.dat", "Carros.dat");
    

    //Exclusao clientes.
    PtrArq = fopen("Clientes.dat", "rb");
    rewind(PtrArq);
    PtrTemp = fopen("Temp.dat", "wb");
    rewind(PtrTemp);

	fread(&RCli, sizeof(TpCliente), 1, PtrArq);
    while(!feof(PtrArq))
    {
        if(RCli.Status == 1){
            fwrite(&RCli, sizeof(TpCliente), 1, PtrTemp);
        }
        fread(&RCli, sizeof(TpCliente), 1, PtrArq);
    }
    fclose(PtrArq);
    fclose(PtrTemp);
    remove("Clientes.dat");
    rename("Temp.dat", "Clientes.dat");
    
    //Exclusao Loc.
    PtrArq = fopen("Locacoes.dat", "rb");
    rewind(PtrArq);
   	PtrTemp = fopen("Temp.dat", "wb");
    rewind(PtrTemp);

	fread(&RLoc, sizeof(TpLocacao), 1, PtrArq);
    while(!feof(PtrArq))
    {
        if(RLoc.Status == 1){
            fwrite(&RLoc, sizeof(TpLocacao), 1, PtrTemp);
        }
        fread(&RLoc, sizeof(TpLocacao), 1, PtrArq);
    }
    fclose(PtrArq);
    fclose(PtrTemp);
    remove("Locacoes.dat");
    rename("Temp.dat", "Locacoes.dat");
}

int SemRegistroCli()
{
	TpCliente Cliente;
	FILE *PtrCli = fopen("clientes.dat", "rb");
	int flag=1;
	fread(&Cliente, sizeof(TpCliente), 1, PtrCli);
	while(!feof(PtrCli))
	{
		if(Cliente.Status == 1)	
			flag=0;
			
		fread(&Cliente, sizeof(TpCliente), 1, PtrCli);
	}
	
	fclose(PtrCli);
	
	return flag;
}

void ExclusaoCliente()
{
	TpCliente Cliente;
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Exclusao de Clientes ###");
	if(SemRegistroCli())
	{
		gotoxy(30,7);
		printf("Nenhum cliente cadastrado!");
		getch();
	}
	else
	{
		FILE *PtrCli = fopen("clientes.dat", "rb+");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Cliente.CPF);
		while(strcmp(Cliente.CPF, "\0")!=0)
		{
			if(VerifCPF(Cliente.CPF, 30, 8))
			{
				pos = BuscaClienteSeqIndex(Cliente.CPF, PtrCli);
				if(pos!=-1)
				{
					ExclusaoCliLoc(Cliente.CPF);
					fseek(PtrCli, pos, 0);
					fread(&Cliente, sizeof(TpCliente),1 , PtrCli);
					Cliente.Status = 0;
					fseek(PtrCli, pos, 0);
					fwrite(&Cliente, sizeof(TpCliente),1 , PtrCli);
					gotoxy(30,8);
					printf("Cliente excluido com sucesso!");
				}
				else
					{
						gotoxy(30,8);
						printf("Cliente nao cadastrado!");				
					}
			}
			getch();
			Interface();
			gotoxy(30,3);
			printf("### Exclusao de Clientes ###");
			gotoxy(30,7);
			printf("CPF [ENTER para sair]: ");
			fflush(stdin);
			gets(Cliente.CPF);
			
		}
		fclose(PtrCli);
	}
}

int SemRegistroCar()
{
	TpCarro Carro;
	FILE *PtrCar = fopen("carros.dat", "rb");
	int flag=1;
	fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	while(!feof(PtrCar))
	{
		if(Carro.Status == 1)	
			flag=0;
			
		fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	}
	
	fclose(PtrCar);
	
	return flag;
}

void ExclusaoCarro()
{
	TpCarro Carro;
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Exclusao de Carros ###");
	if(SemRegistroCar())
	{
		gotoxy(30,7);
		printf("Nenhum carro cadastrado!");
		getch();
	}
	else
	{
		FILE *PtrCar = fopen("carros.dat", "rb+");
		gotoxy(30,7);
		printf("Codigo do Carro [0 para sair]: ");
		scanf("%d", &Carro.CodCar);
		while(Carro.CodCar>0)
		{
			pos = BuscaCarroBinaria(Carro.CodCar, PtrCar);
			if(pos!=-1)
			{
				ExclusaoCarLoc(Carro.CodCar);
				fseek(PtrCar, pos, 0);
				fread(&Carro, sizeof(TpCarro),1 , PtrCar);
				Carro.Status = 0;
				fseek(PtrCar, pos, 0);
				fwrite(&Carro, sizeof(TpCarro),1 , PtrCar);
				gotoxy(30,8);
				printf("Carro excluido com sucesso!");
			}
			else
				{
					gotoxy(30,8);
					printf("Carro nao cadastrado!");				
				}
			
			getch();
			Interface();
			gotoxy(30,3);
			printf("### Exclusao de Carros ###");
			gotoxy(30,7);
			printf("Codigo do Carro [0 para sair]: ");
			scanf("%d", &Carro.CodCar);
		}
		fclose(PtrCar);
	}
}

int SemRegistroLoc()
{
	TpLocacao Locacao;
	FILE *PtrLoc = fopen("locacoes.dat", "rb");
	int flag=1;
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc))
	{
		if(Locacao.Status == 1)	
			flag=0;
			
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	}
	
	fclose(PtrLoc);
	
	return flag;
}

void ExclusaoLocacao()
{
	TpLocacao Locacao;
	int pos;
	Interface();
	gotoxy(30,3);
	printf("### Exclusao de Locacoes ###");
	if(SemRegistroLoc())
	{
		gotoxy(30,7);
		printf("Nenhuma locacao cadastrada!");
		getch();
	}
	else
	{
		FILE *PtrLoc = fopen("locacoes.dat", "rb+");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Locacao.CPF);
		while(strcmp(Locacao.CPF, "\0")!=0)
		{
			if(VerifCPF(Locacao.CPF, 30, 8))
			{
				FILE *PtrCli = fopen("clientes.dat", "rb");
				pos = BuscaClienteSeqIndex(Locacao.CPF, PtrCli);
				fclose(PtrCli);
				if(pos!=-1)
				{
					gotoxy(30,8);
					printf("Codigo do Carro: ");
					scanf("%d", &Locacao.CodCar);
					FILE *PtrCar = fopen("carros.dat", "rb");
					pos = BuscaCarroBinaria(Locacao.CodCar, PtrCar);
					if(pos!=-1)
					{
						pos = BuscaLocacaoExaust(Locacao.CPF, Locacao.CodCar, PtrLoc);
						if(pos!=-1)
						{
							fseek(PtrLoc, pos, 0);
							fread(&Locacao, sizeof(TpLocacao),1 , PtrLoc);
							Locacao.Status = 0;
							fseek(PtrLoc, pos, 0);
							fwrite(&Locacao, sizeof(TpLocacao),1 , PtrLoc);
							gotoxy(30,9);
							printf("Locacao excluida com sucesso!");
						}
						else
							{
								gotoxy(30,9);
								printf("Locacao nao cadastrada!");
							}
						
					}
					else
						{
							gotoxy(30,9);
							printf("Carro nao cadastrado!");
						}
					
				}
				else
					{
						gotoxy(30,8);
						printf("Cliente nao cadastrado!");				
					}
			
			}
			
			getch();
			Interface();
			gotoxy(30,3);
			printf("### Exclusao de Locacoes ###");
			gotoxy(30,7);
			printf("CPF [ENTER para sair]: ");
			fflush(stdin);
			gets(Locacao.CPF);
		}
		fclose(PtrLoc);
		
	}
}

void AlteracaoCliLoc(TpCliente ClienteA, TpCliente ClienteD)
{
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	TpLocacao Locacao;
	int i=0;
	
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc))
	{
		if(strcmp(Locacao.CPF, ClienteA.CPF)==0 && Locacao.Status == 1)
		{
			strcpy(Locacao.CPF, ClienteD.CPF);
			fseek(PtrLoc, i*sizeof(TpLocacao), 0);
			fwrite(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
		}
		i++;
		fseek(PtrLoc, i*sizeof(TpLocacao), 0);
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	}
	
	fclose(PtrLoc);
}



void AlteracaoCliente()
{
	TpCliente ClienteA, ClienteD;
	int pos, pos2;
	Interface();
	gotoxy(30,3);
	printf("### Alteracao de Clientes ###");
	if(SemRegistroCli())
	{
		gotoxy(30,7);
		printf("Nenhum cliente cadastrado!");
		getch();
	}
	else
	{
		FILE *PtrCli = fopen("clientes.dat", "rb+");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(ClienteA.CPF);
		while(strcmp(ClienteA.CPF, "\0")!=0)
		{
			if(VerifCPF(ClienteA.CPF, 30, 8))
			{
				pos = BuscaClienteSeqIndex(ClienteA.CPF, PtrCli);
				if(pos!=-1)
				{
					fseek(PtrCli, pos, 0);
					fread(&ClienteA, sizeof(TpCliente), 1, PtrCli);
					gotoxy(30, 9);
					printf("### Dados do Cliente ###");
					gotoxy(30, 11);
					printf("CPF: %s", ClienteA.CPF); 
					gotoxy(30, 12);
					printf("NOME: %s", ClienteA.Nome);
					gotoxy(30,13);
		            printf("TELEFONE: %s", ClienteA.Telefone);
		            gotoxy(30,15);
		            printf("Deseja alterar (S/N)? ");
		            if(toupper(getche())=='S')
		            {
		            	gotoxy(30,15);
		            	printf("                               ");
						gotoxy(30, 9);
						printf("                               ");
						gotoxy(30, 9);
						printf("### Novos Dados do Cliente ###");
						gotoxy(35, 11);
						printf("                               ");
						gotoxy(35, 11);
						gets(ClienteD.CPF);
						if(VerifCPF(ClienteD.CPF, 35, 12))
						{
							pos2 = BuscaClienteSeqIndex(ClienteD.CPF, PtrCli);
							if(pos2!=-1 && pos!=pos2)
							{
								gotoxy(30,12);
								printf("CPF ja cadastrado!");
								getch();
							}
							else
								{
									gotoxy(36, 12);
									printf("                            ");
									gotoxy(36, 12);
									gets(ClienteD.Nome);
									VerifString(ClienteD.Nome,36, 12);
									gotoxy(40, 13);
									printf("                            ");
									gotoxy(40, 13);
									gets(ClienteD.Telefone);
									while(!(VerifTelefone(ClienteD.Telefone, 40, 14)))
									{
										gotoxy(40, 13);
										printf("                             ");
										fflush(stdin);
										gotoxy(40, 13);
										gets(ClienteD.Telefone);
										gotoxy(40, 14);
										printf("                                       ");
									}
									gotoxy(40, 14);
									printf("                                       ");
									ClienteD.Status = 1;
									fseek(PtrCli, pos, 0);
									fwrite(&ClienteD, sizeof(TpCliente), 1, PtrCli);
									AlteracaoCliLoc(ClienteA, ClienteD);
									gotoxy(30,15);
									printf("Cliente Alterado com Sucesso!");
									getch();
								}
						}
						else
							getch();
					}
				}
				else
					{
						gotoxy(30,8);
						printf("Cliente nao cadastrado!");
						getch();				
					}
			}
			else
				getch();
				
			Interface();
			gotoxy(30,3);
			printf("### Alteracao de Clientes ###");
			gotoxy(30,7);
			printf("CPF [ENTER para sair]: ");
			fflush(stdin);
			gets(ClienteA.CPF);
			
		}
		fclose(PtrCli);
		OrdCliente();
		OrdLoc();
	}
}

void AlteracaoLocacao()
{
	TpLocacao Locacao;
	int pos;
	float precoDiaria;
	Interface();
	gotoxy(30,3);
	printf("### Alteracao de Locacoes ###");
	if(SemRegistroLoc())
	{
		gotoxy(30,7);
		printf("Nenhuma locacao cadastrada!");
		getch();
	}
	else
	{
		FILE *PtrLoc = fopen("locacoes.dat", "rb+");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Locacao.CPF);
		while(strcmp(Locacao.CPF, "\0")!=0)
		{
			if(VerifCPF(Locacao.CPF, 30, 8))
			{
				gotoxy(30,8);
				printf("Codigo do Carro: ");
				scanf("%d", &Locacao.CodCar);
				pos = BuscaLocacaoExaust(Locacao.CPF, Locacao.CodCar, PtrLoc);
				if(pos!=-1)
				{
					fseek(PtrLoc, pos, 0);
					fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
					precoDiaria = Locacao.ValorLocacao/Locacao.QtdeDias;
					gotoxy(30, 10);
					printf("### Dados da Locacao ###");
					gotoxy(30, 12);
					printf("CPF: %s", Locacao.CPF); 
					gotoxy(30, 13);
					printf("CODIGO CARRO: %d", Locacao.CodCar);
					gotoxy(30,14);
		            printf("QTDE DIAS: %d", Locacao.QtdeDias);
		            gotoxy(30,15);
		            printf("VALOR DA LOCACAO: %.2f", Locacao.ValorLocacao);
		            gotoxy(30,17);
		            printf("Deseja alterar (S/N)? ");
		            if(toupper(getche())=='S')
		            {
		            	gotoxy(30,17);
		            	printf("                               ");
						gotoxy(30, 10);
						printf("                               ");
						gotoxy(30, 10);
						printf("### Novos Dados da Locacao ###");
						gotoxy(41, 14);
						printf("       ");
						gotoxy(41, 14);
						scanf("%d", &Locacao.QtdeDias);
						gotoxy(48,15);
						printf("         ");
						gotoxy(48,15);
						Locacao.ValorLocacao = Locacao.QtdeDias*precoDiaria;
						printf("%.2f", Locacao.ValorLocacao);
						fseek(PtrLoc, pos, 0);
						fwrite(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
						gotoxy(30,17);
						printf("Locacao Alterada com Sucesso!");
						
		            }
				}
				else
					{
						gotoxy(30,9);
						printf("Locacao nao encontrada!");
					}
					
			}
			getch();
			Interface();
			gotoxy(30,3);
			printf("### Alteracao de Locacoes ###");
			gotoxy(30,7);
			printf("CPF [ENTER para sair]: ");
			fflush(stdin);
			gets(Locacao.CPF);
		}
		fclose(PtrLoc);
	}
}

void AlteracaoCarLoc(TpCarro CarroA, TpCarro CarroB)
{
	FILE *PtrLoc = fopen("locacoes.dat", "rb+");
	TpLocacao Locacao;
	int i=0;
	
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc))
	{
		if(Locacao.CodCar == CarroA.CodCar && Locacao.Status == 1)
		{
			Locacao.CodCar = CarroB.CodCar;
			Locacao.ValorLocacao=CarroB.PrecoDiaria*Locacao.QtdeDias;
			fseek(PtrLoc, i*sizeof(TpLocacao), 0);
			fwrite(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
		}
		i++;
		fseek(PtrLoc, i*sizeof(TpLocacao), 0);
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	}
	
	fclose(PtrLoc);
}

void AlteracaoCarro()
{
	
	TpCarro CarroA, CarroB;
	int pos, pos2;
	Interface();
	gotoxy(30,3);
	printf("### Alteracao de Carros ###");
	if(SemRegistroCar())
	{
		gotoxy(30,7);
		printf("Nenhum carro cadastrado!");
		getch();
	}
	else
	{
		FILE *PtrCar = fopen("carros.dat", "rb+");
		gotoxy(30,7);
		printf("Codigo do Carro [0 para sair]: ");
		scanf("%d", &CarroA.CodCar);
		while(CarroA.CodCar>0)
		{
			pos = BuscaCarroSentinela(CarroA.CodCar, PtrCar);
			if(pos!=-1)
			{
				fseek(PtrCar, pos, 0);
				fread(&CarroA, sizeof(TpCarro), 1, PtrCar);
				gotoxy(30, 9);
				printf("### Dados do Carro ###");
				gotoxy(30, 11);
				printf("CODIGO DO CARRO: %d", CarroA.CodCar); 
				gotoxy(30, 12);
				printf("MODELO: %s", CarroA.Modelo);
				gotoxy(30,13);
	            printf("CATEGORIA: %s", CarroA.Categoria);
	            gotoxy(30,14);
	            printf("PRECO DIARIA: %.2f", CarroA.PrecoDiaria);
	            gotoxy(30,16);
	            printf("Deseja alterar (S/N)? ");
	            if(toupper(getche())=='S')
	            {
	            	gotoxy(30,16);
	            	printf("                               ");
					gotoxy(30, 9);
					printf("                               ");
					gotoxy(30, 9);
					printf("### Novos Dados do Carro ###");
					gotoxy(47, 11);
					printf("        ");
					gotoxy(47, 11);
					scanf("%d", &CarroB.CodCar);
	
					pos2 = BuscaCarroSentinela(CarroB.CodCar, PtrCar);
					if(pos2!=-1 && pos!=pos2)
					{
						gotoxy(30,12);
						printf("Codigo do carro ja cadastrado!");
						getch();
					}
					else
						{
							gotoxy(38, 12);
							printf("                            ");
							gotoxy(38, 12);
							gets(CarroB.Modelo);
							VerifString(CarroB.Modelo,38, 12);
							gotoxy(41, 13);
							printf("                            ");
							gotoxy(41, 13);
							gets(CarroB.Categoria);
							VerifString(CarroB.Categoria,41, 13);
							gotoxy(44, 14);
							printf("             ");
							gotoxy(44, 14);
							scanf("%f", &CarroB.PrecoDiaria);
							CarroB.Status = 1;
							fseek(PtrCar, pos, 0);
							fwrite(&CarroB, sizeof(TpCarro), 1, PtrCar);
							AlteracaoCarLoc(CarroA, CarroB);
							gotoxy(30,15);
							printf("Carro Alterado com Sucesso!");
							getch();
						}
	
				}
			}
			else
				{
					gotoxy(30,8);
					printf("Carro nao cadastrado!");
					getch();				
				}
	
				
			Interface();
			gotoxy(30,3);
			printf("### Alteracao de Carros ###");
			gotoxy(30,7);
			printf("Codigo do Carro [0 para sair]: ");
			scanf("%d", &CarroA.CodCar);
			
		}
		fclose(PtrCar);
		OrdCarrosCod();
	}
}

void TabClientes()
{
	int i;
    TpCliente Cliente;
    FILE *PtrClientes = fopen("clientes.dat","rb");
	Interface();
    gotoxy(30,3);
	printf("### Tabela Clientes ###");
	gotoxy(20,7);
	printf("CPF*");
	gotoxy(40, 7);
	printf("Nome");
	gotoxy(55, 7);
	printf("Telefone");

	if(SemRegistroCli())
	{
		gotoxy(25, 9);
		printf("Nenhum cliente cadastrado!");
	}
	else
	{
		rewind(PtrClientes);
		fread(&Cliente, sizeof(TpCliente),1,PtrClientes);
    	i=9;
        while (!feof(PtrClientes))
        {	
        	if(Cliente.Status == 1)
        	{
        		if(i>=24)
        		{
        			gotoxy(30,24);
					printf("[ENTER] Avancar");
					getch();
					Interface();
				    gotoxy(30,3);
					printf("### Tabela Clientes ###");
					gotoxy(20,7);
					printf("CPF*");
					gotoxy(40, 7);
					printf("Nome");
					gotoxy(55, 7);
					printf("Telefone");
					i=9;
        		}
        		gotoxy(20, i);
	            printf("%s", Cliente.CPF); 
				gotoxy(40, i);
	            printf("%s", Cliente.Nome); 
				gotoxy(55, i);
	            printf("%s", Cliente.Telefone); 
	            i++;
        	}
            fread(&Cliente, sizeof(TpCliente),1,PtrClientes);
            
        }
        
	}	
	fclose(PtrClientes);
    getch();
}

void TabCarros()
{
	int i;
    TpCarro Carro;
    FILE *PtrCarros = fopen("carros.dat","rb");
	Interface();
    gotoxy(30,3);
	printf("### Tabela Carros ###");
	gotoxy(20,7);
	printf("CodCar*");
	gotoxy(30, 7);
	printf("Modelo");
	gotoxy(45, 7);
	printf("Categoria");
	gotoxy(60, 7);
	printf("PrecoDiaria");

	if(0)
	{
		gotoxy(25, 9);
		printf("Nenhum carro cadastrado!");
	}
	else
	{
		rewind(PtrCarros);
    	fread(&Carro, sizeof(TpCarro),1,PtrCarros);
    	i=9;
        while (!feof(PtrCarros))
        {	
        	//if(Carro.Status == 1)
        	//{
        		if(i>=24)
        		{
        			gotoxy(30,24);
					printf("[ENTER] Avancar");
					getch();
					Interface();
				    gotoxy(30,3);
					printf("### Tabela Carros ###");
					gotoxy(20,7);
					printf("CodCar*");
					gotoxy(30, 7);
					printf("Modelo");
					gotoxy(45, 7);
					printf("Categoria");
					gotoxy(60, 7);
					printf("PrecoDiaria");
					i=9;
        		}
        		gotoxy(20, i);
	            printf("%d", Carro.CodCar); 
				gotoxy(30, i);
	            printf("%s", Carro.Modelo); 
				gotoxy(45, i);
	            printf("%s", Carro.Categoria); 
	            gotoxy(60, i);
	            printf("%.2f",Carro.PrecoDiaria);
	            i++;
        	//}
			fread(&Carro, sizeof(TpCarro),1,PtrCarros);
        }
        
    }
	fclose(PtrCarros);
    getch();
}

void TabLocacoes()
{
	int i;
    TpLocacao Locacao;
    FILE *PtrLocacoes = fopen("locacoes.dat","rb");
	Interface();
    gotoxy(30,3);
	printf("### Tabela Locacoes ###");
	gotoxy(20,7);
	printf("CPF*");
	gotoxy(40, 7);
	printf("CodCar*");
	gotoxy(50, 7);
	printf("QtdeDias");
	gotoxy(60, 7);
	printf("ValorLocacao");

	if(SemRegistroLoc())
	{
		gotoxy(25, 9);
		printf("Nenhuma locacao cadastrada!");
	}
	else
	{
		rewind(PtrLocacoes);
    	fread(&Locacao, sizeof(TpLocacao),1,PtrLocacoes);
    	i=9;
        while (!feof(PtrLocacoes))
        {	
        	if(Locacao.Status == 1)
        	{
        		if(i>=24)
        		{
        			gotoxy(30,24);
					printf("[ENTER] Avancar");
					getch();
					Interface();
				    gotoxy(30,3);
					printf("### Tabela Locacoes ###");
					gotoxy(20,7);
					printf("CPF*");
					gotoxy(40, 7);
					printf("CodCar*");
					gotoxy(50, 7);
					printf("QtdeDias");
					gotoxy(60, 7);
					printf("ValorLocacao");
					i=9;
        		}
        		gotoxy(20, i);
	            printf("%s", Locacao.CPF); 
				gotoxy(40, i);
	            printf("%d", Locacao.CodCar); 
				gotoxy(50, i);
	            printf("%d", Locacao.QtdeDias); 
	            gotoxy(60, i);
	            printf("%.2f",Locacao.ValorLocacao);
	            i++;
        	}
        	fread(&Locacao, sizeof(TpLocacao),1,PtrLocacoes);
            
        }
        
    }
	fclose(PtrLocacoes);
    getch();
}

void CriarArquivos()
{
	FILE *PtrArq;
	
	PtrArq = fopen("clientes.dat", "ab");
	fclose(PtrArq);
	
	PtrArq = fopen("carros.dat", "ab");
	fclose(PtrArq);
	
	PtrArq = fopen("locacoes.dat", "ab");
	fclose(PtrArq);
}

void RelCli3loc()
{
	FILE *PtrLoc = fopen("locacoes.dat", "rb");
	TpLocacao Locacao, Aux;
	int flag, linha, pos, cont;
	Interface();
	gotoxy(30,3);
	printf("### Clientes com +3 Locacoes ###");
	linha=7;
	flag=1;
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	Aux = Locacao;
	while(!feof(PtrLoc))
	{
		cont=0;
		while(!feof(PtrLoc) && strcmp(Locacao.CPF, Aux.CPF)==0)
		{
			if(Locacao.Status==1)
				cont++;
			fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
		}
			
		if(cont>=3)
		{
			TpCliente Cliente;
			FILE *PtrCli = fopen("clientes.dat", "rb");
			pos=BuscaClienteSeqIndex(Aux.CPF, PtrCli);
			fseek(PtrCli, pos, 0);
			fread(&Cliente, sizeof(TpCliente), 1, PtrCli);
			fclose(PtrCli);
			gotoxy(15, linha);
			printf("NOME: %s", Cliente.Nome);
			gotoxy(35, linha);
			printf("CPF: %s", Cliente.CPF);
			gotoxy(60, linha);
			printf("Locacoes: %d", cont);
			flag=0;
			linha+=2;
			if(linha>=24)
			{
				gotoxy(30,24);
				printf("[ENTER] Avancar");
				getch();
				Interface();
				gotoxy(30,3);
				printf("### Clientes com +3 Locacoes ###");
				linha=7;
			}
			
		}
		Aux = Locacao;
	}
	if(flag==1)
	{
		gotoxy(30,7);
		printf("Nenhum cliente com +3 locacoes encontrado!");
	}
	getch();
	fclose(PtrLoc);
	
}

void RelLocLim(void)
{
	FILE *PtrArq = fopen("Locacoes.dat", "rb");rewind(PtrArq);
	float limite;
	int i=7, cont=0;
	TpLocacao RL;
	
	Interface();
	gotoxy(23,3);
	printf("### Locacoes + caras que limite ###");
	gotoxy(21,5);
	printf("Digite o limite que deseja pesquisar: ");
	scanf("%f", &limite);
	while(limite<0)
	{
		gotoxy(21,5);
		printf("                                          ");
		gotoxy(21,5);
		printf("Limite invalido, digite novamente: ");
		scanf("%f", &limite);
	}
	gotoxy(21,5);
	printf("                                             ");	
	fread(&RL, sizeof(TpLocacao),1 , PtrArq);
	while(!feof(PtrArq))
	{
		gotoxy(25,5);
		printf("Locacoes mais caras que %.2f", limite);
		if(RL.ValorLocacao > limite && (RL.Status>0 && RL.Status<2))
		{
			gotoxy(3,i);
			printf("CPF: %s\tCodCar: %d\tQDias: %d\tValor: %.2f\n", RL.CPF, RL.CodCar, RL.QtdeDias, RL.ValorLocacao);
			cont++;
			i+=2;
			if(i>=24)
			{
				gotoxy(30,24);
				printf("[ENTER] Avancar");
				getch();
				Interface();
				gotoxy(23,3);
				printf("### Locacoes + caras que limite ###");
				gotoxy(25,5);
				printf("Locacoes mais caras que %.2f", limite);
				i=7;
			}
		}
		fread(&RL, sizeof(TpLocacao),1 , PtrArq);
	}
	if(cont==0)
	{
		gotoxy(21,5);
		printf("                                           ");
		gotoxy(21,5);
		printf("Nenhuma locacao encontrada com mais que limite!\n");
	}
	getch();
	fclose(PtrArq);
}

void RelCarCateg()
{
	FILE *PtrCar = fopen("carros.dat", "rb");
	TpCarro Carro, Aux;
	int flag, linha;
	flag=1;
	Interface();
	gotoxy(30,3);
	printf("### Carro da Categoria ###");
	gotoxy(30,7);
	printf("Digite a categoria: ");
	fflush(stdin);
	gets(Aux.Categoria);
	Interface();
	gotoxy(30,3);
	printf("### Carro da Categoria: %s ###", Aux.Categoria);
	linha=7;
	fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	while(!feof(PtrCar))
	{
		if(stricmp(Aux.Categoria,Carro.Categoria)==0 && Carro.Status==1)
		{
			gotoxy(20, linha);
			printf("MODELO: %s", Carro.Modelo);
			gotoxy(40, linha);
			printf("CODIGO:%d", Carro.CodCar);
			gotoxy(60, linha);
			printf("CATEGORIA:%s", Carro.Categoria);
			flag=0;
			linha+=2;
			if(linha>=24)
			{
				gotoxy(30,24);
				printf("[ENTER] Avancar");
				getch();
				Interface();
				gotoxy(30,3);
				printf("### Carro da Categoria: %s ###", Aux.Categoria);
				linha=7;
			}
		}
		fread(&Carro, sizeof(TpCarro), 1, PtrCar);
	}
	if(flag==1)
	{
		gotoxy(30,7);
		printf("Nenhum carro com essa categoria encontrado!");
	}
	
	getch();
	fclose(PtrCar);
	
}

int BuscaLocBinaria(char CPF[], FILE *PtrBusca)
{
	TpLocacao LocacaoM;
	int pos,i,f,m,num=0;
	
	i = 0;
	
	fseek(PtrBusca, 0, 2);
	f = ftell(PtrBusca)/sizeof(TpLocacao)-1;
	
	m = f/2;
	
	fseek(PtrBusca,m*sizeof(TpLocacao),0);
	fread(&LocacaoM,sizeof(TpLocacao),1,PtrBusca);
	while(i<f && (strcmp(CPF, LocacaoM.CPF)!=0 || LocacaoM.Status != 1))
	{
		if(strcmp(CPF, LocacaoM.CPF)>0)
		{
			i=m+1;
		}
		else
			{
				f=m-1;
		}
		m=(i+f)/2;
		fseek(PtrBusca,m*sizeof(TpLocacao),0);
		fread(&LocacaoM,sizeof(TpLocacao),1,PtrBusca);
	}
	
	if(strcmp(LocacaoM.CPF,CPF)==0 && LocacaoM.Status == 1)
		return m*sizeof(TpLocacao);
	else
		return -1;
}

void RelLocCPF()
{
	TpLocacao Locacao,Busca;
	FILE *PtrLoc = fopen("locacoes.dat","rb");
	int pos,i,TL,pos2;
	Interface();
	gotoxy(25,3);
	printf("### Busca de Locacoes pelo CPF ###");
	gotoxy(30,7);
	printf("CPF [ENTER para sair]: ");
	fflush(stdin);
	gets(Locacao.CPF);
	while(Locacao.CPF[0] != '\0')
	{
		if(VerifCPF(Locacao.CPF, 30, 8))
		{
			FILE *PtrCli = fopen("clientes.dat", "rb");
			pos = BuscaClienteSeqIndex(Locacao.CPF, PtrCli);
			fclose(PtrCli);
			if(pos!=-1)
			{
				i=7;
				pos = BuscaLocBinaria(Locacao.CPF,PtrLoc);
				if(pos==-1)
					{
						gotoxy(30,9);
						printf("Locacao nao encontrada");
					}
					else
					{
						gotoxy(30,7);
						printf("                                      ");
						pos2 = pos/sizeof(TpLocacao);
						fseek(PtrLoc,pos2*sizeof(TpLocacao),0);
						fread(&Busca,sizeof(TpLocacao),1,PtrLoc);
						fseek(PtrLoc,0,2);
						TL = ftell(PtrLoc)/sizeof(TpLocacao);
						while(pos2>=0 && strcmp(Busca.CPF,Locacao.CPF)==0)
						{
							if(Busca.Status==1)
							{
								gotoxy(5, i);
								printf("CPF: %s",Busca.CPF);
								gotoxy(30,i);
								printf("CODIGO: %d",Busca.CodCar);
								gotoxy(45,i);
								printf("DIAS: %d", Busca.QtdeDias);
								gotoxy(60, i);
								printf("VALOR: %.2f",Busca.ValorLocacao);
								i++;
							}
							pos2--;
							if (pos2 >= 0) 
							{
							    fseek(PtrLoc, pos2*sizeof(TpLocacao), SEEK_SET);
							    fread(&Busca,sizeof(TpLocacao),1,PtrLoc);
							}
							if(i>=24)
							{
								gotoxy(30,24);
								printf("[ENTER] Avancar");
								getch();
								Interface();
								gotoxy(25,3);
								printf("### Busca de Locacoes pelo CPF ###");
								i=7;
							}
						}
						pos2 = pos/sizeof(TpLocacao);
						pos2++;
						fseek(PtrLoc,pos2*sizeof(TpLocacao),0);
						fread(&Busca,sizeof(TpLocacao),1,PtrLoc);
						while(pos2<TL && strcmp(Busca.CPF,Locacao.CPF)==0)
						{
							if(Busca.Status==1)
							{
								gotoxy(5, i);
								printf("CPF: %s",Busca.CPF);
								gotoxy(30,i);
								printf("CODIGO: %d",Busca.CodCar);
								gotoxy(45,i);
								printf("DIAS: %d", Busca.QtdeDias);
								gotoxy(60, i);
								printf("VALOR: %.2f",Busca.ValorLocacao);
								i++;
							}
							pos2++;
							if(pos2<TL)
							{
								fseek(PtrLoc,pos2*sizeof(TpLocacao),0);
								fread(&Busca,sizeof(TpLocacao),1,PtrLoc);
								if(i>=24)
								{
									gotoxy(30,24);
									printf("[ENTER] Avancar");
									getch();
									Interface();
									gotoxy(25,3);
									printf("### Busca de Locacoes pelo CPF ###");
									i=7;
								}
							}
						}
					}	
			}
			else
				{
					gotoxy(30,8);
					printf("Cliente nao Cadastrado!");				
				}
		}
		getch();
		Interface();
		gotoxy(25,3);
		printf("### Busca de Locacoes pelo CPF ###");
		gotoxy(30,7);
		printf("CPF [ENTER para sair]: ");
		fflush(stdin);
		gets(Locacao.CPF);
	}
	fclose(PtrLoc);
}


int BuscaCPFLoc(char CPF[], FILE *PtrLoc)
{
	TpLocacao Locacao;
	rewind(PtrLoc);
	fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	while(!feof(PtrLoc) && (strcmp(CPF, Locacao.CPF)!=0 || Locacao.Status!=1))
		fread(&Locacao, sizeof(TpLocacao), 1, PtrLoc);
	
	if(!feof(PtrLoc))
		return ftell(PtrLoc) - sizeof(TpLocacao);
	return -1;
}

void RelCompleto()
{
	FILE *PtrCli = fopen("clientes.dat", "rb");
	FILE *PtrLoc = fopen("locacoes.dat", "rb");
	TpCliente Cliente;
	TpLocacao Locacao;
	TpCarro Carro;
	int flag=1, linha=6, pos, i=0;
	fread(&Cliente, sizeof(TpCliente), 1, PtrCli);
	Interface();
	gotoxy(30,3);
	printf("### Relatorio Completo ###");
	while(!feof(PtrCli))
	{
		pos = BuscaCPFLoc(Cliente.CPF, PtrLoc);
		i=pos/sizeof(TpLocacao);
		if(pos!=-1)
		{
			flag=0;
			gotoxy(10,linha);
			printf("CPF: %s", Cliente.CPF);
			gotoxy(35,linha);
			printf("NOME: %s", &Cliente.Nome);
			linha++;
			if(linha>=24)
			{
				gotoxy(30,24);
				printf("[ENTER] Avancar");
				getch();
				Interface();
				gotoxy(30,3);
				printf("### Relatorio Completo ###");
				linha=6;
			}
			fseek(PtrLoc, pos, 0);
			fread(&Locacao, sizeof(TpLocacao), 1,PtrLoc);
			while(!feof(PtrLoc) && strcmp(Locacao.CPF, Cliente.CPF)==0)
			{
				if(Locacao.Status==1)
				{
					gotoxy(10, linha);
					printf("%d", Locacao.CodCar);
					FILE *PtrCar = fopen("carros.dat", "rb");
					pos = BuscaCarroBinaria(Locacao.CodCar, PtrCar);
					fseek(PtrCar, pos, 0);
					fread(&Carro, sizeof(TpCarro), 1, PtrCar);
					fclose(PtrCar);
					gotoxy(25, linha);
					printf("%s", Carro.Modelo);
					gotoxy(37, linha);
					printf("%s", Carro.Categoria);
					gotoxy(50, linha);
					printf("%d dia(s)", Locacao.QtdeDias);
					gotoxy(65, linha);
					printf("R$%.2f", Locacao.ValorLocacao);
					linha++;
					if(linha>=24)
					{
						gotoxy(30,24);
						printf("[ENTER] Avancar");
						getch();
						Interface();
						gotoxy(30,3);
						printf("### Relatorio Completo ###");
						linha=6;
					}
				}
				i++;
				fread(&Locacao, sizeof(TpLocacao), 1,PtrLoc);
			}
			fseek(PtrLoc, (i-1)*sizeof(TpLocacao),0);
			linha++;
			if(linha>=24)
			{
				gotoxy(30,24);
				printf("[ENTER] Avancar");
				getch();
				Interface();
				gotoxy(30,3);
				printf("### Relatorio Completo ###");
				linha=6;
			}
				
		}
		fread(&Cliente, sizeof(TpCliente), 1, PtrCli);
	}
	fclose(PtrCli);
	fclose(PtrLoc);
	if(flag==1)
	{
		gotoxy(30,6);
		printf("Nenhum cliente com locacao encontrado!");
	}
	getch();
}

int main () 
{
	char op, op2, op3, op4;
	
	
	CriarArquivos();
	do
	{
		op = MenuGeral();
		switch(op)
		{
			case 'A': 	do
						{
							op2 = MenuManutencao();
							switch(op2)
							{
								case 'A': 	do 
											{
												Interface();
												gotoxy(30,3);
												printf("### Cadastrar ###");
												op3 = MenuCCL();
												switch(op3)
												{
													case 'A':	CadastroCliente();
																break;
																
													case 'B':	CadastroCarro();
																break;
													case 'C':	CadastroLocacao();
												}
											} while (op3 != 27);
											break;
											
								case 'B': 	do
											{
												Interface();
												gotoxy(30,3);
												printf("### Excluir ###");
												op3 = MenuCCL();
												switch(op3)
												{
													case 'A':	ExclusaoCliente();
																break;
													case 'B':	ExclusaoCarro();
																break;
													case 'C':	ExclusaoLocacao();
												}
												
											}while (op3 != 27);
											break;
											
								case 'C': 	do 
											{
												Interface();
												gotoxy(30,3);
												printf("### Alterar ###");
												op3 = MenuCCL();
												switch(op3)
												{
													case 'A':	AlteracaoCliente();
																break;
													case 'B':	AlteracaoCarro();
																break;
													case 'C':;	AlteracaoLocacao();
												}
											}while(op3 != 27);
											break;
											
								case 'D': 	do
											{
												Interface();
												gotoxy(30,3);
												printf("### Listar ###");
												op3 = MenuCCL();
												switch(op3)
												{
													case 'A':	TabClientes();
																break;
													case 'B':	do
																{
																	op4 = MenuCarro();
																	switch(op4)
																	{
																		case 'A': 	OrdCarrosCod();
																					TabCarros();
																					break;
																		case 'B': 	OrdCarrosMod();
																					TabCarros();
																					OrdCarrosCod();
																	}
																}while(op4 != 27);
																break;
													case 'C':	TabLocacoes();
												}
											}while(op3 != 27);
											
								
							}
						} while(op2 != 27);
						break;
						
						
			case 'B': 	do
						{
							op2 = MenuRelatorio();
							switch(op2)
							{
								case 'A':	RelCli3loc();
											break;
								case 'B':	RelCarCateg();
											break;
								case 'C':	RelLocLim();
											break;
								case 'D':	RelLocCPF();
											break;
								case 'E':	RelCompleto();
											clrscr();
											break;
	
							}
						} while(op2 != 27);
						
		}
	}while(op != 27);
	ExclusaoFisica();
	return 0;
	
}
