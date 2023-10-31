// Fill out your copyright notice in the Description page of Project Settings.


#include "StringToTxt.h"

#include "Misc/FileHelper.h"
#include "Misc/DateTime.h"

/* https://unrealcommunity.wiki/file-manipulation:-readwrite-5nytg2tu */
void UStringToTxt::StringToTextFile(const FString str)
{
    FString file = FPaths::ProjectSavedDir();
    
    // Use current date and time
    FDateTime timestamp = FDateTime::Now();

    // File path for fileName
    file.Append(TEXT("Notes.txt"));

    // We will use this FileManager to deal with the file.
    IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
    
    // String to load the file into
    FString fileContent;

    // Always first check if the file that you want to manipulate exist.
    if (FileManager.FileExists(*file))
    {
        // We use the LoadFileToString to load the file into a string
        if (FFileHelper::LoadFileToString(fileContent, *file, FFileHelper::EHashOptions::None))
        {
            // Create the string to write into a file
            FString strToWrite = fileContent + timestamp.ToString() + '\n' + str + '\n';
            FFileHelper::SaveStringToFile(strToWrite, *file);

            UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Success, Written: \"%s\" to the text file"), *strToWrite);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to text file."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
        UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
    }
}
