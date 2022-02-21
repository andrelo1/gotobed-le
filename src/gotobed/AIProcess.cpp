#include "AIProcess.h"
#include "Offsets.h"
#include "SleepwearManager.h"

namespace Gotobed
{
	namespace
	{
		std::uintptr_t SitSleepStateUpdateAddr{ 0 };
	}

	void AIProcess::SitSleepStateUpdate(::Actor* a_actor, std::uint32_t a_newState, std::uint32_t& a_refHandle, std::int32_t a_marker)
	{
		using func_t = decltype(&AIProcess::SitSleepStateUpdate);
		auto func = reinterpret_cast<func_t&>(SitSleepStateUpdateAddr);
		(this->*func)(a_actor, a_newState, a_refHandle, a_marker);
	}

	void AIProcess::SitSleepStateUpdate_Hook(::Actor* a_actor, std::uint32_t a_newState, std::uint32_t& a_refHandle, std::int32_t a_marker)
	{
		SitSleepStateUpdate(a_actor, a_newState, a_refHandle, a_marker);

		if (a_actor && !a_actor->IsInCombat()) {
			SleepwearManager::Get().UpdateOutfit(a_actor);
		}
	}

	void AIProcessNS::Init()
	{
		SitSleepStateUpdateAddr = Offsets::AIProcess::SitSleepStateUpdate;
		auto SitSleepStateUpdateHook = &AIProcess::SitSleepStateUpdate_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&SitSleepStateUpdateAddr), reinterpret_cast<PVOID&>(SitSleepStateUpdateHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}