#pragma warning(disable:4996)
#pragma warning(disable:6031)

#define sol 800
#define ciltea 900
#define ZICO 2800
#define maccol 800
#define achim 1200
#define dejawa 800
#define drpper 1200
#define mint 1500

#include <stdio.h>
#include <conio.h>

int pay(int* p);
void saveToFile(int money, int cnt)
{
	FILE* file = fopen("vending_machine.txt", "w");
	if (file == NULL)
	{
		printf("Failed to open file for writing.\n");
		return;
	}

	fprintf(file, "%d %d", money, cnt);

	fclose(file);
}

void loadFromFile(int* money, int* cnt)
{
	FILE* file = fopen("vending_machine.txt", "r");
	if (file == NULL)
	{
		printf("Failed to open file for reading.\n");
		return;
	}

	fscanf(file, "%d %d", &money, &cnt);

	fclose(file);
}

int p;
int total_money = 0;
int money = 0;
int cnt = 0;

int main(void)
{
	int start = 0;
	int a = 0;
	char c;
	printf("------------- Vending Machine -------------\n");
	printf(" Hello, Welcome to Beverage Vending Machine!\n");
	printf(" Please enter ENTER KEY to start!\n ");
	for (;;)
	{
		if (_kbhit()) {
			c = _getch();
			if (c == 13)
			{
				break;
			}
			else
			{
				printf("Please press the ENTER key again\n");
			}
		}
	}
	switch (c)
	{
	case 13:
		while (1)
		{
			printf("------------- Vending Machine -------------\n");
			printf(" 1. 솔의 눈(800 WON)\n 2. 실론 티(900 WOM)\n 3. ZICO(2800 WON)\n 4. 맥콜(800WON)\n 5. 아침 햇살(1200 WON)\n 6. 데자와(800 WON)\n 7. Dr.Pepper(1200 WON)\n 8. 덴마크 민트초코 우유(1500 WON)\n");
			printf(" Please select the item you want: ");
			scanf(" %d", &a);
			printf("-------------------------------------------\n");
			if (a < 0 || a > 8)
			{
				printf("Please select a number from the menu!\n");
				continue;
			}
			fflush(stdin);

			printf("Please input the number of products!: ");
			scanf(" %d", &cnt);
			if (cnt < 0)
			{
				printf("Wrong Input!\n");
				continue;
			}

			switch (a)
			{
			case 1:
				money += sol * cnt;
				pay(&p);
				break;
			case 2:
				money += ciltea * cnt;
				pay(&p);
				break;
			case 3:
				money += ZICO * cnt;
				pay(&p);
				break;
			case 4:
				money += maccol * cnt;
				pay(&p);
				break;
			case 5:
				money += achim * cnt;
				pay(&p);
				break;
			case 6:
				money += dejawa * cnt;
				pay(&p);
				break;
			case 7:
				money += drpper * cnt;
				pay(&p);
				break;
			case 8:
				money += mint * cnt;
				pay(&p);
				break;;

			default:
				break;
			}

		}
	}
}

int pay(int* p)
{	
	while (1)
	{
		printf("Press 1 to select more, Press 2 to pay: ");
		scanf(" %d", p);
		if (*p != 1 && *p != 2)
		{
			printf("Please Input Correct value!\n");
			continue;
		}
		fflush(stdin);

		if (*p == 1)
		{
			return;
		}
		else if (*p == 2)
		{
			printf("Input Money!: ");
			scanf(" %d", &total_money);
			if (total_money < money)
			{
				printf("%d WON is not enough money. Please put in more money.\n",money-total_money);
			}
			else if (total_money == money)
			{
				printf("Thank you for using it.\n");
				break;
			}
			else if (total_money > money)
			{
				printf("Changes of %d WON will be refunded.\n", -(money-total_money));
				printf("Thank you for using it.\n");
				break;
			}
			saveToFile(money, cnt);
			break;
		}

	}
}
	
	
	