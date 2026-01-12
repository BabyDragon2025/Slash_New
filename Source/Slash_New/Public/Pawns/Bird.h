// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

class UCapsuleComponent; //提前声明

UCLASS()
class SLASH_NEW_API ABird : public APawn  //Pawn派生自Actor，ABird是Actor的子类，编辑器会帮我们自动去掉A。
{
	GENERATED_BODY()

public:
	ABird();
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input//设置玩家输入组件函数。
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 
	
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere);//把胶囊体暴露给蓝图。
	UCapsuleComponent* Capsule; //建立胶囊体指针。准备设置胶囊体。


};
