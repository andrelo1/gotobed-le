#include "UIUtil.h"
#include "Offsets.h"

namespace Gotobed::UIUtil
{
	namespace detail
	{
		void ShowSleepWaitMenu(bool a_sleep)
		{
			using func_t = decltype(&ShowSleepWaitMenu);
			auto func = reinterpret_cast<func_t>(Offsets::ShowSleepWaitMenu);
			func(a_sleep);
		}
	}

	void ShowSleepWaitMenu(StaticFunctionTag*, bool a_sleep)
	{
		detail::ShowSleepWaitMenu(a_sleep);
	}

	void Init()
	{
		SKSE::GetPapyrusInterface()->Register([](VMClassRegistry* a_registry) {
			a_registry->RegisterFunction(new NativeFunction1<StaticFunctionTag, void, bool>("ShowSleepWaitMenu", "GTB_UIUtil", ShowSleepWaitMenu, a_registry));
			return true;
		});
	}
}