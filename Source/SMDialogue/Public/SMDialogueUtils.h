// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#pragma once
#include "SMDialogueNode.h"
#include "SMDialogueUtils.generated.h"


UCLASS()
class SMDIALOGUE_API USMDialogueUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Get all dialogue nodes that are connected to each other starting with the FromNode.
	 * @param FromNode The node to start the search from.
	 * @param OutDialogueNodes All connected nodes.
	 * @param bBreakOnChoices If choice nodes should break the search.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Logic Driver|Dialogue Utilities")
	static void GetAllConnectedDialogueNodes(const USMStateInstance_Base* FromNode, TArray<USMDialogueNode*>& OutDialogueNodes, bool bBreakOnChoices = false);

};