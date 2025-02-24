// Blur Feng All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlurPawnComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLURARPGFRAMEWORK_API UBlurPawnComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBlurPawnComponentBase();
	
protected:

	// Notes：static_assert子父类确认断言。
	// static_assert 是 C++11 引入的一种编译时断言机制，用于在编译时验证某些条件是否为真。
	// 它是一种编译时检查机制，能够有效地保证模板参数的合法性，避免无效类型导致的运行时错误。
	// 在UE中，我们配合 TPointerIsConvertibleFromTo<T, APawn>::Value 代码检查 T 是否派生自要求的类型。
	
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' Template Parameter to GetPawn must be derived from APawn.");
		return CastChecked<T>(GetOwner());
	}

	/// 获取拥有者Pawn。
	/// @return 
	APawn* GetOwningPawn() const;

	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter to GetController must be derived from AController.");
		return GetOwningPawn<APawn>()->GetController<T>();
	}

	/// 获取拥有者Controller。
	/// @return 
	AController* GetOwningController() const;
};
