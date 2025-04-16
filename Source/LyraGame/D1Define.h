#pragma once

UENUM(BlueprintType)
enum class ECharacterSkinType : uint8
{
	Asian,
	Black,

	Count UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EArmorType : uint8
{
	Helmet,
	Chest,
	Legs,
	Hands,
	Foot,

	Count	UMETA(Hidden)
};