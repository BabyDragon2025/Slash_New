// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"
#include "GameFramework/SpringArmComponent.h"//弹簧臂头文件
#include "Camera/CameraComponent.h"//摄像

ASlashCharacter::ASlashCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	//用控制器旋转，让人物视角转向正常，人体不会随着“超人飞行”，而是站着换视角。
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	//创造摇臂，附加到根组件上
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	//设置臂长
	CameraBoom->TargetArmLength = 300.f;//由于设立了蓝图可见，所以蓝图也可以改。这个相当于默认值。

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);//设置到CameraBoom目录里面

}


void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//和鸟类似，绑定轴映射
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASlashCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASlashCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASlashCharacter::LookUp);
}

void ASlashCharacter::MoveForward(float Value)
{
	if (Controller && (Value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void ASlashCharacter::MoveRight(float Value)
{
	if (Controller && (Value != 0.f))
	{
		FVector Right = GetActorRightVector();//调用右移函数，获得右移向量
		AddMovementInput(Right, Value);
	}
}

void ASlashCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASlashCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

