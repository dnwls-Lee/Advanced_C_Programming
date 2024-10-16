#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int VIP_Room[3] = {0,};
int Normal_Room[5] = {0,};
int Reserved_Room[5];
int Remaining_Guest;

int VIP_Check(int People_Num) {
	int num = 0, Room_Num = 0;
	for (int i = 0; i < 4; i++) { // 현재 예약된 방 찾기
		if (VIP_Room[num] != 0) {
			num++;
		}
	}
	while (People_Num != 0 && num < 3) { // 손님을 방에 숙박시키기
		if (VIP_Room[num] == 4) {
			Reserved_Room[Room_Num++] = 300 + num + 1;
			num++;
		}
		else {
			VIP_Room[num]++;
			People_Num--;
		}
	}
	Remaining_Guest = People_Num;
	if (VIP_Room[num] != 0 && Remaining_Guest == 0) // 예약된 방 저장하기
		Reserved_Room[Room_Num++] = 300 + num + 1;
}

int Normal_Check(int People_Num) {
	int num = 0, Room_Num = 0;
	for (int i = 0; i < 4; i++) {
		if (Normal_Room[num] != 0) {
			num++;
		}
	}
	while (People_Num != 0 && num < 5) {
		if (Normal_Room[num] == 2) {
			Reserved_Room[Room_Num++] = 200 + num + 1;
			num++;
		}
		else {
			Normal_Room[num]++;
			People_Num--;
		}
	}
	Remaining_Guest = People_Num;
	if (Normal_Room[num] != 0 && Remaining_Guest == 0)
		Reserved_Room[Room_Num++] = 200 + num + 1;
}

int Reservation_hotel(char Room_Type[], int People_Num) {
	if (strcmp(Room_Type, "VIP") == 0) {
		if (VIP_Room[2] != 0) {
			return 0;
		}
		else {
			VIP_Check(People_Num);
			return 1;
		}
	}
	else if (strcmp(Room_Type, "NORMAL") == 0) {
		if (Normal_Room[4] != 0) {
			return 0;
		}
		else {
			Normal_Check(People_Num);
			return 1;
		}
	}
	else
		return -1;
}

int main() {
	char Room_Type[7];
	int People_Num, Result;

	for (int i = 0; i < 5; i++) {
		for (int i = 0; i < 5; i++) {
			Reserved_Room[i] = 0;
		}
		printf("예약할 방과 예약 인원을 적어주세요 : ");
		scanf("%s %d", Room_Type, &People_Num);

		Result = Reservation_hotel(Room_Type, People_Num);

		if (Result == 1) {
			int i = 0;
			printf("예약된 방 : ");
			while (Reserved_Room[i] != 0) {
				printf("%d ", Reserved_Room[i]);
				i++;
			}
			if (Remaining_Guest != 0)
				printf("| 예약하지 못한 손님 수 : %d", Remaining_Guest);
			printf("\n");
		}
		else if (Result == 0)
			printf("예약이 전부 꽉 찼습니다.\n");
		else
			printf("잘못된 객실 타입입니다.\n");
	}
}