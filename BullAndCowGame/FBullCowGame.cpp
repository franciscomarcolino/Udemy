#pragma once //make sure it import libraries only once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map

//The constructor of the class
FBullCowGame::FBullCowGame()
{
	Reset();
}

//Initialize tha game values
void FBullCowGame::Reset()
{
	//Variables declaration
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "plane";
	constexpr int32 INITIAL_CURRENT_TRY = 1;
	constexpr bool INITAL_GAME_IS_WON = false;

	//Variables initiation
	MyCurrentTry = INITIAL_CURRENT_TRY;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = INITAL_GAME_IS_WON;

	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLenghtToMaxTries{ {3,5}, {4,5}, {5,5}, {6,7}, {7,8} };

	return WordLenghtToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{		
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		//Not an isogram
		return EGuessStatus::Not_Isogram;		
	}
	else if (!IsLowerCase(Guess))
	{
		//Not lowercase
		return EGuessStatus::Not_lowercase;
	}
	else if (GetHiddenWordLenght() != Guess.length())
	{
		//Wrong lenght
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		//Ok
		return EGuessStatus::Ok;
	}
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	//Variables declaration
	int32 HiddenWordLength;
	FBullCowCount BullCowCount;
	
	HiddenWordLength = GetHiddenWordLenght();
	int32 GuessLenght = Guess.length();
	   
	for (int HiddenIteration = 0; HiddenIteration < HiddenWordLength; HiddenIteration++)
	{
		for (int GuessIteration = 0; GuessIteration < GuessLenght; GuessIteration++)
		{
			if (MyHiddenWord[HiddenIteration] == Guess[GuessIteration])
			{
				if (HiddenIteration == GuessIteration)
				{
					BullCowCount.Bulls++;					
				}
				else
				{	
					BullCowCount.Cows++;
				}
			}
			else
			{
				//Do nothing;
			}
		}
	}

	if ( BullCowCount.Bulls == GetHiddenWordLenght() )
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;

	for (char letter : Guess)
	{
		letter = tolower(letter);

		if (LetterSeen[letter])
		{
			return false;
		}
		else
		{
			LetterSeen[letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	//if (Guess.length() <= 1) { return true; }
	
	for (auto letter : Guess)
	{	
		if (!islower(letter))
		{
			return false;
		}		
	}
	return true;
}

