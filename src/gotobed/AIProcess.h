#pragma once

namespace Gotobed
{
	class AIProcess
	{
	public:
		void	SitSleepStateUpdate(::Actor* a_actor, std::uint32_t a_newState, std::uint32_t& a_refHandle, std::int32_t a_marker);
		void	SitSleepStateUpdate_Hook(::Actor* a_actor, std::uint32_t a_newState, std::uint32_t& a_refHandle, std::int32_t a_marker);
	};

	namespace AIProcessNS
	{
		void	Init();
	}
}