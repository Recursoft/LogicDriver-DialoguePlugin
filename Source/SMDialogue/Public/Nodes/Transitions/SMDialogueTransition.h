// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "SMTransitionInstance.h"
#include "SMDialogueTransition.generated.h"


UCLASS(Blueprintable, BlueprintType, classGroup = "Dialogue (SM Extended)", hideCategories = (SMDialogueTransition), meta = (DisplayName = "Dialogue Transition"))
class SMDIALOGUE_API USMDialogueTransition : public USMTransitionInstance
{
public:
	GENERATED_BODY()

	USMDialogueTransition();
	
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	bool IsGoingToChoiceNode() const;

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	bool IsLeavingChoiceNode() const;

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	bool IsGoingToDialogueNode(bool bIncludeChoiceAsDialogue = true) const;
	
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	bool IsLeavingDialogueNode(bool bIncludeChoiceAsDialogue = true) const;

	/* Should be called when a dialogue is updated. Recommended usage is binding to an event. Override for custom implementations. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Dialogue")
	void OnDialogueUpdated();
protected:
	void OnTransitionInitialized_Implementation() override;
	bool CanEnterTransition_Implementation() const override;
	void OnTransitionEntered_Implementation() override;

	virtual void OnDialogueUpdated_Implementation();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	bool bCanGoToNextDialogue;
};