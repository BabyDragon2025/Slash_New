// Fill out your copyright notice in the Description page of Project Settings.

#pragma once//避免重复包含头文件

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"//因为AActor继承与Actor，要使用Actor内容要记得包含它的头文件。
#include "Item.generated.h"

UCLASS()
class SLASH_NEW_API AItem : public AActor
{
	GENERATED_BODY()  //理解为一个功能增强的普通C++类，它能参与虚幻引擎的幕后工作，从而与ue的反射系统连接。作用：可以基于这个类创建蓝图，把属性暴露给蓝图等等。
		
	
public:	
	// Sets default values for this actor's properties
	AItem();
	virtual void Tick(float DeltaTime) override;
protected:
	// Called（调用） when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")//BlueprintReadOnly等不可放到私有对象里面。
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")//加上Category可进行分类，不加则不分类,这种暴露函数结尾无分号.
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure) //暴露函数给蓝图，注意不要加分号。
	float TransformedSin();//正弦函数

	UFUNCTION(BlueprintPure)
	float TransformedCosin(); // 余弦函数

	template<typename T> //建立模板函数，T可以自动成为任何合适的类型,取决与你定义的参数类型。
	T Avg(T First, T Second);//平均函数。鼠标执行创建模板函数。当然你选择的变量要支持加减乘除，比如FRotato旋转器就不可以作为参数进入。
	
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess="true"))//你可以通过一些方法在private里面使用BlueprintReadOnly等
	//加入这个元指定符meta=(AllowPrivateAccess="true")，事件列表也可以访问私有变量
	float RunningTime;

	
};

template<typename T>
inline T AItem::Avg(T First, T Second) //内联函数，在编译时，函数调用将被函数体替换像宏一样。
{
	return (First + Second) / 2;
}
