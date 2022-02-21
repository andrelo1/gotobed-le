#pragma once

namespace jc::JMap
{
	std::int32_t					object(void* a_domain);
	std::int32_t					getInt(void* a_domain, std::int32_t a_obj, BSFixedString a_key, std::int32_t a_default = 0);
	float							getFlt(void* a_domain, std::int32_t a_obj, BSFixedString a_key, float a_default = 0.0f);
	BSFixedString					getStr(void* a_domain, std::int32_t a_obj, BSFixedString a_key, BSFixedString a_default = "");
	std::int32_t					getObj(void* a_domain, std::int32_t a_obj, BSFixedString a_key, std::int32_t a_default = 0);
	TESForm*						getForm(void* a_domain, std::int32_t a_obj, BSFixedString a_key, TESForm* a_default = nullptr);
	void							setInt(void* a_domain, std::int32_t a_obj, BSFixedString a_key, std::int32_t a_value);
	void							setFlt(void* a_domain, std::int32_t a_obj, BSFixedString a_key, float a_value);
	void							setStr(void* a_domain, std::int32_t a_obj, BSFixedString a_key, BSFixedString a_value);
	void							setObj(void* a_domain, std::int32_t a_obj, BSFixedString a_key, std::int32_t a_container);
	void							setForm(void* a_domain, std::int32_t a_obj, BSFixedString a_key, TESForm* a_value);
	bool							hasKey(void* a_domain, std::int32_t a_obj, BSFixedString a_key);
	std::int32_t					valueType(void* a_domain, std::int32_t a_obj, BSFixedString a_key);
	std::int32_t					allKeys(void* a_domain, std::int32_t a_obj);
	std::vector<BSFixedString>		allKeysPArray(void* a_domain, std::int32_t a_obj);
	std::int32_t					allValues(void* a_domain, std::int32_t a_obj);
	bool							removeKey(void* a_domain, std::int32_t a_obj, BSFixedString a_key);
	std::int32_t					count(void* a_domain, std::int32_t a_obj);
	void							clear(void* a_domain, std::int32_t a_obj);
	void							addPairs(void* a_domain, std::int32_t a_obj, std::int32_t a_source, bool a_overrideDuplicates);
	BSFixedString					nextKey(void* a_domain, std::int32_t a_obj, BSFixedString a_previousKey = "", BSFixedString a_endKey = "");
	BSFixedString					getNthKey(void* a_domain, std::int32_t a_obj, std::int32_t a_keyIndex);
}