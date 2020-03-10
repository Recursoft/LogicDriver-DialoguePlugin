// Copyright Recursoft LLC 2019-2020. All Rights Reserved.
#include "ISMDialogueModule.h"


DEFINE_LOG_CATEGORY(SMDialogueModule)

class FSMDialogueModule : public ISMDialogueModule
{
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
};

IMPLEMENT_MODULE(FSMDialogueModule, SMDialogue)


void FSMDialogueModule::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FSMDialogueModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



