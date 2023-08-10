// Cerebral Paralysis... Think twice ;)


#include "Infrastructure/Subsystems/Generic/CursorHandlerSubsystem.h"

void UCursorHandlerSubsystem::ShowCursor(APlayerController* PlayerController) const
{
	PlayerController->SetShowMouseCursor(true);
}

void UCursorHandlerSubsystem::HideCursor(APlayerController* PlayerController) const
{
	PlayerController->SetShowMouseCursor(false);
}
