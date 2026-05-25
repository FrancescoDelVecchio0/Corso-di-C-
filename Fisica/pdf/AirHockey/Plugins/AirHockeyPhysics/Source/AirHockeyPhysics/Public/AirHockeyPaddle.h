#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AirHockeyPaddle.generated.h"

class UCapsuleComponent;
class StaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AIRHOCKEYPHYSICS_API AAirHockeyPaddle : public APawn
{
	GENERATED_BODY()

public:

	AAirHockeyPaddle();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(Category = "Paddle", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCapsuleComponent>		CapsuleComponent;
	UPROPERTY(Category = "Paddle", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent>	StaticMeshComponent;

	UPROPERTY(Category = "Paddle", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent>		SpringArmComponent;
	UPROPERTY(Category = "Paddle", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent>		CameraComponent;
};
