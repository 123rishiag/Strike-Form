// Strike Form

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class STRIKEFORM_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(
		const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(
	const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, 
	ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input Config Data Asset is null, cannot proceed with binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
