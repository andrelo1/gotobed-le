#include "util.h"
#include "windows.h"

namespace util
{
	void report_and_fail(std::string_view a_msg, std::source_location a_loc)
	{
		auto file = std::filesystem::path(a_loc.file_name()).filename().string();
		auto msg = fmt::format("{}({}:{}): {}", file, a_loc.line(), a_loc.column(), a_msg);

		spdlog::critical(msg);
		MessageBoxA(nullptr, msg.c_str(), Version::PROJECT, 0);
		TerminateProcess(GetCurrentProcess(), EXIT_FAILURE);
	}
}