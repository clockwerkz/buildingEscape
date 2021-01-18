// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);

	
	float newYawRotation = FMath::Lerp(GetOwner()->GetActorRotation().Yaw, TargetYaw, 0.1f);
	GetOwner()->SetActorRotation({0.f, newYawRotation, 0.f});
	// FRotator CurrentRotation = GetOwner()->GetActorRotation();
	// CurrentRotation.Yaw = -90.f;
	// FRotator OpenDoor{0.f, -90.f, 0.f};
	// GetOwner()->SetActorRotation(OpenDoor);
	// ...
}
