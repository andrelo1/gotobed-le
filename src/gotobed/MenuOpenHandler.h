#pragma once

namespace Gotobed
{
	struct MenuOpenHandler
	{
		bool	ProcessButton_Original(ButtonEvent* a_event);
		bool	ProcessButton_Hook(ButtonEvent* a_event);
		bool	ProcessWaitButton();
	};

	namespace MenuOpenHandlerNS
	{
		void	Init();
	}
}