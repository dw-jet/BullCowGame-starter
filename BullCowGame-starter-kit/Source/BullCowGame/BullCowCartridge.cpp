// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetUpGame();

    // PrintLine(FString::Printf(TEXT("The HiddenWord is: %s\nIt is %i letters long"), *HiddenWord, HiddenWord.Len()));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (bGameOver)
    {
        ClearScreen();
        SetUpGame();
    }

    else {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("I'm out. I don't fuck with psychics."));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                // FString::Printf is included in terminal code
                PrintLine(TEXT("You do know how to count to %i right?"), HiddenWord.Len());
            }

            PrintLine("What an idiot");
            LoseALife();
        }
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
    Lives = HiddenWord.Len();
    bGameOver = false;
    ClearScreen();
    // Welcome player
    PrintLine(TEXT("Guess the isogram and win a prize"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter"));
    PrintLine(TEXT("You have %i guesses to get it right"), Lives);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine("Press enter to play again");
}

void UBullCowCartridge::LoseALife()
{
    Lives -= 1;
    if (Lives < 1)
    {
        PrintLine(TEXT("You are the weakest link. Goodbye."));
        EndGame();
    }
    else
    {
        PrintLine(TEXT("Only %i guesses left"), Lives);
    }
}