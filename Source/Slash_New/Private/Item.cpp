// Fill out your copyright notice in the Description page of Project Settings.



#include "Item.h"
#include "Slash_New/DebugMacros.h"  //该头文件路径位于模块Slash_New的public下，所以，要（模块/.h）来包含



// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	//Amplitude = 0.25;//这个严格来说不算初始化，可以在private里面直接赋值，或者在该函数后面，如：AItem::AItem():Amplitude(0.25f)
}
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	
}

float AItem::TransformedSin() //正弦函数转化
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}




void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);//得到物品位置与原点零向量的值，找到中点。ZeroVector为FVector自带，不用创建物品。
	DRAW_POINT_SingleFrame(AvgVector); //在中点创造一个点。

}

