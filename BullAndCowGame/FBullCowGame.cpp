#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	//Variables declaration
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "p";
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
	return MyMaxTries;
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
	if (false)
	{
		//Not an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
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

