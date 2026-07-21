// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"

void UHUDWidget::SetHealthPercent(float NewPercent)
{
	if (HealthBar && NewPercent >= 0.0f && NewPercent <= 1.0f)
	{
		HealthBar->SetPercent(NewPercent);

	}
}

void UHUDWidget::SetEnemiesRemaining(int32 Count)
{
	if (EnemiesRemainingText)
	{
		EnemiesRemainingText->SetText(FText::FromString(FString::Printf(TEXT("Enemies: %d"), Count)));
	}
}
