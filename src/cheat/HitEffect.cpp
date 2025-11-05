#include <pch.h>
#include <appdata/helpers.h>
#include "HitEffect.h"

namespace cheat::feature
{
	static bool AdventureActor_OnHitActor_Hook(app::AdventureActor* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method);
	static bool AreaEffectEntity_OnHitActor_Hook(app::AreaEffectEntity* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* entity, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method);
	static bool AreaEffect_AttackComponent_OnHitActor_Hook(app::AreaEffect_AttackComponent* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* entity, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method);
	static bool AdventureWeapon_OnHitActor_Hook(app::AdventureWeapon* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method);
	static bool AdventureBullet_OnHitActor_Hook(app::AdventureBulletBase* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method);

	HitEffect& HitEffect::GetInstance()
	{
		static HitEffect instance;
		return instance;
	}

	HitEffect::HitEffect() : Feature(),
		f_GodMode(false),
		f_MultiHit(false),
		f_MultiHitMultiplier(2)
	{
		HookManager::install(app::AdventureActor_OnHitActor, AdventureActor_OnHitActor_Hook);
		HookManager::install(app::AreaEffectEntity_OnHitActor, AreaEffectEntity_OnHitActor_Hook);
		HookManager::install(app::AreaEffect_AttackComponent_OnHitActor, AreaEffect_AttackComponent_OnHitActor_Hook);
		HookManager::install(app::AdventureWeapon_OnHitActor, AdventureWeapon_OnHitActor_Hook);
		HookManager::install(app::AdventureBullet_OnHitActor, AdventureBullet_OnHitActor_Hook);
	}

	const FeatureGUIInfo& HitEffect::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Hit Effect", "Player", true };
		return info;
	}

	void HitEffect::DrawMain()
	{
		ImGui::Checkbox("God Mode", &f_GodMode);
		ImGui::Checkbox("Multi Hit", &f_MultiHit);
		ImGui::SameLine();
		ImGui::SliderInt("##MultiHit", &f_MultiHitMultiplier, 2, 50, "%d", ImGuiInputTextFlags_EnterReturnsTrue);
	}

	static bool isPlayer(app::LogicEntity* actor) {
		auto adventurePlayerController = GET_SINGLETON(AdventurePlayerController);
		if (adventurePlayerController == nullptr)
			return false;

		if ((app::LogicEntity*)adventurePlayerController->fields._activedPlayerActor == actor)
			return true;

		return false;
	}

	static bool AdventureActor_OnHitActor_Hook(app::AdventureActor* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method)
	{
		auto& hitEffect = HitEffect::GetInstance();

		if (hitEffect.f_GodMode && isPlayer(actor)) {
			*damaged = false;
			return false;
		}

		if (hitEffect.f_MultiHit && !isPlayer(actor)) {
			for (int i = 0; i < hitEffect.f_MultiHitMultiplier; i++) {
				CALL_ORIGIN(AdventureActor_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
			}

			*damaged = true;
			return true;
		}

		return CALL_ORIGIN(AdventureActor_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
	}

	static bool AreaEffectEntity_OnHitActor_Hook(app::AreaEffectEntity* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* entity, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method)
	{
		auto& hitEffect = HitEffect::GetInstance();
		if (hitEffect.f_GodMode && isPlayer(entity)) {
			*damaged = false;
			return false;
		}

		if (hitEffect.f_MultiHit && !isPlayer(entity)) {
			for (int i = 0; i < hitEffect.f_MultiHitMultiplier; i++) {
				CALL_ORIGIN(AreaEffectEntity_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, entity, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
			}

			*damaged = true;
			return true;
		}

		return CALL_ORIGIN(AreaEffectEntity_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, entity, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
	}

	static bool AreaEffect_AttackComponent_OnHitActor_Hook(app::AreaEffect_AttackComponent* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* entity, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method)
	{
		auto& hitEffect = HitEffect::GetInstance();
		if (hitEffect.f_GodMode && isPlayer(entity)) {
			*damaged = false;
			return false;
		}

		if (hitEffect.f_MultiHit && !isPlayer(entity)) {
			for (int i = 0; i < hitEffect.f_MultiHitMultiplier; i++) {
				CALL_ORIGIN(AreaEffect_AttackComponent_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, entity, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
			}

			*damaged = true;
			return true;
		}

		return CALL_ORIGIN(AreaEffect_AttackComponent_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, entity, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
	}

	static bool AdventureWeapon_OnHitActor_Hook(app::AdventureWeapon* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method)
	{
		auto& hitEffect = HitEffect::GetInstance();

		if (hitEffect.f_GodMode && isPlayer(actor)) {
			*damaged = false;
			return false;
		}

		if (hitEffect.f_MultiHit && !isPlayer(actor)) {
			for (int i = 0; i < hitEffect.f_MultiHitMultiplier; i++) {
				CALL_ORIGIN(AdventureWeapon_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
			}

			*damaged = true;
			return true;
		}
		return CALL_ORIGIN(AdventureWeapon_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
	}

	static bool AdventureBullet_OnHitActor_Hook(app::AdventureBulletBase* __this, app::HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, app::LogicEntity* actor, app::DeterministicRaycastHit* raycastHit, bool* damaged, app::GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method)
	{
		auto& hitEffect = HitEffect::GetInstance();

		if (hitEffect.f_GodMode && isPlayer(actor)) {
			*damaged = false;
			return false;
		}

		if (hitEffect.f_MultiHit && !isPlayer(actor)) {
			for (int i = 0; i < hitEffect.f_MultiHitMultiplier; i++) {
				CALL_ORIGIN(AdventureBullet_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
			}

			*damaged = true;
			return true;
		}
		return CALL_ORIGIN(AdventureBullet_OnHitActor_Hook, __this, hitBox, uniqueAttackId, onceAttackTargetCount, actor, raycastHit, damaged, hurtEffectPrefab, isHittedEffectScale, effectIgnoreTimeScale, method);
	}
}