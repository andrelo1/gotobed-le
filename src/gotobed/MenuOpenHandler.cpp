#include "MenuOpenHandler.h"
#include "Offsets.h"

namespace Gotobed
{
	namespace
	{
		std::uintptr_t	ProcessButtonAddr{ 0 };
		
		template<class... Args>
		bool ShowMessageBox(const char* a_msg, void (*a_callback)(std::uint8_t), std::uint8_t a_unk3, std::uint32_t a_unk4, std::uint32_t a_unk5, Args... a_args)
		{
			using func_t = decltype(&ShowMessageBox<Args...>);
			auto func = reinterpret_cast<func_t>(Offsets::ShowMessageBox);
			return func(a_msg, a_callback, a_unk3, a_unk4, a_unk5, a_args...);
		}
		
		void ShowSleepWaitMenu(bool a_sleep)
		{
			using func_t = decltype(&ShowSleepWaitMenu);
			auto func = reinterpret_cast<func_t>(Offsets::ShowSleepWaitMenu);
			func(a_sleep);
		}
	}

	bool MenuOpenHandler::ProcessButton_Original(ButtonEvent* a_event)
	{
		using func_t = decltype(&MenuOpenHandler::ProcessButton_Original);
		auto func = reinterpret_cast<func_t&>(ProcessButtonAddr);
		return (this->*func)(a_event);
	}

	bool MenuOpenHandler::ProcessButton_Hook(ButtonEvent* a_event)
	{
		if (a_event) {
			if (a_event->controlID == "Wait") {
				if (a_event->flags && a_event->timer == 0.0f) {
					if (ProcessWaitButton()) {
						auto unk_1B3FCA8 = reinterpret_cast<std::uint8_t*>(Offsets::unk_1B3FCA8);
						*unk_1B3FCA8 = true;
						return true;
					}
				}
			}
		}

		return ProcessButton_Original(a_event);
	}

	bool MenuOpenHandler::ProcessWaitButton()
	{
		auto ui = MenuManager::GetSingleton();
		auto uiStringHolder = UIStringHolder::GetSingleton();

		if (ui->unk_0C8 || ui->IsMenuOpen(&uiStringHolder->faderMenu)) {
			return false;
		}
		
		auto player = *g_thePlayer;

		if ((player->actorState.flags04 >> 0x15 & 0xF) == 1 || (player->actorState.flags04 >> 0x15 & 0xF) == 2) {
			return false;
		}

		if (*reinterpret_cast<std::int32_t*>(reinterpret_cast<std::uint8_t*>(player) + 0x430) > 0 && (*(reinterpret_cast<std::uint8_t*>(player) + 0x724) & 0x40) == 0) {
			auto settings = *g_gameSettingCollection;
			auto sServeSentenceQuestion = settings->Get("sServeSentenceQuestion")->data.s;
			auto sYes = settings->Get("sYes")->data.s;
			auto sNo = settings->Get("sNo")->data.s;
			auto callback = [](std::uint8_t a_idx) {
				if (a_idx == 1) {
					(*g_thePlayer)->Unk_B9();
				}
			};

			ShowMessageBox(sServeSentenceQuestion, callback, 1, 0x19, 4, sYes, sNo, nullptr);
		} else if ((player->actorState.flags04 >> 0xE & 0xF) == 7) {
			ShowSleepWaitMenu(true);
		} else {
			return false;
		}
		
		return true;
	}

	void MenuOpenHandlerNS::Init()
	{
		ProcessButtonAddr = Offsets::MenuOpenHandler::ProcessButton;
		auto ProcessButtonHook = &MenuOpenHandler::ProcessButton_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&ProcessButtonAddr), reinterpret_cast<PVOID&>(ProcessButtonHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}