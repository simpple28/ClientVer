// Copyright SimppleGames, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClientVerBPLibrary.generated.h"


UCLASS()
class UClientVerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


	UFUNCTION(BlueprintCallable, Category = "BPF")
		static FString GetAppVersion();

	UFUNCTION(BlueprintCallable, Category = "BPF")
		static void SetAppVersion(const FString& NewVersion);
	
	UFUNCTION(BlueprintCallable, Category = "BPF")
		static int GetUnixTimestamp(FDateTime Time);
};
