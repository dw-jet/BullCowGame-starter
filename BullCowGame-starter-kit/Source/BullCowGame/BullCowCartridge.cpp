// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcome player
    PrintLine(TEXT("Guess the isogram and win a prize"));
    PrintLine(TEXT("Guess the 5 letter word")); // TODO remove magic number
    PrintLine(TEXT("Press enter to continue..."));

    SetUpGame();

    // Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking PlayerGuess

    if (Input == HiddenWord)
    {
        PrintLine("I'm out. I don't fuck with psychics.");
    }
    else
    {
        PrintLine("What an idiot");
    }
    
}
// Check if isogram
// Check right number of characters

// Remove life

// Check if lives > 0
// If yes guess again
// If no show gameover and hiddenword
// Prompt to play again
// Check user input
// Play again quit

void UBullCowCartridge::SetUpGame()
{
    HiddenWord = TEXT("thing");
    Lives = 3;
}