// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetUpGame();

    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s\nIt is %i letters long"), *HiddenWord, HiddenWord.Len()));

    // Welcome player
    PrintLine(TEXT("Guess the isogram and win a prize"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len()); // TODO remove magic number
    PrintLine(TEXT("Type in your guess and press enter"));
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
        if (Input.Len() != HiddenWord.Len())
        {
            // FString::Printf is included in terminal code
            PrintLine(TEXT("You do know how to count to %i right?"), HiddenWord.Len()); // TODO remove magic number
            PrintLine(TEXT("Now let's try this again."));
        }

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