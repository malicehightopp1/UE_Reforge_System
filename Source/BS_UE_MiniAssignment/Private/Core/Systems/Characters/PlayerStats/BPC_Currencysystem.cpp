// Brandin stanfield

#include "Core/Systems/Characters/PlayerStats/BPC_Currencysystem.h"

UBPC_Currencysystem::UBPC_Currencysystem()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	PlayerCurrentCurrency = 0;
	PlayerMaxCurrency = 999;
}
void UBPC_Currencysystem::BeginPlay()
{
	Super::BeginPlay();
	PlayerCurrentCurrency = 0;
	PlayerMaxCurrency = 100;
	OnCurrencyChange.Broadcast(PlayerCurrentCurrency); //initial broadcast to set default value
}
// Called every frame
void UBPC_Currencysystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
void UBPC_Currencysystem::ChangePlayerCurrencey(float CurrencyTochange)
{
	UE_LOG(LogTemp, Warning, TEXT("Currency changed To: %f"), PlayerCurrentCurrency);
	PlayerCurrentCurrency = FMath::Clamp(PlayerCurrentCurrency + CurrencyTochange, 0, PlayerMaxCurrency);

	if (OnCurrencyChange.IsBound())
	{
		UE_LOG(LogTemp, Warning , TEXT("Ui updated"));
		OnCurrencyChange.Broadcast(PlayerCurrentCurrency); //telling UI that the value changed
	}
}