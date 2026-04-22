// Fill out your copyright notice in the Description page of Project Settings.


#include "GASLessons/Public/GASCharacter.h"

#include "AbilitySystemGlobals.h"
#include "GameplayCueManager.h"
#include "GASNativeTags.h"
#include "AttributeSets/CharacterAttributeSet.h"
#include "Components/GASAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


AGASCharacter::AGASCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComp");
}

UAbilitySystemComponent* AGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void AGASCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//@GAS_INIT - initialization of the Ability Actor info when the Controller is bound
	//Owner Actor will be the Controller
	//Avatar actor will be the Character
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(NewController, this);
	}
}

void AGASCharacter::BeginPlay()
{
	Super::BeginPlay();

	//trigger the example Begin Play
	if (bRunExampleBeginPlay)
	{
		Example_BeginPlay();
	}
}

void AGASCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//trigger the example End Play
	if (bRunExampleEndPlay)
	{
		Example_EndPlay();
	}
	Super::EndPlay(EndPlayReason);
}

void AGASCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);

	//trigger the example OnMovementModeChanged
	Example_OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);
}

void AGASCharacter::Example_BeginPlay()
{
	//GET ABILITY SYSTEM FROM ANY ACTOR
	constexpr bool bLookForComponent = true;
	UAbilitySystemComponent* ASCFound = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(this, bLookForComponent);


	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	//--------------------@EXAMPLE_TAGS-------------------

	//check if it has a tag (for the others see the IGameplayTagAssetInterface)
	bool bIsInAir = ASC->HasMatchingGameplayTag(Tags::State::InAir.GetTag());

	//count how many tags it has with TagName
	FGameplayTag TagName = Tags::State::InAir.GetTag();
	int32 TagsCount = ASC->GetTagCount(TagName);

	//Wait Tag Added or Removed Registration
	const FGameplayTag InAirTag = Tags::State::InAir.GetTag();
	FOnGameplayEffectTagCountChanged& TagEvent = ASC->RegisterGameplayTagEvent(InAirTag, EGameplayTagEventType::NewOrRemoved);
	Example_InAirTagHandle = TagEvent.AddWeakLambda(this, [this](const FGameplayTag Tag, int32 Count)
	{
		if (Count > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("[GAS] Character %s is in air!"), *GetNameSafe(this));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("[GAS] Character %s has landed!"), *GetNameSafe(this));
		}
	});

	//!!! WARNING !!!
	// Exists also the version RegisterAndCallGameplayTagEvent
	// this one triggers the event ONLY if the TagCount is > 0
	// e.g.: if you need to call the logics in order to show/hide something
	// and the Tag Count is zero, the function isn't called,
	// and so the stuff won't be hidden


	//-------------------@EXAMPLE_ATTRIBUTES-------------------

	// Finds and returns the AttributeSet instance in the ASC
	// useful as optimization if you need to query different gameplay attributes of this attribute set
	const UAttributeSet* AttSet = ASC->GetAttributeSet(UCharacterAttributeSet::StaticClass());

	//get the GameplayAttribute via code in order to query it
	//(it is required to have the ATTRIBUTE_ACCESSOR for said attribute)
	FGameplayAttribute HealthAttribute = UCharacterAttributeSet::GetHealthAttribute();

	//check if the Attribute Set that defines the Gameplay Attribute exists in the ASC
	bool bHasAttributeSet = ASC->HasAttributeSetForAttribute(HealthAttribute);

	//get the Base Value of the GameplayAttribute
	//returns 0 if the Attribute Set isn't assigned to the Ability System Component
	float BaseHealth = ASC->GetNumericAttributeBase(HealthAttribute);

	//get the Current Value of the GameplayAttribute
	//returns 0 if the Attribute Set containing it isn't assigned to the ASC
	float CurrentHealth = ASC->GetNumericAttribute(HealthAttribute);

	//get the Current Value of the GameplayAttribute
	//forces a crash if the Attribute Set containing it isn't assigned to the ASC
	float CurrentHealth_Checked = ASC->GetNumericAttributeChecked(HealthAttribute);

	//get the Current Value of the GameplayAttribute (Safest Way)
	//returns 0 if the Attribute Set containing it isn't assigned to the ASC
	//the boolean returns if it has actually found the GameplayAttribute
	bool bHasFound;
	float CurrentHealth_Safe = ASC->GetGameplayAttributeValue(HealthAttribute, bHasFound);

	//Listen for Attribute Change Registration
	FOnGameplayAttributeValueChange& AttEvent = ASC->GetGameplayAttributeValueChangeDelegate(HealthAttribute);
	Example_HealthAttHandle = AttEvent.AddWeakLambda(this, [this](const FOnAttributeChangeData& Data)
	{
		UE_LOG(LogTemp, Warning, TEXT("[GAS] %s Health changed from %f to %f")
		       , *GetNameSafe(this), Data.OldValue, Data.NewValue);
	});

	//--------------------@EXAMPLE_EVENTS-------------------

	//send Gameplay Event
	FGameplayTag EventTag = FGameplayTag::EmptyTag; //fake gameplayTag
	FGameplayEventData Payload;
	Payload.EventTag = EventTag;
	ASC->HandleGameplayEvent(EventTag, &Payload);

	//register on Gameplay Event
	//see UAbilityTask_WaitGameplayEvent::Activate

	//--------------------@EXAMPLE_CUES-------------------

	//Gameplay Cue Parameters
	FGameplayCueParameters CueParams;
	CueParams.Instigator = this;

	//Ability System Version:
	//requires the ASC
	//The Gameplay Cue Tag will be added to the ASC Tags in case of Add-Remove
	//replicated
	//Execute Cue
	ASC->ExecuteGameplayCue(Example_CueTag.GameplayCueTag, CueParams);

	//Add Cue
	ASC->AddGameplayCue(Example_CueTag.GameplayCueTag, CueParams);

	//Remove Cue
	ASC->RemoveGameplayCue(Example_CueTag.GameplayCueTag);

	//Direct Version:
	//Non-replicated

	UGameplayCueManager* GameplayCueManager = UAbilitySystemGlobals::Get().GetGameplayCueManager();
	//Execute Cue
	GameplayCueManager->HandleGameplayCue(this, Example_CueTag.GameplayCueTag, EGameplayCueEvent::Executed, CueParams);

	//Add Cue
	GameplayCueManager->HandleGameplayCue(this, Example_CueTag.GameplayCueTag, EGameplayCueEvent::OnActive, CueParams);

	//Remove Cue
	GameplayCueManager->HandleGameplayCue(this, Example_CueTag.GameplayCueTag, EGameplayCueEvent::Removed, CueParams);

	//While Active (a sort of manual "tick" of the gameplay cue)
	GameplayCueManager->HandleGameplayCue(this, Example_CueTag.GameplayCueTag, EGameplayCueEvent::WhileActive, CueParams);

	//--------------------@EXAMPLE_ABILITY-------------------
	if (Example_GAClass)
	{
		//GIVE
		//Give a Gameplay Ability
		constexpr int32 AbilityLevel = 1;
		constexpr int32 InputID = INDEX_NONE;
		UObject* SourceObject = this;
		FGameplayAbilitySpec Spec(Example_GAClass, AbilityLevel, InputID, SourceObject);
		Example_GASpecHandle = ASC->GiveAbility(Spec);


		//Give and Execute instantly a Gameplay Ability
		//when this ability ends, will be automatically removed from ASC

		//Gameplay Event Data is intended for the abilities triggered from the Gameplay Event
		//avoid using it and keep it nullptr
		constexpr FGameplayEventData* GameplayEventData = nullptr;
		ASC->GiveAbilityAndActivateOnce(Spec, GameplayEventData);

		//ACTIVATE
		//trigger a gameplay ability from the Handle
		bool bSuccess = ASC->TryActivateAbility(Example_GASpecHandle);

		//trigger the first Gameplay Ability found with EXACTLY the class
		TSubclassOf<UGameplayAbility> FakeAbility = nullptr;
		bool bSuccessClass = ASC->TryActivateAbilityByClass(FakeAbility);

		//trigger all the abilities that match the tag container
		FGameplayTagContainer FakeTagContainer;
		if (FakeTagContainer.IsValid())
		{
			ASC->TryActivateAbilitiesByTag(FakeTagContainer);
		}

		//FIND
		//!!!WARNING!!!
		// The Find of a Gameplay Ability just given will fail due to the Scope lock!

		//Find the Gameplay Ability Spec through its handle
		{
			FGameplayAbilitySpec* ActiveSpec = ASC->FindAbilitySpecFromHandle(Example_GASpecHandle);
		}

		//Find the first Gameplay Ability Spec that matches EXACTLY the Class
		{
			FGameplayAbilitySpec* ActiveSpec = ASC->FindAbilitySpecFromClass(FakeAbility);
		}

		//Find the first Gameplay Ability Spec that matches the Input ID
		{
			int32 InputIDFake = INDEX_NONE;
			FGameplayAbilitySpec* ActiveSpec = ASC->FindAbilitySpecFromInputID(InputIDFake);

			//array version that returns all the abilities with Input ID
			TArray<FGameplayAbilitySpecHandle> OutAbilityHandles;
			ASC->FindAllAbilitiesWithInputID(OutAbilityHandles, InputIDFake);
		}

		//Find all the Gameplay Ability Specs that match the GameplayTagContainer
		{
			TArray<FGameplayAbilitySpecHandle> OutAbilityHandles;
			ASC->FindAllAbilitiesWithTags(OutAbilityHandles, FakeTagContainer);
		}

		//CANCEL AND REMOVE

		//Cancel the Gameplay Ability with this handle (forces the EndAbility)
		ASC->CancelAbilityHandle(Example_GASpecHandle);

		//Marks the ability to be removed: if the ability isn't active, it will be removed
		//otherwise it will wait the end of the ability
		//!!!BUG!!!
		//an ability in the pending adds won't be removed
		//see the fix in GASStatics::SetRemoveAbilityOnEnd
		ASC->SetRemoveAbilityOnEnd(Example_GASpecHandle);

		if (Example_GASpecHandle.IsValid())
		{
			//Forces the remove of a Gameplay Ability
			ASC->ClearAbility(Example_GASpecHandle);
			Example_GASpecHandle = FGameplayAbilitySpecHandle();
		}
	}

	//--------------------@EXAMPLE_EFFECTS-------------------

	//The Gameplay Effect is read-only! It never changes during runtime!
	TSubclassOf<UGameplayEffect> DummyGameplayEffect;

	//The FGameplayEffectContextHandle is a wrapper of a pointer that keeps
	//the FGameplayEffectContext alive while there is at least one instance of the handle
	FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext(); //default creation

	//The Gameplay Effect Spec Handle is a wrapper of a pointer that keeps
	//the Gameplay Effect Spec alive while there is at least one instance of the handle

	//The Gameplay Effect Spec is definition of the gameplay effect with runtime payload
	FGameplayEffectSpecHandle EffectSpecHandle = ASC->MakeOutgoingSpec(DummyGameplayEffect
	                                                                   , FGameplayEffectConstants::INVALID_LEVEL,
	                                                                   ContextHandle);
	//!!!TIP!!!
	//you can manually reproduce what the MakeOutgoingSpec does and avoid the FGameplayEffectSpecHandle

	//Apply the Gameplay Effect to the relative ASC
	FActiveGameplayEffectHandle ActiveEffectHandle = ASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	//Apply the Gameplay Effect from an ASC (source) to another ASC (target)
	UAbilitySystemComponent* TargetASC = nullptr;
	FActiveGameplayEffectHandle ActiveEffectHandleTarget = ASC->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), TargetASC);

	//FActiveGameplayEffectHandle is a handle that informs if the Gameplay Effect has been applied with success
	// and contains the ID of the FActiveGameplayEffect. You can use it for find it and work with it (rare, hopefully).
	//FActiveGameplayEffect is the runtime logics in execution of a Gameplay Effect Infinite or with Duration
	//inside it, you can find the FGameplayEffectSpec and query the duration


	//remove an active Gameplay Effect
	//the stack is intended for a Gameplay Effect that handles the stack
	//if -1 removes all the stacks of said GE, otherwise the amount requested
	constexpr int32 StackToRemove = -1;
	ASC->RemoveActiveGameplayEffect(ActiveEffectHandle, StackToRemove);
}

