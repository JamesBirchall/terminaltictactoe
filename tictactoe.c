// tictactoe.c - game based on Tic Tac Toe
// Author - James Birchall
// Date - 2nd September 2012

#include <stdio.h>

//prototype functions used in game
void welcome();
void drawGrid();
int promptPlayer(int);
int checkSetValue(int);
void setGrid(int, int);
int checkThreeInRow();
int checkFull();
void win(int);
void draw();

//define grid and set to empty - global as only one needed
char gridOne = '1';
char gridTwo = '2';
char gridThree = '3';
char gridFour = '4';
char gridFive = '5';
char gridSix = '6';
char gridSeven = '7';
char gridEight = '8';
char gridNine = '9';

int main(void){

	int gameOver = 0;
	int currentPlayer = 1;

	welcome();	//draw credits & welcome message

	drawGrid();	//draw empty grid first time around

	while(gameOver != 1){

		int setValue = 0;
		setValue = promptPlayer(currentPlayer);

		if(checkSetValue(setValue) == 0){
      drawGrid();
      printf("That space is already taken! Shame on you...try again...\n");

    	continue;
    }
    else{
      setGrid(currentPlayer, setValue);
    }




		drawGrid();

		if(checkThreeInRow() != 0){
			gameOver = 1;
			win(currentPlayer);
		} else if(checkFull() == 1){
			gameOver = 1;
			draw();
		}

		if(currentPlayer == 1)
			currentPlayer = 2;
		else
			currentPlayer = 1;

	}

  printf("\n\nGoodbye for now!\n");

	return 0;
}

void welcome(){
	printf("\n\nWelcome to Tic Tac Toe\n");
	printf("\nThis version brought to you by James Birchall\n");
	printf("\nSmee Studios 2012\n\n");
}

void drawGrid(){
	printf("\n***************\n");
	printf("*-------------*\n");
	printf("*| %c | %c | %c |*\n", gridOne, gridTwo, gridThree);
	printf("*-------------*\n");
	printf("*| %c | %c | %c |*\n", gridFour, gridFive, gridSix);
	printf("*-------------*\n");
	printf("*| %c | %c | %c |*\n", gridSeven, gridEight, gridNine);
	printf("*-------------*\n");
	printf("***************\n\n\n");
}

int promptPlayer(int player){
  int scannedNumber = 0;
  int wrong = 0;

  while(scannedNumber < 1 || scannedNumber > 9){
    if(0 == wrong)
      printf("Player %i, enter a grid number still available [1-9]: ", player);
    else
      printf("Invalid number, Player %i, enter a grid number [1-9]: ", player);

    scanf("%d", &scannedNumber);
    wrong = 1;
  }
}

int checkSetValue(int value){
  int passed = 0;

  switch (value){
    case 1:
      if(gridOne == '1')
        passed = 1;
        break;
    case 2:
      if(gridTwo == '2')
        passed = 1;
        break;
    case 3:
      if(gridThree == '3')
        passed = 1;
        break;
    case 4:
      if(gridFour == '4')
        passed = 1;
        break;
    case 5:
      if(gridFive == '5')
        passed = 1;
        break;
    case 6:
      if(gridSix == '6')
        passed = 1;
        break;
    case 7:
      if(gridSeven == '7')
        passed = 1;
        break;
    case 8:
      if(gridEight == '8')
        passed = 1;
        break;
    case 9:
      if(gridNine == '9')
        passed = 1;
        break;
  }

  return passed;
}

void setGrid(int player, int value){

  if(player == 1){
    switch (value){
      case 1:
        gridOne = 'X';
        break;
      case 2:
        gridTwo = 'X';
        break;
      case 3:
        gridThree = 'X';
        break;
      case 4:
        gridFour = 'X';
        break;
      case 5:
        gridFive = 'X';
        break;
      case 6:
        gridSix = 'X';
        break;
      case 7:
        gridSeven = 'X';
        break;
      case 8:
       gridEight = 'X';
        break;
      case 9:
        gridNine = 'X';
        break;
    }
  }
  else{
    switch (value){
      case 1:
        gridOne = 'O';
        break;
      case 2:
        gridTwo = 'O';
        break;
      case 3:
        gridThree = 'O';
        break;
      case 4:
        gridFour = '0';
        break;
      case 5:
        gridFive = 'O';
        break;
      case 6:
        gridSix = 'O';
        break;
      case 7:
        gridSeven = 'O';
        break;
      case 8:
       gridEight = 'O';
        break;
      case 9:
        gridNine = 'O';
        break;
    }
  }
}

int checkThreeInRow(){
  int foundThree = 0;

  //check for all Player 1, then check all Player 2

  if(gridOne == 'X' && gridTwo == 'X' && gridThree == 'X')
    foundThree = 1;
  if(gridFour == 'X' && gridFive == 'X' && gridSix == 'X')
    foundThree = 1;
  if(gridSeven == 'X' && gridEight == 'X' && gridNine == 'X')
    foundThree = 1;
  if(gridOne == 'X' && gridFour == 'X' && gridSeven == 'X')
    foundThree = 1;
  if(gridTwo == 'X' && gridFive == 'X' && gridEight == 'X')
    foundThree = 1;
  if(gridThree == 'X' && gridSix == 'X' && gridNine == 'X')
    foundThree = 1;
  if(gridOne == 'X' && gridFive == 'X' && gridNine == 'X')
    foundThree = 1;
  if(gridThree == 'X' && gridFive == 'X' && gridSeven == 'X')
    foundThree = 1;

  if(gridOne == 'O' && gridTwo == 'O' && gridThree == 'O')
    foundThree = 1;
  if(gridFour == 'O' && gridFive == 'O' && gridSix == 'O')
    foundThree = 1;
  if(gridSeven == 'O' && gridEight == 'O' && gridNine == 'O')
    foundThree = 1;
  if(gridOne == 'O' && gridFour == 'O' && gridSeven == 'O')
    foundThree = 1;
  if(gridTwo == 'O' && gridFive == 'O' && gridEight == 'O')
    foundThree = 1;
  if(gridThree == 'O' && gridSix == 'O' && gridNine == 'O')
    foundThree = 1;
  if(gridOne == 'O' && gridFive == 'O' && gridNine == 'O')
    foundThree = 1;
  if(gridThree == 'O' && gridFive == 'O' && gridSeven == 'O')
    foundThree = 1;

  return foundThree;
}

int checkFull(){
  int full = 0;

  if(gridOne != '1' && gridTwo != '2' && gridThree != '3' && gridFour != '4' && gridFive != '5' && gridSix != '6' && gridSeven != '7' && gridEight != '8' && gridNine != '9')
    full = 1;

  return full;
}

void win(int player){
  printf("Congratulations Player %i, you WIN!\n", player);
}

void draw(){
  printf("A stalemate...you have DRAWN!\n");
}
