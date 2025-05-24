// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/SS_Enemy_ai_controller.h"
#include "Characters/SS_Shooter_character.h"

// Unreal includes
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"



ASS_Enemy_ai_controller::ASS_Enemy_ai_controller()
{
	// Set AI Behavior Tree.
	static  ConstructorHelpers::FObjectFinder<UBehaviorTree> ai_behavior_tree_container(*behavior_tree_path_);
	if (ai_behavior_tree_container.Succeeded())
	{
		ai_behavior_tree_ = ai_behavior_tree_container.Object;
	}
}

auto ASS_Enemy_ai_controller::BeginPlay() -> void
{
	Super::BeginPlay();

	if (ai_behavior_tree_ != nullptr)
	{
		APawn* player_pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		RunBehaviorTree(ai_behavior_tree_);

		GetBlackboardComponent()->SetValueAsVector(TEXT("start_location"), GetPawn()->GetActorLocation());
	}
}

auto ASS_Enemy_ai_controller::Tick(float delta_time) -> void
{
	Super::Tick(delta_time);
}

auto ASS_Enemy_ai_controller::b_is_dead() const -> bool
{
	if (ASS_Shooter_character* controlled_character = Cast<ASS_Shooter_character>(GetPawn()))
	{
		return controlled_character->get_is_dead();
	}

	return true;
}