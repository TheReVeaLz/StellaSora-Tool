// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.3.0 - 2023.1.99

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************

using namespace app;

// God Mode & Hit effect
DO_APP_FUNC(0x012106B0, bool, AdventureActor_OnHitActor, (AdventureActor* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x01599D00, List_1_LogicEntity_*, AdventureModuleController_get_playerActors, (AdventureModuleController* __this, MethodInfo* method));
DO_APP_FUNC(0x0158D100, List_1_LogicEntity_*, AdventureModuleController_get_monsterActors, (AdventureModuleController* __this, MethodInfo* method));
DO_APP_FUNC(0x0165A340, bool, AreaEffectEntity_OnHitActor, (AreaEffectEntity* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* entity, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x016605A0, bool, AreaEffect_AttackComponent_OnHitActor, (AreaEffect_AttackComponent* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* entity, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x016A4390, bool, AdventureWeapon_OnHitActor, (AdventureWeapon* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x0168a870, bool, AdventureBullet_OnHitActor, (AdventureBulletBase* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));

// No Cooldown
DO_APP_FUNC(0x01474580, void, PlayerSkillCd_ReduceSkillSection, (PlayerSkillCd* __this, int32_t skillId, bool beginResume, MethodInfo* method));
DO_APP_FUNC(0x01474CE0, void, PlayerSkillCd_ResetUseInterval, (PlayerSkillCd* __this, int32_t skillId, MethodInfo* method));

// Unlimited Energy
DO_APP_FUNC(0x01472320, void, PlayerSkillCd_ClearEnergy, (PlayerSkillCd* __this, MethodInfo* method));
DO_APP_FUNC(0x0147BCE0, void, SkillInfo_set_currentEnergy, (SkillInfo* __this, FP value, MethodInfo* method));
DO_APP_FUNC(0x0147BCA0, int32_t, SkillInfo_get_totalEnergy, (SkillInfo* __this, MethodInfo* method));
DO_APP_FUNC(0x011CB720, void, AdventureSkill_InitSkill, (AdventureSkill* __this, int32_t skillId, GameObject* owner, List_1_UnityEngine_GameObject_* targets, SkillLauncherType__Enum skillLauncherType, bool isInterruptAttack, bool isBreakable, SkillPhaseFeatureFlag__Enum skillCastBehaviourType, SkillCountdownTiming__Enum countdownTiming, Action_1_Boolean_* finishCallback, Action_1_TrueSync_FP_* beginCDForMonsterCallback, bool ingoreCDAndEnergy, MethodInfo* method));
DO_APP_FUNC(0x01335290, iFP, AttributeList_GetAttributeValue, (AttributeList* __this, GameEnum_effectAttributeType__Enum type, MethodInfo* method));

DO_APP_FUNC(0x051FF150, FP, FP_op_Implicit, (int32_t value, MethodInfo* method));

// Singleton
DO_APP_FUNC(0x00014840, void*, Singleton_GetInstance, (MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x06F52CD8, Singleton_1_AdventureModuleController__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x06F3C898, Singleton_1_AdventurePlayerController__get_Instance__MethodInfo);