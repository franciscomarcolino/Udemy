#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	Ok,
	Not_Isogram,
	Wrong_Lenght,
	Not_lowercase
};

class FBullCowGame
{
public:

	FBullCowGame();
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;	
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	int32 GetHiddenWordLenght() const;
	FBullCowCount SubmitValidGuess(FString);	

private:

	//See constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};
