// Cerebral Paralysis... Think twice ;)


#include "AI/Tasks/AdvancedMoveToTask.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


EBTNodeResult::Type UAdvancedMoveToTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController == nullptr)
		return EBTNodeResult::Failed;

	APawn* ControlledPawn = AIController->GetPawn();
	if (ControlledPawn == nullptr)
		return EBTNodeResult::Failed;

	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (BlackboardComponent == nullptr)
		return EBTNodeResult::Failed;

	const ACharacter* MyCharacter = Cast<ACharacter>(ControlledPawn);
	if (MyCharacter == nullptr)
		return EBTNodeResult::Failed;

	const FVector TargetLocation = BlackboardComponent->GetValueAsVector(TargetLocationKey.SelectedKeyName);
	if (!TargetLocation.IsNearlyZero())
	{
		AIController->MoveToLocation(TargetLocation, AcceptanceRadius);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
