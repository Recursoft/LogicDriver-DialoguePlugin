// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#pragma once

#include "SMDialogueChoiceNode.h"

USMDialogueChoiceNode::USMDialogueChoiceNode() : Super()
{
#if WITH_EDITORONLY_DATA
	NodeDescription.Name = "Dialogue Choice";
	bDisplayNameWidget = false;
	DialogueBody.WidgetInfo.MinWidth = 75;
	DialogueBody.WidgetInfo.MinHeight = 25;
	DialogueBody.WidgetInfo.DisplayOrder = 1;
	NodeColor = FLinearColor(0.5f, 0.9f, 1.f, 0.7f);
#endif
}

void USMDialogueChoiceNode::SetCurrentDialogueOwner(USMDialogueNode* Owner)
{
	CurrentDialogueOwner = Owner;
}

void USMDialogueChoiceNode::OnStateBegin_Implementation()
{
}

void USMDialogueChoiceNode::OnStateUpdate_Implementation(float DeltaSeconds)
{
}

void USMDialogueChoiceNode::OnStateEnd_Implementation()
{
}

void USMDialogueChoiceNode::SelectChoice_Implementation()
{
	if (USMDialogueNode* Dialogue = GetCurrentDialogueOwner())
	{
		Dialogue->SelectChoice(this);
	}
}
