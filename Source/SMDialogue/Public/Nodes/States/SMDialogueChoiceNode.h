// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "SMDialogueNode.h"
#include "SMDialogueChoiceNode.generated.h"

UCLASS(Blueprintable, BlueprintType, classGroup = "Dialogue (SM Dialogue)", hideCategories = (SMDialogueNode), meta = (DisplayName = "Dialogue Choice Node"))
class SMDIALOGUE_API USMDialogueChoiceNode : public USMDialogueNode_Base
{
public:
	GENERATED_BODY()

	USMDialogueChoiceNode();

	/* Signals the dialogue node owner to take this choice. This can only be valid if the choice was retrieved from the dialogue node owner method GetAvailableChoices. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Dialogue")
	void SelectChoice();
	
	/* Returns the dialogue node this choice currently belongs to.
	 * This can change if more than one node leads to this choice. */
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	USMDialogueNode* GetCurrentDialogueOwner() const { return CurrentDialogueOwner; }
	void SetCurrentDialogueOwner(USMDialogueNode* Owner);

protected:
	virtual void OnStateBegin_Implementation() override;
	virtual void OnStateUpdate_Implementation(float DeltaSeconds) override;
	virtual void OnStateEnd_Implementation() override;

	virtual void SelectChoice_Implementation();

protected:
	UPROPERTY()
	USMDialogueNode* CurrentDialogueOwner;
};