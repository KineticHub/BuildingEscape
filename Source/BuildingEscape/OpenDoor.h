// Copyright ShiftingDiscord 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();
	void CloseDoor();

private:
    UPROPERTY(EditAnywhere) float OpenAngle = 90.0f;
    UPROPERTY(EditAnywhere) ATriggerVolume* DoorClosePressurePlate;
	UPROPERTY(EditAnywhere) ATriggerVolume* DoorOpenPressurePlate;
	UPROPERTY(EditAnywhere) AActor* PressurePlateWeightObject;
    
	AActor* Owner; // this is the current door object
	AActor* PawnActor;  // remember pawn inherits from actor, so could use APawn
};
