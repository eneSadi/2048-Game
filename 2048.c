#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

//Oyunun bitip bitmedi�ini belirlemek i�in her indeksin etraf�ndakilerle ayn� olup olmad��� kontrol�n�n yap�ld��� int tipinde fonksiyon
int game_over (int board[4][4]){

	int i,j,over=0;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==board[i][j+1] || board[i][j]==board[i+1][j] || board[i][j]==0){
				over=1;
				return over;	
			}
		}
	}
	
	for(i=0,j=3;i<3;i++){
		if(board[i][j]==board[i+1][j] || board[i][j]==0){
			over=1;
			return over;		
		}
	}
	
	for(i=3,j=0;j<3;j++){
		if(board[i][j]==board[i][j+1] || board[i][j]==0 || board[3][3]==0){
			over=1;
			return over;		
		}
	}
	
	return over;
}


int main(){
	
	srand(time(NULL));
	
	int board[4][4],i,j,a,b,k,tmp,score,counter=0,counter2=0,highscore=0,x,y,sayone=0,previous[4][4];
	char operation='k';
	//goto'nun g�sterdi�i sat�r playAgain
	playAgain:
	
	printf("For moves, please use arrow keys\nRestarting: x\nEnd the game: e\nUndo: r\n\n");
	score=0;
	printf("\nCurrent Score: %d\nHighscore: %d\n",score,highscore);
	
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			board[i][j]=0;
		}
	} 	
	//iki yeni say�n�n atand��� ve tablonun ilk yazd�r�ld��� k�s�m
	board[i][j]=b;
	for(tmp=0;tmp<2;tmp++){
		i=rand()%4;
		j=rand()%4;
		while(board[i][j]!=0){
			i=rand()%4;
			j=rand()%4;
		}
		
		a=rand()%2;
		
		if(a==0)
			b=2;
		else
			b=4;
		board[i][j]=b;
	}
	
	for(i=0;i<4;i++){
		printf("|");
		for(j=0;j<4;j++){
			printf("%4.d |",board[i][j]);
		}
		printf("\n");
	} 
	printf("\n");
	
	
	while(operation!='e'){

		operation=getch();
		//r inputu durumunda yedek matrisi �u anki matrise atar ve bir �nceki hamleye d�nm�� olur
		if(operation=='r'){
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					board[i][j]=previous[i][j];
		    	}
	    	}	
		}
		
		system("cls");
		printf("The Previous State\n");
		printf("\nPrevious Score: %d\nHighscore: %d\n\n",score,highscore);
		
		//matris yedeklemesi
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				previous[i][j]=board[i][j];
			}
		}
		
		for(i=0;i<4;i++){
			printf("|");
			for(j=0;j<4;j++){
				printf("%4.d |",board[i][j]);	
			}
			printf("\n");
		} 
		printf("\n");	

		switch(operation){
			//sa�a kayd�rma i�leminin yap�ld��� case		
			case 77:					
				//toplama i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=3;j>0;j--){
						if(board[i][j]!=0){
							k=j;
							while(k>0){
								if(board[i][k-1]==board[i][j]){
									board[i][j]=board[i][k-1]+board[i][j];
									score=score+board[i][j];
									board[i][k-1]=0;
									counter++;
								}
								else if(board[i][k-1]!=board[i][j] && board[i][k-1]!=0){
									j=k-1;	
								}
								k--;
							}
						}
					}
				}
				
				//kayd�rma i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=3;j>=0;j--){
						if(board[i][j]!=0){
							for(k=j;k<3;k++){
								if(board[i][k+1]==0){
									tmp=board[i][k+1];
									board[i][k+1]=board[i][k];
									board[i][k]=tmp;
									counter++;
								}
							}				
						}
					}
				}	
				
				break;
			
			//sola kayd�rma i�leminin yap�ld��� case
			case 75:	

				//toplama i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=0;j<3;j++){
						if(board[i][j]!=0){
							k=j;
							while(k<3){
								if(board[i][k+1]==board[i][j]){
									board[i][k+1]=board[i][k+1]+board[i][j];
									score=score+board[i][k+1];
									board[i][j]=0;
									counter++;
								}
								else if(board[i][k+1]!=board[i][j] && board[i][k+1]!=0){
									j=k+1;
								}
								k++;	
							}
						}	
					}
				}
				
				//kayd�rma i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						if(board[i][j]!=0){
							for(k=j;k>0;k--){
								if(board[i][k-1]==0){
									tmp=board[i][k-1];
									board[i][k-1]=board[i][k];
									board[i][k]=tmp;
									counter++;
								}
							}					
						}
					}
				}								
		
				break;	
		
			//yukar�ya kayd�rma i�leminin yap�ld��� case
			case 72:		

				//toplama i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=0;j<3;j++){
						if(board[j][i]!=0){
							k=j;
							while(k<3){
								if(board[k+1][i]==board[j][i]){
									board[k+1][i]=board[k+1][i]+board[j][i];
									score=score+board[k+1][i];
									board[j][i]=0;
									counter++;
								}
								else if(board[k+1][i]!=board[j][i] && board[k+1][i]!=0){
									j=k+1;
								}
								k++;
							}
						}
					}
				}
				
				//kayd�rma i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						if(board[j][i]!=0){
							for(k=j;k>0;k--){
								if(board[k-1][i]==0){
									tmp=board[k-1][i];
									board[k-1][i]=board[k][i];
									board[k][i]=tmp;
									counter++;
								}
							}
						}
					}
				}	
	
				break;
		
			//a�a��ya kayd�rma i�leminin yap�ld��� case
			case 80:

				//toplama i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=3;j>0;j--){
						if(board[j][i]!=0){
							k=j;
							while(k>0){
								if(board[k-1][i]==board[j][i]){
									board[j][i]=board[k-1][i]+board[j][i];
									score=score+board[j][i];
									board[k-1][i]=0;
									counter++;
								}
								else if(board[k-1][i]!=board[j][i] && board[k-1][i]!=0){
									j=k-1;	
								}
								k--;
							}
						}
					}
				}
				
				//kayd�rma i�leminin yap�ld��� yer
				for(i=0;i<4;i++){
					for(j=3;j>=0;j--){
						if(board[j][i]!=0){
							for(k=j;k<3;k++){
								if(board[k+1][i]==0){
									tmp=board[k+1][i];
									board[k+1][i]=board[k][i];
									board[k][i]=tmp;
									counter++;
								}
							}			
						}
					}
				}	
		
				break;
			
			//x inputu durumunda goto komutuyla �st k�s�mda bahsedilen sat�ra gider
			case 'x':
				
				system("cls");

				goto playAgain;
		}

		if(score>=highscore){
			highscore=score;
		}
		
		//kayd�rma veya toplama i�lemi yap�ld���nda counter artar bu durumda yeni say� ekleme i�lemi yapar, counter ayn� ise yeni say� eklemez		
		if(counter>counter2){
	
			i=rand()%4;
			j=rand()%4;
	
			while(board[i][j]!=0){
				i=rand()%4;
				j=rand()%4;
			}
	
			a=rand()%2;
	
			if(a==0)
				b=2;
			else
				b=4;
	
			board[i][j]=b;
			x=i;y=j;
			counter2=counter;	
		}
		
		printf("----------------------------\nThe Current State\n");
		printf("\nCurrent Score: %d\nHighscore: %d\n",score,highscore);
	
		for(i=0;i<4;i++){
			printf("|");
			for(j=0;j<4;j++){					
				if(i==x && j==y){
					printf("%4.d",board[i][j]);
					if(operation=='r' || operation=='e'){
						printf(" ");
					}
					else{
						printf("*");
					}
					printf("|");
				}
				else{
					printf("%4.d |",board[i][j]);
				}
			}
			printf("\n");
		} 
		printf("\n");
		
		//2048'e ula��lma durumu kontrol edilir ve ula�t�ktan sonra yazd�r�r ve oyun devam eder
		if(sayone%2==0){
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(board[i][j]==2048){
						printf("Congratulations, you reached 2048!\nYou can continue...");
						sayone++;
					}
				}
			}
		}
	
		//�st k�s�mda bahsedilen fonksiyonu �a��rarak oyunun bitme durumunu kontrol eder
		if(game_over(board)!=1){
	
			printf("Game Over!");
	
			printf("\nInstant Score: %d\nHighscore: %d\n",score,highscore);
	
			printf("If you want to play again please press x!\nIf you want to end this game press e!\n\n");
	
			operation=getch();
		
			if(operation=='x')
				goto playAgain;
		}
				
	}
	printf("Thanks for playing!\n\ndeveloped by sadi\n");
	
	return 0;	
}
