// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"// 胶囊体头文件

ABird::ABird()  
{
 	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));//创建胶囊体并且命名
	Capsule->SetCapsuleHalfHeight(20.f);//设置胶囊体高度
	Capsule->SetCapsuleRadius(15.f);//设置胶囊体半径
	SetRootComponent(Capsule);// 相当于RootComponent = Capsule;修改默认根组件。
}


void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);  

}

