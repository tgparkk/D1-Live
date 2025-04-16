// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h" // 필수적일때만 넣죠.
#include "D1Define.h"
#include "Engine/DataAsset.h"
#include "D1CharacterData.generated.h"

USTRUCT(BlueprintType) // USRUCT 는 블루프린트 에서 사용하기 위한 구조체 정의 이름
struct FD1DefaultArmorMeshSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UMaterialInterface> UpperBodySkinMaterial;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UMaterialInterface> LowerBodySkinMaterial;

public:
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<USkeletalMesh> HeadDefaultMesh;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<USkeletalMesh> HeadSecondaryMesh;

public:
	UPROPERTY(EditDefaultsOnly, meta = (ArraySizeEnum = "EArmorType"))
	TSoftObjectPtr<USkeletalMesh> DefaultMeshEntries[(int32)EArmorType::Count];

	UPROPERTY(EditDefaultsOnly, meta = (ArraySizeEnum = "EArmorType"))
	TSoftObjectPtr<USkeletalMesh> SecondaryMeshEntries[(int32)EArmorType::Count];
};

/**
 * 
 */
UCLASS()
class LYRAGAME_API UD1CharacterData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	static const UD1CharacterData& Get();

public:
#if WITH_EDITOR // 에디터에서만 사용되는 코드
	virtual void PreSave(FObjectPreSaveContext ObjectSaveContext) override;
#endif // WITH_EDITOR

public:
	const FD1DefaultArmorMeshSet& GetDefaultArmorMeshSet(ECharacterSkinType CharacterSkinType) const;

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<ECharacterSkinType, FD1DefaultArmorMeshSet> DefaultArmorMeshMap;
};
