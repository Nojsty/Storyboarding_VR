// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringToTxt.generated.h"

/**
 * Create a txt file out of entered String
 */
UCLASS()
class UStringToTxt : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Whatever")
		static void StringToTextFile(const FString str);
};
