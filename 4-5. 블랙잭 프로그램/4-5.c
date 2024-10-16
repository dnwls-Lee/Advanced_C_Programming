#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int Cur_CardNum = 0; // 최근까지 나누어준 카드의 순서
int Cur_PlayerNum = 0; // 플레이어가 최근까지 받은 카드 개수
int Cur_DealerNum = 0; // 딜러가 최근까지 받은 카드 개수
int Result_Player = 0; // 플레이어의 카드 합 결과
int Result_Dealer = 0; // 딜러의 카드 합 결과

void Shuffle(char** Initial_Cards); // 카드 20장을 랜덤으로 생성하는 함수
void Initialization(char** Initial_Cards, char** Player_Card, char** Dealer_Card); // 플레이어와 딜러에게 최초로 2장씩 나누어주는 함수
void Status(char** Player_Card, char** Dealer_Card); // 플레이어와 딜러의 현재 카드 상황을 알려주는 함수
void Hit(char** Player_Card, char** Dealer_Card, char** Initial_Cards); // 플레이어가 카드를 1장 더 받는 함수
void End(char** Player_Card, char** Dealer_Card, char** Initial_Cards); // 딜러가 카드를 받는 함수
int Result(char** Player_Card, char** Dealer_Card, char** Initial_Cards); // 게임의 결과를 판단하는 함수
void Free_Cards(char** Player_Card, char** Dealer_Card, char** Initial_Cards); // 게임이 끝나고 모든 배열 초기화하는 함수

