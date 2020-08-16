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

    else 
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetUpGame()
{
    HiddenWord = TEXT("thing");
    Lives = HiddenWord.Len();
    bGameOver = false;
    ClearScreen();
    // Welcome player
    PrintLine(TEXT("Guess the isogram and win a prize"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i guesses to get it right"), Lives);

    PrintLine(TEXT("Type in your guess and press enter"));
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
        ClearScreen();
        PrintLine(TEXT("You are out of guesses."));
        PrintLine(TEXT("The word was: %s."), *HiddenWord);
        PrintLine(TEXT("You are the weakest link. Goodbye."));
        EndGame();
    }
    else
    {
        PrintLine(TEXT("Only %i guesses left"), Lives);
    }
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
        {
            PrintLine(TEXT("Alright. You win. I'm out though.\nI don't fuck with psychics."));
            EndGame();
        }
    else
    {
        if (Guess.Len() != HiddenWord.Len())
        {
            int32 HiddenWordLength = HiddenWord.Len();
            // FString::Printf is included in terminal code
            PrintLine(TEXT("It's %i letters, %i...\nYou do know how to count to %i right?"), HiddenWordLength,HiddenWordLength,HiddenWordLength);
        }
        else 
        {
            PrintLine(TEXT("Wow, that wasn't even close"));
        }
        LoseALife();
    }
}