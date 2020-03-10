// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "SMStateInstance.h"
#include "SMTextGraphProperty.h"
#include "SMDialogueNode.generated.h"

UCLASS(meta = (DisplayName = "Dialogue Node Base"))
class SMDIALOGUE_API USMDialogueNode_Base : public USMStateInstance
{
public:
	GENERATED_BODY()

	USMDialogueNode_Base();

	/* Evaluates the dialogue graph and returns formatted text. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Dialogue")
	const FText& GetDialogueText() const;

	/* The speaker this dialogue belongs to. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "Dialogue")
	UObject* GetDialogueSpeaker() const;

	/* Set from previous node during transition. */
	void SetPreviousDialogueSpeaker(UObject* Speaker);

protected:
	virtual UObject* GetDialogueSpeaker_Implementation() const;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Dialogue")
	FSMTextGraphProperty DialogueBody;

	UPROPERTY()
	UObject* PreviousDialogueSpeaker;
};


UCLASS(Blueprintable, BlueprintType, classGroup = "Dialogue (SM Extended)", hideCategories = (SMDialogueNode), meta = (DisplayName = "Dialogue Node"))
class SMDIALOGUE_API USMDialogueNode : public USMDialogueNode_Base
{
public:
	GENERATED_BODY()

	USMDialogueNode();

	/* Iterates over all transitions out leading to dialogue choices and evaluates them determining which choices are visible. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Dialogue")
	virtual void GetAvailableChoices(TArray<class USMDialogueChoiceNode*>& Choices);

	/* Select the given choice and move to the next node. */
	virtual void SelectChoice(class USMDialogueChoiceNode* Choice);

	/* Get all dialogue nodes in the hierarchy starting from this node. */
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void GetAllDialogueNodes(TArray<USMDialogueNode*>& OutDialogueNodes) const;

	/**
	 * Get all dialogue nodes that are connected to each other starting with this node.
	 * @param OutDialogueNodes All connected nodes.
	 * @param bBreakOnChoices If choice nodes should break the search.
	 */
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void GetAllConnectedDialogueNodes(TArray<USMDialogueNode*>& OutDialogueNodes, bool bBreakOnChoices = false) const;

	/**
	 * Get all speaker objects for dialogues.
	 * @param Speakers All found speakers.
	 * @param bConnectedOnly If only dialogue nodes connected to each other should be checked.
	 * @param bBreakOnChoices If choice nodes should break the search.
	 */
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void GetAllDialogueSpeakers(TArray<UObject*>& Speakers, bool bConnectedOnly = true, bool bBreakOnChoices = false) const;

protected:
	virtual void OnStateBegin_Implementation() override;
	virtual void OnStateUpdate_Implementation(float DeltaSeconds) override;
	virtual void OnStateEnd_Implementation() override;
	
	UObject* GetDialogueSpeaker_Implementation() const override;
protected:
	/* If no speaker has been set the previous speaker will be used. */
	UPROPERTY(EditAnywhere, Category = "Speaker")
	bool bUsePreviousSpeakerIfNoneSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speaker")
	UObject* Speaker;
};