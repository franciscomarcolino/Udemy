#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Functions declarations
void PrintIntro();
void PlayGame();
bool AskWantsToPlayAgain();
FText GetValidGuess();

//New Game instance
FBullCowGame BCGame;

int main()
{
	//Variables
	

	//Logic	
	do
	{
		PrintIntro();
		PlayGame();
	} 
	while (AskWantsToPlayAgain());

	//End of the function
	return 0;
}

void PrintIntro()
{
	//Logic
	system("cls");
	std::cout << std::endl << std::endl << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram i am thinking of?" << std::endl;
	
	//End of the function
	return;
}

void PlayGame()
{
	//Variables
	FText PlayerGuess = "";	
	FBullCowCount BullCowCount;
	EGuessStatus GuessStatus;
	
	//Logic	
	BCGame.Reset();

	//for (int MAX_TRY_ITERATION = 1; MAX_TRY_ITERATION <= BCGame.GetMaxTries(); MAX_TRY_ITERATION++)
	//{
		while ( ! BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries() )
		{
			PlayerGuess = GetValidGuess();		
			BullCowCount = BCGame.SubmitValidGuess(PlayerGuess);
			std::cout << std::endl << "Bulls: " << BullCowCount.Bulls << ". " << "Cows: " << BullCowCount.Cows << ".";		
		}

		if (!BCGame.IsGameWon())
		{
			std::cout << std::endl << std::endl << "You lost the game. Try again!" << std::endl;
		}
		else if (BCGame.IsGameWon())
		{
			std::cout << std::endl << std::endl << "Congrats!!! You won the game!" << std::endl;
		}
		else
		{
			std::cout << std::endl << std::endl << "Unknown behavior." << std::endl;
		}

	//}
	
	return;
}

FText GetValidGuess()
{
	//Variables
	FText PlayerGuess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	EGuessStatus GuessStatus = EGuessStatus::Invalid;

	//Logic	
	do 
	{
		std::cout << std::endl << std::endl << "Try number " << CurrentTry << " --> Type your guess: ";
		std::getline(std::cin, PlayerGuess);
		GuessStatus = BCGame.CheckGuessValidity(PlayerGuess);

		switch (GuessStatus)
		{
		case EGuessStatus::Ok:
			std::cout << std::endl << "This is a valid guess.";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << std::endl << "Error: please enter an isogram.";
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << std::endl << "Error: please enter a " << BCGame.GetHiddenWordLenght() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_lowercase:
			std::cout << std::endl << "Error: please enter the guess in lowercase.";
			break;
		default:
			return PlayerGuess;
			break;
		}
	} while (GuessStatus != EGuessStatus::Ok);

	//End of the function
	return PlayerGuess;
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