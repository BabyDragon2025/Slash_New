// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"// 胶囊体头文件
#include "Components/SkeletalMeshComponent.h"//骨骼网络体头文件

ABird::ABird()  
{
 	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));//创建胶囊体并且命名
	Capsule->SetCapsuleHalfHeight(20.f);//设置胶囊体高度
	Capsule->SetCapsuleRadius(15.f);//设置胶囊体半径
	SetRootComponent(Capsule);// 相当于RootComponent = Capsule;修改默认根组件。

	BirdMesh= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());//把鸟的模型附加到根组件————胶囊体上。

	AutoPossessPlayer = EAutoReceiveInput::Player0;//EAutoReceiveInput自动控制玩家的类型，这里控制玩家0，也就是我们自己。
}


void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::MoveForward(float Value)
{
	//用UE日志测试一下输入键
	UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
}


void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);  

	//前进函数绑定到前进轴的映射上，参数为：轴映射名字设为MoveForward，this代表该鸟对象，回调函数地址）
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABird::MoveForward); 
}

