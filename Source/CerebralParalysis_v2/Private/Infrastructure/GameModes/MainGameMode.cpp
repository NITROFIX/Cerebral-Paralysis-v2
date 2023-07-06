// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/GameModes/MainGameMode.h"

#include "Infrastructure/Subsystems/Factories/PlayerFactorySubsystem.h"
#include "Pawns/Hero/HeroCharacter.h"

APawn* AMainGameMode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
	return GetWorld()->GetGameInstance()->GetSubsystem<UPlayerFactorySubsystem>()->SpawnPlayer(
		DefaultPawnClass,
		StartSpot);
	
}
