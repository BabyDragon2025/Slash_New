// Fill out your copyright notice in the Description page of Project Settings...

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;//提前声明弹簧臂组件
class UCameraComponent;//提前声明摄像机组件

UCLASS()
class SLASH_NEW_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value); //前进函数。
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
private:
	//添加弹簧臂组件
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	//添加摄像机组件
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};
