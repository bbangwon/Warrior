// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WarriorBaseCharacter.h"

// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 나중에 사용할 일부 VFX는 바닥에 데칼을 투사하는데, 캐릭터 메시가 아닌 바닥에만 영향을 주도록 할것임
	GetMesh()->bReceivesDecals = false;

}


