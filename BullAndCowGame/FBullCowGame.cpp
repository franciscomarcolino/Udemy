#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	//Variables declaration
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	//Variables initiation
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}


bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	//Variables declaration
	FBullCowCount BullCowCount;
	
	int32 HiddenWordLength = MyHiddenWord.length();
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

	
	return BullCowCount;
}

