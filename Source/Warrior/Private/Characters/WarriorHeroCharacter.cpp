// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WarriorHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


#include "WarriorDebugHelper.h"



AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	//캡슐 컴포넌트의 크기를 설정합니다. 반지름이 42, 높이가 96인 캡슐입니다.
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	//캐릭터가 컨트롤러의 회전에 영향을 받지 않도록 설정합니다. 즉 캐릭터는 항상 수직으로 서 있게 됩니다.
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//카메라 붐(Spring Arm Component)을 생성하고 설정합니다.
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;	// 카메라가 캐릭터로부터 200 유닛 떨어져 있도록 설정
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);	//카메라의 위치를 캐릭터의 뒤쪽과 위쪽으로 약간 이동시킵니다.
	CameraBoom->bUsePawnControlRotation = true;	//카메라 붐이 캐릭터의 회전에 따라 회전하도록 설정합니다.

	// 팔로우 카메라(Camera Component)를 생성하고 설정합니다.
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);	//카메라를 카메라 붐의 끝에 부착합니다.
	FollowCamera->bUsePawnControlRotation = false;	//카메라가 캐릭터의 회전에 따라 회전하지 않도록 설정합니다.

	// 캐릭터의 이동 컴포넌트의 설정을 조정합니다.
	GetCharacterMovement()->bOrientRotationToMovement = true;	//캐릭터가 이동 방향으로 회전하도록 설정합니다.
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);	// 캐릭터의 회전 속도를 설정합니다. Yaw 축에서 500도/초로 회전하도록 설정합니다.
	GetCharacterMovement()->MaxWalkSpeed = 400.f;	//캐릭터의 최대 걷기 속도를 설정합니다. 400 유닛/초로 설정합니다.
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;	//캐릭터가 걷기 상태에서 멈출 때의 감속도를 설정합니다.
}

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::Print(TEXT("Working"));
}
