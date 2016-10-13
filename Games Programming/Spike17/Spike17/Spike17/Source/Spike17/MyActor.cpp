// Fill out your copyright notice in the Description page of Project Settings.

#include "Spike17.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
