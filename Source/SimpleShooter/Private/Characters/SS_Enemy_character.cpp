// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SS_Enemy_character.h"
#include "Weapons/SS_Enemy_rifle.h"
#include "AI/SS_Enemy_ai_controller.h"
#include "Components/SS_Character_movement_component.h"


ASS_Enemy_character::ASS_Enemy_character(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer.SetDefaultSubobjectClass<USS_Character_movement_component>(ACharacter::CharacterMovementComponentName))
{
	setup_character();
}

auto ASS_Enemy_character::BeginPlay() -> void
{
	Super::BeginPlay();

	// Setup giving gun to character.
	gun_ref_ = GetWorld()->SpawnActor<ASS_Gun_base>(ASS_Enemy_rifle::StaticClass());
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	gun_ref_->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("weapon_socket"));
	gun_ref_->SetOwner(this);
}

auto ASS_Enemy_character::setup_character() -> void
{
	AIControllerClass = ASS_Enemy_ai_controller::StaticClass();

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletal_mesh_path_container(*enemy_mesh_path_);
	if (skeletal_mesh_path_container.Succeeded())
	{
		// Set Mesh to our skeletal mesh path.
		character_mesh_ = GetMesh();
		character_mesh_->SetSkeletalMesh(skeletal_mesh_path_container.Object);
		character_mesh_->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
		character_mesh_->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	// Set Anim Instance to our skeletal mesh path.
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> anim_class_container(*anim_bp_file_path_);
	if (anim_class_container.Succeeded())
	{
		character_mesh_->SetAnimInstanceClass(anim_class_container.Object->GeneratedClass);
	}

	// Set Hip Fire Montage for our skeletal mesh.
	static ConstructorHelpers::FObjectFinder<UAnimMontage> hip_fire_montage_container(*hip_fire_montage_path_);
	if (hip_fire_montage_container.Succeeded())
	{
		hip_fire_montage_ = hip_fire_montage_container.Object;
	}
}