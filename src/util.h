#pragma once

namespace util
{
	void report_and_fail(std::string_view a_msg, std::source_location a_loc = std::source_location::current());
}