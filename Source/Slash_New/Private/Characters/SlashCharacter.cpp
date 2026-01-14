// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashCharacter.h"
#include "GameFramework/SpringArmComponent.h"//弹簧臂头文件
#include "Camera/CameraComponent.h"//摄像
#include "GameFramework/CharacterMovementComponent.h"//角色移动组件头文件

ASlashCharacter::ASlashCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	//用控制器旋转，让人物视角转向正常，人体不会随着“超人飞行”，而是站着换视角。
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//角色移动组件，控制转向速度。
	GetCharacterMovement()->bOrientRotationToMovement = true;//开启角色转向
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);//设置偏航转向速度。

	
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
		//确定我们的前进方向。
		//获取旋转角度。不打算改变这个变量->加入const
		const FRotator ControlRotation = GetControlRotation();
		//前进等行动角度只关注偏航分量。使用FRotator构造函数。
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		
		//创建一个FRotationMatrix，传入偏航角，并且利用FRotationMatrix函数调用GetUnitAxis函数，得到标准化的X方向向量。
		const FVector Direction=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);//增加输入。
	}
}

void ASlashCharacter::MoveRight(float Value)
{
	if (Controller && (Value != 0.f))
	{
		//确定我们的右边方向。
		
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);//Y向量控制左右。
		AddMovementInput(Direction, Value);//增加输入。
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

