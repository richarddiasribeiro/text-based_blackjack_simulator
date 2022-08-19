#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cards [52][3] = {
	{1, 1, 1},    {1, 2, 1},   {1, 3, 1},   {1, 4, 1}, //Ace
	{2, 1, 2},    {2, 2, 2},   {2, 3, 2},   {2, 4, 2},
	{3, 1, 3},    {3, 2, 3},   {3, 3, 3},   {3, 4, 3},
	{4, 1, 4},    {4, 2, 4},   {4, 3, 4},   {4, 4, 4},
	{5, 1, 5},    {5, 2, 5},   {5, 3, 5},   {5, 4, 5},
	{6, 1, 6},    {6, 2, 6},   {6, 3, 6},   {6, 4, 6},
	{7, 1, 7},    {7, 2, 7},   {7, 3, 7},   {7, 4, 7},
	{8, 1, 8},    {8, 2, 8},   {8, 3, 8},   {8, 4, 8},
	{9, 1, 9},    {9, 2, 9},   {9, 3, 9},   {9, 4, 9},
	{10, 1, 10},  {10, 2, 10}, {10, 3, 10}, {10, 4, 10},
	{11, 1, 10},  {11, 2, 10}, {11, 3, 10}, {11, 4, 10}, //Jack
	{12, 1, 10},  {12, 2, 10}, {12, 3, 10}, {12, 4, 10}, //Queen
	{13, 1, 10},  {13, 2, 10}, {13, 3, 10}, {13, 4, 10} //King
};

#define CARD_RANK_POSITION 0
#define CARD_SUIT_POSITION 1
#define CARD_GAME_VALUE 2

#define DIAMONDS_SUIT 1
#define SPADES_SUIT 2
#define HEARTS_SUIT 3
#define CLUBS_SUIT 4

int player_score = 0;
int player_card_quantity = 0;
int player_cards [5];


int computer_score = 0;
int computer_cards_quantity = 0;
int computer_cards [5];

int next_card_position = 0;
int next_player_card_position = 0;
int next_computer_card_position = 0;




void shuffle();
void get_new_cards(int  quantity, char player_or_computer);
void player_move();
void computer_move();
void print_cards_visually();
void print_cards_numerically();





