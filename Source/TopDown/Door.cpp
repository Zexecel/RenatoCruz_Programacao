// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = RootSceneComponent;

	DoorLeft = CreateDefaultSubobject<UStaticMeshComponent>("DoorLeft");
	DoorLeft->SetupAttachment(GetRootComponent());

	DoorRight = CreateDefaultSubobject<UStaticMeshComponent>("DoorRight");
	DoorRight->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	DoorLeftInitialLocation = DoorLeft->GetRelativeLocation().X;
	DoorRightInitialLocation = DoorRight->GetRelativeLocation().X;
	
	CurrentOffset = 0;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	
	CurrentOffset = FMath::FInterpConstantTo(CurrentOffset, DoorOpened? 100 : 0, DeltaTime, 150);

	FString FloatAsString = FString::SanitizeFloat(CurrentOffset);
	
	DoorLeft->SetRelativeLocation(FVector(DoorLeftInitialLocation-CurrentOffset,0,-1));
	DoorRight->SetRelativeLocation(FVector(DoorRightInitialLocation+CurrentOffset,0,-1));
	
	
}

void ADoor::Interact()
{
	DoorOpened = !DoorOpened;
	
}

