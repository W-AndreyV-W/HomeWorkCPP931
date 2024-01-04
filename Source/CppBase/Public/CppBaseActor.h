#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

USTRUCT(BlueprintType) struct FTransformStruct {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector CurrentLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FRotator CurrentRotation = FRotator::ZeroRotator;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

class UStaticMeshComponent;

UENUM(BlueprintType) enum class EMovementState : uint8 {

	Mobility,
	Static
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor {

	GENERATED_BODY()
	
public:	

	ACppBaseActor();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* mesh;

protected:

	UPROPERTY(EditAnywhere) float amplitude = 70.0f;
	UPROPERTY(EditAnywhere) float frequency = 4.0f;
	UPROPERTY(BlueprintReadWrite) FVector initialLocation;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable) float SinMovement(float timeSeconds);

public:	

	virtual void Tick(float DeltaTime) override;

private:

};
