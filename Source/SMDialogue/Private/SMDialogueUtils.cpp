// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#include "SMDialogueUtils.h"
#include "SMConduitInstance.h"
#include "SMDialogueChoiceNode.h"


void USMDialogueUtils::GetAllConnectedDialogueNodes(const USMStateInstance_Base* FromNode, TArray<USMDialogueNode*>& OutDialogueNodes, bool bBreakOnChoices)
{
	TArray<UClass*> RequiredTypes
	{
		USMDialogueNode::StaticClass(),
		USMConduitInstance::StaticClass()
	};

	if (!bBreakOnChoices)
	{
		RequiredTypes.Add(USMDialogueChoiceNode::StaticClass());
	}

	TArray<USMNodeInstance*> OutNodes;
	FromNode->GetAllNodesOfType(OutNodes, USMDialogueNode::StaticClass(), true, RequiredTypes);
	for (USMNodeInstance* OutNode : OutNodes)
	{
		if (USMDialogueNode* Node = Cast<USMDialogueNode>(OutNode))
		{
			OutDialogueNodes.Add(Node);
		}
	}
}
