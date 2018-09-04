#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Functions declarations
void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText PlayerGuess);
bool AskWantsToPlayAgain();

//New Game instance
FBullCowGame BCGame;

int main()
{
	//Variables
	bool bWantsToPlayAgain = false;

	//Logic
	do
	{	
	PrintIntro();
	PlayGame();
	bWantsToPlayAgain = AskWantsToPlayAgain();
	} while (bWantsToPlayAgain == true);
	
	//End of the function
	return 0;
}

void PrintIntro()
{
	//Constants
	constexpr int32 WORD_LENGHT = 9;
	
	//Logic
	system("cls");
	std::cout << std::endl << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGHT << " letter isogram i am thinking of?" << std::endl;
	
	//End of the function
	return;
}

void PlayGame()
{
	//Variables
	FText PlayerGuess = "";	
	FBullCowCount BullCowCount;

	//Logic	
	BCGame.Reset();
	//std::cout << BCGame.GetMaxTries();
	PlayerGuess = GetGuess();

	BullCowCount = BCGame.SubmitGuess(PlayerGuess);

	std::cout << "Bulls: " << BullCowCount.Bulls << ". " << "Cows: " << BullCowCount.Cows << ".";

	//TODO Check de validacity of the guess
	//PrintGuess(PlayerGuess);

	//End of the function
	return;
}

FText GetGuess()
{
	//Variables
	FText PlayerGuess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	//Logic	
	std::cout << std::endl << "Try number " << CurrentTry << " --> Type your guess: ";
	std::getline(std::cin, PlayerGuess);	

	//End of the function
	return PlayerGuess;
}

void PrintGuess(FText PlayerGuess)
{
	//Logic
	std::cout << "This is your guess: '" << PlayerGuess << "'" << std::endl;

	//End of the function
	return;
}

bool AskWantsToPlayAgain()
{
	//Variables	
	FText PlayerAnswerKeepPlaying = "";

	//Logic
	std::cout << std::endl << "Do you wanna keep playing (y/n)?" << std::endl;	
	std::getline(std::cin, PlayerAnswerKeepPlaying);
	
	//End of the function
	return (PlayerAnswerKeepPlaying[0] == 'y') || (PlayerAnswerKeepPlaying[0] == 'Y');
}