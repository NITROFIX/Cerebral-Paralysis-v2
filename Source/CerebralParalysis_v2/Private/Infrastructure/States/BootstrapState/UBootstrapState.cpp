
#include "Infrastructure/States/BootstrapState/UBootstrapState.h"

#include "Infrastructure/MainGameInstance.h"
#include "Infrastructure/Subsystems/LoadLevelSubsystem.h"

void UBootstrapState::Enter()
{
	IState::Enter();
	
	UGameInstance* GameInstance = CurrentWorld->GetGameInstance();
	UMainGameInstance* MainGameInstance = Cast<UMainGameInstance>(GameInstance);
	UGameStateMachine* GameStateMachine = MainGameInstance->GetGameStateMachina();
	
	ConstructSubsystems(GameInstance);

	GameStateMachine->Enter<ULoadLevelState>();
}

void UBootstrapState::ConstructSubsystems(const UGameInstance* GameInstance) const
{
	GameInstance->GetSubsystem<ULoadLevelSubsystem>()->Construct(CurrentWorld);
}

void UBootstrapState::Exit()
{
	IExitableState::Exit();

	UE_LOG(LogTemp, Warning, TEXT("Exited bootstrap state"));
}
