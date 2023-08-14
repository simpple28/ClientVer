// Copyright SimppleGames, Inc. All Rights Reserved.

#include "ClientVerBPLibrary.h"
#include "ClientVer.h"

UClientVerBPLibrary::UClientVerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


FString UClientVerBPLibrary::GetAppVersion()
{
	FString IniFilePath = FPaths::ProjectConfigDir() / TEXT("DefaultGame.ini");
	FString AppVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		AppVersion,
		GGameIni
	);
	return AppVersion;
}

// INI 파일에 값을 설정
void UClientVerBPLibrary::SetAppVersion(const FString& NewVersion)
{
	FString SectionName = TEXT("/Script/EngineSettings.GeneralProjectSettings");
	FString KeyName = TEXT("ProjectVersion");
	FString IniFilePath = FPaths::ProjectConfigDir() / TEXT("DefaultGame.ini");
	GConfig->SetString(*SectionName, *KeyName, *NewVersion, GGameIni);
	GConfig->SetString(*SectionName, *KeyName, *NewVersion, IniFilePath);
	GConfig->Flush(true, IniFilePath);
	GConfig->Flush(true, GGameIni);
}

int UClientVerBPLibrary::GetUnixTimestamp(FDateTime Time)
{
	return Time.ToUnixTimestamp();
}