int main(int argc, char *argv[]) {
	
	printf(" ________________________________________________________________________\n");
	printf("|             Modified Blackjack C Game, by Richard D. Ribeiro           |\n");
	printf("|________________________________________________________________________|\n\n");
	
	char main_menu_entered_option = 'O';
	
		printf("%c%c%c%c%c%c Main menu %c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
		printf("%c 1 > Play           %c\n", 186, 186);
		printf("%c Other > Exit game  %c\n", 186, 186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
	
		scanf("%c", &main_menu_entered_option);
		fflush(stdin);
	
		if (main_menu_entered_option == '1') {
			
			srand(time(NULL));
			shuffle();
			
			get_new_cards(2, 'P');
			get_new_cards(2, 'C');
			
			int player_printed_cards_counter;
			int computer_printed_cards_counter;
			
			printf("\nYour initial hand is: \n");
			for (player_printed_cards_counter = 0; player_printed_cards_counter < player_card_quantity; player_printed_cards_counter++) {
				print_cards_visually(cards[player_cards[player_printed_cards_counter]][CARD_RANK_POSITION], cards[player_cards[player_printed_cards_counter]][CARD_SUIT_POSITION]);
			}
				
			printf("\nComputer's initial hand is: \n");
			for (computer_printed_cards_counter = 0; computer_printed_cards_counter < computer_cards_quantity; computer_printed_cards_counter++) {
				print_cards_visually(cards[computer_cards[computer_printed_cards_counter]][CARD_RANK_POSITION], cards[computer_cards[computer_printed_cards_counter]][CARD_SUIT_POSITION]);
			}
			
			
			
			
			while (1) {
				
				player_move();
				
				printf("\nYour hand is now like this: \n");
				for (player_printed_cards_counter = 0; player_printed_cards_counter < player_card_quantity; player_printed_cards_counter++) {
					print_cards_visually(cards[player_cards[player_printed_cards_counter]][CARD_RANK_POSITION], cards[player_cards[player_printed_cards_counter]][CARD_SUIT_POSITION]);
				}
				
				computer_move();
				
				printf("\nComputer's hand is now like this \n");
				for (computer_printed_cards_counter = 0; computer_printed_cards_counter < computer_cards_quantity; computer_printed_cards_counter++) {
					print_cards_visually(cards[computer_cards[computer_printed_cards_counter]][CARD_RANK_POSITION], cards[computer_cards[computer_printed_cards_counter]][CARD_SUIT_POSITION]);
				}
				
			}
			
		} else {
			system("CLS");
			printf("Exiting...\n");
			exit(0);
		}
	
}

void shuffle() {
	int i;
	int drawn_position;
	int temp [3];
	
	for (i = 0; i < 52; i++)
	{
		drawn_position = rand() % 52;

		temp[CARD_RANK_POSITION] = cards[i][CARD_RANK_POSITION];
		temp[CARD_SUIT_POSITION] = cards[i][CARD_SUIT_POSITION];
		temp[CARD_GAME_VALUE] = cards[i][CARD_GAME_VALUE];
		
		cards[i][CARD_RANK_POSITION] = cards[drawn_position][CARD_RANK_POSITION];
		cards[i][CARD_SUIT_POSITION] = cards[drawn_position][CARD_SUIT_POSITION];
		cards[i][CARD_GAME_VALUE] = cards[drawn_position][CARD_GAME_VALUE];
		
		cards[drawn_position][CARD_RANK_POSITION] = temp[CARD_RANK_POSITION];
		cards[drawn_position][CARD_SUIT_POSITION] = temp[CARD_SUIT_POSITION];
		cards[drawn_position][CARD_GAME_VALUE] = temp[CARD_GAME_VALUE];
	}
}

void get_new_cards(int quantity, char player_or_computer) {
	int i;
	
	if (player_or_computer == 'P') {
		for (i = 0; i < quantity; i++) {
			player_cards[next_player_card_position] = next_card_position;
			player_score += cards[next_card_position][CARD_GAME_VALUE];
			next_card_position++;
			next_player_card_position++;
			player_card_quantity++;
		}
	} else if (player_or_computer == 'C'){
		for (i = 0; i < quantity; i++) {
			computer_cards[next_computer_card_position] = next_card_position;
			computer_score += cards[next_card_position][CARD_GAME_VALUE];
			next_card_position++;
			next_computer_card_position++;
			computer_cards_quantity++;
		}
	}
}

void endgame(int player_won) {
    int player_printed_cards_counter;
	int computer_printed_cards_counter;
		
    system("CLS");
	player_won ? printf("You win!\n") : printf("You lose :(\n");
						
	printf("\nYour hand is now like this: \n");
		for (player_printed_cards_counter = 0; player_printed_cards_counter < player_card_quantity; player_printed_cards_counter++) {
			print_cards_visually(cards[player_cards[player_printed_cards_counter]][CARD_RANK_POSITION], cards[player_cards[player_printed_cards_counter]][CARD_SUIT_POSITION]);
		}
	printf("\nComputer's hand is now like this \n");
	for (computer_printed_cards_counter = 0; computer_printed_cards_counter < computer_cards_quantity; computer_printed_cards_counter++) {
		print_cards_visually(cards[computer_cards[computer_printed_cards_counter]][CARD_RANK_POSITION], cards[computer_cards[computer_printed_cards_counter]][CARD_SUIT_POSITION]);
	}
						
	printf("Your score: %d\n", player_score);
	printf("Computer's score: %d\n", computer_score);
	printf("See ya!\n");
	system("PAUSE");
	exit(0);
}

void player_move() {
		char player_option = 'O';
		
		while (1) {
			printf("\n%c%c%c%c%c%c%c%c Your turn: %c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
			printf("%c 1 > Take a new card      %c\n", 186, 186);
			printf("%c 2 > Skip your turn       %c\n", 186, 186);
			printf("%c 3 > Exit game            %c\n", 186, 186);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
		
			scanf("%c", &player_option);
			fflush(stdin);
			
			if (player_option == '1') {
				
				if (player_card_quantity < 5) {
					
					get_new_cards(1, 'P');
					
					if (player_score == 21) {
						endgame(1);
					} else if (player_score > 21) {
						endgame(0);
					} else {
						return;
					}
					 
				} else {
					printf("Error: each player can only have up to 5 cards");
					continue;
				}
			} else if (player_option == '2') {
				break;
			} else if (player_option == '3') {
				printf("Exiting...\n");
				exit(0);
			} else {
				system("CLS");
				printf("Error: unrecognized option \n\n");
			}
		}
		
}

void computer_move() {
	int player_printed_cards_counter;
	int computer_printed_cards_counter;
		
	printf("\n\nComputer's turn...\n");
	
	srand(time(NULL));
	
	if (computer_cards_quantity < 5 && (rand() % 10 < 5)) {
					
		get_new_cards(1, 'C');
		printf("\n\nComputer has taken a new card...\n\n");
					
		if (computer_score == 21) {
			endgame(0);
		} else if (computer_score > 21) {
			endgame(1);
		}
		
	} else {
		printf("\n\nComputer has skipped its turn...\n\n");
		return;
	}
}

void print_cards_visually(int value, int suit) {
	char card_suit_part_1; //first digit
	char card_suit_part_2 = ' '; //second digit, in case there is one
	
	//translates card suite from int to char
	if (value == 1) {
		card_suit_part_1 = 'A';
	} else if (value == 2) {
		card_suit_part_1 = '2';
	} else if (value == 3) {
		card_suit_part_1 = '3';
	} else if (value == 4) {
		card_suit_part_1 = '4';
	} else if (value == 5) {
		card_suit_part_1 = '5';
	} else if (value == 6) {
		card_suit_part_1 = '6';
	} else if (value == 7) {
		card_suit_part_1 = '7';
	} else if (value == 8) {
		card_suit_part_1 = '8';
	} else if (value == 9) {
		card_suit_part_1 = '9';
	} else if (value == 10) {
		
		card_suit_part_1 = '1';
		card_suit_part_2 = '0';
		
	} else if (value == 11) {
		card_suit_part_1 = 'P';
	} else if (value == 12) {
		card_suit_part_1 = 'Q';
	} else if (value == 13) {
		card_suit_part_1 = 'K';
	}
	
	if (suit == DIAMONDS_SUIT) {
		printf(" %c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 191);
		printf(" %c%c%c%c%c%c%c\n", 179, card_suit_part_1, card_suit_part_2, ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '^', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '/', ' ', '\\', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '\\', ' ', '/', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', 'V', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', card_suit_part_1, card_suit_part_2, 179);
		printf(" %c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 217);
	} else if (suit == SPADES_SUIT) {
		printf(" %c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 191);
		printf(" %c%c%c%c%c%c%c\n", 179, card_suit_part_1, card_suit_part_2, ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '.', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '/', ' ', '\\', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, '(', '_', ' ', '_', ')', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '|', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', card_suit_part_1, card_suit_part_2, 179);
		printf(" %c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 217);
	} else if (suit == HEARTS_SUIT) {
		printf(" %c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 191);
		printf(" %c%c%c%c%c%c%c\n", 179, card_suit_part_1, card_suit_part_2, ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '_', ' ', '_', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, '(', ' ', 'V', ' ', ')', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '\\', ' ', '/', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', 'V', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', card_suit_part_1, card_suit_part_2, 179);
		printf(" %c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 217);
	} else if (suit == CLUBS_SUIT) {
		printf(" %c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 191);
		printf(" %c%c%c%c%c%c%c\n", 179, card_suit_part_1, card_suit_part_2, ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '_', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', '(', ' ', ')', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, '(', '_', ' ', '_', ')', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '|', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', card_suit_part_1, card_suit_part_2, 179);
		printf(" %c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 217);
	} else {
		printf(" %c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 191);
		printf(" %c%c%c%c%c%c%c\n", 179, card_suit_part_1, card_suit_part_2, ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '?', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', '?', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', ' ', ' ', 179);
		printf(" %c%c%c%c%c%c%c\n", 179, ' ', ' ', ' ', card_suit_part_1, card_suit_part_2, 179);
		printf(" %c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 217);
	}
}

void print_cards_numerically() {
	int i;
	int j;
	
	for (i = 0; i < 52; i++) {
		printf("Value: %d / Suit: %d", cards[i][CARD_RANK_POSITION], cards[i][CARD_SUIT_POSITION]);
		printf("\n");
	}
			
}