void AGASCharacter::Example_EndPlay()
{
	//--------------------@EXAMPLE_TAGS-------------------
	//Wait Tag Added or Removed Deregistration
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		if (Example_InAirTagHandle.IsValid())
		{
			const FGameplayTag InAirTag = Tags::State::InAir.GetTag();
			FOnGameplayEffectTagCountChanged& Event = ASC->RegisterGameplayTagEvent(InAirTag, EGameplayTagEventType::NewOrRemoved);
			Event.Remove(Example_InAirTagHandle);
			Example_InAirTagHandle.Reset();
		}
	}

	//-------------------@EXAMPLE_ATTRIBUTES-------------------
	//Listen for Attribute Change Deregistration
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		if (Example_HealthAttHandle.IsValid())
		{
			FOnGameplayAttributeValueChange& Event = ASC->GetGameplayAttributeValueChangeDelegate(UCharacterAttributeSet::GetHealthAttribute());
			Event.Remove(Example_HealthAttHandle);
			Example_HealthAttHandle.Reset();
		}
	}

	//--------------------@EXAMPLE_EVENTS-------------------
	//Deregister Wait for Gameplay Event
	//see UAbilityTask_WaitGameplayEvent::OnDestroy
}

void AGASCharacter::Example_OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	//--------------------@EXAMPLE_TAGS-------------------
	//OPERATIONS
	int32 TagCount = GetCharacterMovement()->IsMovingOnGround() ? 0 : 1;
	GetAbilitySystemComponent()->SetLooseGameplayTagCount(Tags::State::InAir.GetTag(), TagCount);
	
	if (!bRunExampleMovementModeFake)
	{
		return;
	}
	//ALL OTHER VARIANTS
	//single tag
	//add quantity
	GetAbilitySystemComponent()->AddLooseGameplayTag(Tags::State::InAir.GetTag(), 1);
	//remove quantity
	GetAbilitySystemComponent()->RemoveLooseGameplayTag(Tags::State::InAir.GetTag(), 1);

	//multiple tags
	//tag container
	FGameplayTagContainer ExampleContainer;
	ExampleContainer.AddTag(Tags::State::InAir.GetTag());

	//add quantity
	GetAbilitySystemComponent()->AddLooseGameplayTags(ExampleContainer, 1);
	//remove quantity
	GetAbilitySystemComponent()->RemoveLooseGameplayTags(ExampleContainer, 1);
}
