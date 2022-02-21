#include "skseapi.h"

namespace SKSE
{
	namespace detail
	{
		struct APIStorage
		{
		public:
			static APIStorage& get()
			{
				static APIStorage singleton;
				return singleton;
			}

			PluginHandle	pluginHandle{ static_cast<PluginHandle>(kPluginHandle_Invalid) };
			std::uint32_t	releaseIndex{ 0 };

			SKSEScaleformInterface*		scaleformInterface{ nullptr };
			SKSEPapyrusInterface*		papyrusInterface{ nullptr };
			SKSESerializationInterface*	serializationInterface{ nullptr };
			SKSETaskInterface*			taskInterface{ nullptr };
			SKSEMessagingInterface*		messagingInterface{ nullptr };
		};

		template<class T>
		T* QueryInterface(const SKSEInterface* a_intfc, std::uint32_t a_id)
		{
			auto result = static_cast<T*>(a_intfc->QueryInterface(a_id));
			if (result && result->interfaceVersion > T::kInterfaceVersion) {
				spdlog::warn("interface (%d) definition is out of date", a_id);
			}
			return result;
		}
	}

	void Init(const SKSEInterface* a_intfc)
	{
		if (!a_intfc) {
			util::report_and_fail("interface is null"sv);
		}

		auto& storage = detail::APIStorage::get();

		storage.pluginHandle = a_intfc->GetPluginHandle();
		storage.releaseIndex = a_intfc->GetReleaseIndex();

		storage.scaleformInterface = detail::QueryInterface<SKSEScaleformInterface>(a_intfc, kInterface_Scaleform);
		storage.papyrusInterface = detail::QueryInterface<SKSEPapyrusInterface>(a_intfc, kInterface_Papyrus);
		storage.serializationInterface = detail::QueryInterface<SKSESerializationInterface>(a_intfc, kInterface_Serialization);
		storage.taskInterface = detail::QueryInterface<SKSETaskInterface>(a_intfc, kInterface_Task);
		storage.messagingInterface = detail::QueryInterface<SKSEMessagingInterface>(a_intfc, kInterface_Messaging);
	}

	PluginHandle GetPluginHandle()
	{
		return detail::APIStorage::get().pluginHandle;
	}

	std::uint32_t GetReleaseIndex()
	{
		return detail::APIStorage::get().releaseIndex;
	}

	const SKSEScaleformInterface* GetScaleformInterface()
	{
		return detail::APIStorage::get().scaleformInterface;
	}

	const SKSEPapyrusInterface* GetPapyrusInterface()
	{
		return detail::APIStorage::get().papyrusInterface;
	}

	const SKSESerializationInterface* GetSerializationInterface()
	{
		return detail::APIStorage::get().serializationInterface;
	}

	const SKSETaskInterface* GetTaskInterface()
	{
		return detail::APIStorage::get().taskInterface;
	}

	const SKSEMessagingInterface* GetMessagingInterface()
	{
		return detail::APIStorage::get().messagingInterface;
	}
}