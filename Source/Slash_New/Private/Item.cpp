// Fill out your copyright notice in the Description page of Project Settings.



#include "Item.h"
#include "Slash_New/DebugMacros.h"  //该头文件路径位于模块Slash_New的public下，所以，要（模块/.h）来包含



// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));//创建UStaticMeshComponent类型对象，并让ItemMesh指向它。
	//TEXT("ItemMeshComponent")->ItemMeshComponent为该组件名称
	RootComponent = ItemMesh; //让根组件指针指向ItemMesh，原本的RootComponent因为空了，会被虚幻自动回收。
	
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
	

}