int main() {
	char* Initial_Cards = NULL; // 카드 20장을 받는 배열 
	char* Player_Card = NULL; // 플레이어 카드를 저장하는 배열
	char* Dealer_Card = NULL; // 딜러 카드를 저장하는 배열
	char Start_Game[10]; // 게임 시작 여부 확인하는 문자열
	char Choose_Game[10]; // 게임 내에서 Hit or Stay 입력 확인받는 문자열
	int Result_Game; // 게임 결과 확인 받는 변수
	srand(time(NULL));

	while (1) {
		Sleep(5000);
		system("cls");
		printf("Game Start? : ");
		gets(Start_Game);
		if (strcmp(Start_Game, "Start") == 0) {
			Shuffle(&Initial_Cards);
			Initialization(&Initial_Cards, &Player_Card, &Dealer_Card);
			Status(&Player_Card, &Dealer_Card);
			while (1) {
				printf("More Card? : ");
				gets(Choose_Game);
				if (strcmp(Choose_Game, "Hit") == 0) {
					Hit(&Player_Card, &Dealer_Card, &Initial_Cards);
					Status(&Player_Card, &Dealer_Card);
					Result_Game = Result(&Player_Card, &Dealer_Card, &Initial_Cards);
					if (Result_Game == 2) {
						printf("Busted! Over 21! Dealer Wins.\n"); // 플레이어가 21을 넘겼을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
					else if (Result_Game == 1) {
						printf("BlackJack! Winner Winner Chicken Dinner! User Win!\n"); // 플레이어가 21을 맞췄을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
				}
				else if (strcmp(Choose_Game, "Stay") == 0) {
					End(&Player_Card, &Dealer_Card, &Initial_Cards);
					Status(&Player_Card, &Dealer_Card);
					while(Result_Dealer < 16) {
						End(&Player_Card, &Dealer_Card, &Initial_Cards);
						Status(&Player_Card, &Dealer_Card);
					}
					Result_Game = Result(&Player_Card, &Dealer_Card, &Initial_Cards);
					if (Result_Game == -1) {
						printf("User Wins! Dealer Busted!\n"); // 딜러가 21을 넘겼을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
					else if (Result_Game == -2) {
						printf("Dealer BlackJack. Dealer Wins.\n"); // 딜러가 21을 맞췄을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
					else if (Result_Game == 3) {
						printf("User Wins! Congratulation!\n"); // 딜러의 숫자보다 플레이어의 숫자가 더 높을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
					else if (Result_Game == -3) {
						printf("Dealer Wins.\n"); // 딜러의 숫자가 플레이어의 숫자보다 더 높을 때
						Free_Cards(&Player_Card, &Dealer_Card, &Initial_Cards);
						break;
					}
					else {
						printf("Draw!\n");
						break;
					}
				}
				else {
					printf("Error : Wrong Input. Try again.\n");
				}
			}
		}
		else if (strcmp(Start_Game, "End") == 0) {
			break;
		}
		else
			printf("Error : Wrong Input. Try again.\n");
	}
}

void Shuffle(char** Initial_Cards) {
	int Card_Num, Card_Var;
	int Card_List[14] = { 0 };
	(*Initial_Cards) = (char*)malloc(sizeof(char) * 21);
	for (int i = 0; i < 20; i++) {
		Card_Num = (rand() % 10) + 1;
		if (Card_Num == 1) {
			(*Initial_Cards)[i] = 'A';
			Card_List[Card_Num]++;
		}
		else if (Card_Num >= 2 && Card_Num <= 9) {
			(*Initial_Cards)[i] = Card_Num + 48;
			Card_List[Card_Num]++;
		}
		else {
			Card_Var = (rand() % 4) + 1;
			if (Card_Var == 1) {
				(*Initial_Cards)[i] = '0';
				Card_List[9 + Card_Var]++;
			}
			else if (Card_Var == 2) {
				(*Initial_Cards)[i] = 'J';
				Card_List[9 + Card_Var]++;
			}
			else if (Card_Var == 3) {
				(*Initial_Cards)[i] = 'Q';
				Card_List[9 + Card_Var]++;
			}
			else {
				(*Initial_Cards)[i] = 'K';
				Card_List[9 + Card_Var]++;
			}
		}
		for (int j = 0; j < 14; j++) {
			if (Card_List[j] > 4) {
				Card_List[j]--;
				i--;
			}
		}
	}
}

void Initialization(char** Initial_Cards, char** Player_Card, char** Dealer_Card) {
	(*Player_Card) = (char*)malloc(sizeof(char) * 3);
	(*Dealer_Card) = (char*)malloc(sizeof(char) * 3);

	memset((*Player_Card), '\0', sizeof(char) * 3);
	memset((*Dealer_Card), '\0', sizeof(char) * 3);

		for (Cur_PlayerNum; Cur_PlayerNum < 2; Cur_PlayerNum++) {
			(*Player_Card)[Cur_PlayerNum] = (*Initial_Cards)[Cur_CardNum];
			if ((*Player_Card)[Cur_PlayerNum] == 'A')
				Result_Player += 1;
			else if ((*Player_Card)[Cur_PlayerNum] >= '2' && (*Player_Card)[Cur_PlayerNum] <= '9')
				Result_Player += (*Player_Card)[Cur_PlayerNum] - 48;
			else
				Result_Player += 10;
			Cur_CardNum++;
		}
		for (Cur_DealerNum; Cur_DealerNum < 2; Cur_DealerNum++) {
			(*Dealer_Card)[Cur_DealerNum] = (*Initial_Cards)[Cur_CardNum];
			if ((*Dealer_Card)[Cur_DealerNum] == 'A')
				Result_Dealer += 1;
			else if ((*Dealer_Card)[Cur_DealerNum] >= '2' && (*Dealer_Card)[Cur_DealerNum] <= '9')
				Result_Dealer += (*Dealer_Card)[Cur_DealerNum] - 48;
			else
				Result_Dealer += 10;
			Cur_CardNum++;
		}
}

void Status(char** Player_Card, char** Dealer_Card) {
	printf("Dealer : ");
	for (int i = 0; (*Dealer_Card)[i] != '\0'; i++) {
		if ((*Dealer_Card)[i + 1] != '\0') {
			if ((*Dealer_Card)[i] == '0')
				printf("10, ");
			else
				printf("%c, ", (*Dealer_Card)[i]);
		}
		else {
			if ((*Dealer_Card)[i] == '0')
				printf("10\n");
			else
				printf("%c\n", (*Dealer_Card)[i]);
		}
	}
	printf("User : ");
	for (int i = 0; (*Player_Card)[i] !=  '\0'; i++) {
		if ((*Player_Card)[i + 1] != '\0') {
			if ((*Player_Card)[i] == '0')
				printf("10, ");
			else
				printf("%c, ", (*Player_Card)[i]);
		}
		else {
			if ((*Player_Card)[i] == '0')
				printf("10\n");
			else
				printf("%c\n", (*Player_Card)[i]);
		}
	}
}

void Hit(char** Player_Card, char** Dealer_Card, char** Initial_Cards) {
	(*Player_Card) = realloc((*Player_Card), sizeof(char) * (Cur_PlayerNum + 2));
	(*Player_Card)[Cur_PlayerNum++] = (*Initial_Cards)[Cur_CardNum++];
	(*Player_Card)[Cur_PlayerNum] = '\0';
	if ((*Player_Card)[Cur_PlayerNum - 1] == 'A')
		Result_Player += 1;
	else if ((*Player_Card)[Cur_PlayerNum - 1] >= '2' && (*Player_Card)[Cur_PlayerNum - 1] <= '9')
		Result_Player += (*Player_Card)[Cur_PlayerNum - 1] - 48;
	else
		Result_Player += 10;
}

void End(char** Player_Card, char** Dealer_Card, char** Initial_Cards) {
	(*Dealer_Card) = realloc((*Dealer_Card), sizeof(char) * (Cur_DealerNum + 2));
	(*Dealer_Card)[Cur_DealerNum++] = (*Initial_Cards)[Cur_CardNum++];
	(*Dealer_Card)[Cur_DealerNum] = '\0';
	if ((*Dealer_Card)[Cur_DealerNum - 1] == 'A')
		Result_Dealer += 1;
	else if ((*Dealer_Card)[Cur_DealerNum - 1] >= '2' && (*Dealer_Card)[Cur_DealerNum - 1] <= '9')
		Result_Dealer += (*Dealer_Card)[Cur_DealerNum - 1] - 48;
	else
		Result_Dealer += 10;
}

int Result(char** Player_Card, char** Dealer_Card, char** Initial_Cards) {
	if (Result_Player > 21)
		return 2;
	else if (Result_Dealer > 21)
		return -1;
	else if (Result_Player == 21)
		return 1;
	else if (Result_Dealer == 21)
		return -2;
	else if (Result_Player > Result_Dealer)
		return 3;
	else if (Result_Player < Result_Dealer)
		return -3;
	else if (Result_Player == Result_Dealer)
		return 0;
}

void Free_Cards(char** Player_Card, char** Dealer_Card, char** Initial_Cards) {
	if ((*Player_Card) != NULL) {
		free((*Player_Card));
		(*Player_Card) = NULL;
	}
	if ((*Dealer_Card) != NULL) {
		free((*Dealer_Card));
		(*Dealer_Card) = NULL;
	}
	if ((*Initial_Cards) != NULL) {
		free((*Initial_Cards));
		(*Initial_Cards) = NULL;
	}
	Cur_CardNum = 0;
	Cur_PlayerNum = 0;
	Cur_DealerNum = 0;
	Result_Player = 0;
	Result_Dealer = 0;
}