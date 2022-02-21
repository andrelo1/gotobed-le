#pragma once

namespace jc::JDB
{
	float				solveFlt(void* a_domain, BSFixedString a_path, float a_default = 0.0f);
	std::int32_t		solveInt(void* a_domain, BSFixedString a_path, std::int32_t a_default = 0);
	BSFixedString		solveStr(void* a_domain, BSFixedString a_path, BSFixedString a_default = "");
	std::int32_t		solveObj(void* a_domain, BSFixedString a_path, std::int32_t a_default = 0);
	TESForm*			solveForm(void* a_domain, BSFixedString a_path, TESForm* a_default = nullptr);
	bool				solveFltSetter(void* a_domain, BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
	bool				solveIntSetter(void* a_domain, BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveStrSetter(void* a_domain, BSFixedString a_path, BSFixedString a_value, bool a_createMissingKeys = false);
	bool				solveObjSetter(void* a_domain, BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveFormSetter(void* a_domain, BSFixedString a_path, TESForm* a_value, bool a_createMissingKeys = false);
	void				setObj(void* a_domain, BSFixedString a_key, std::int32_t a_obj);
	bool				hasPath(void* a_domain, BSFixedString a_path);
	std::int32_t		allKeys(void* a_domain);
	std::int32_t		allValues(void* a_domain);
	void				writeToFile(void* a_domain, BSFixedString a_path);
	//void				readFromFile(void* a_domain, BSFixedString a_path);
	std::int32_t		root(void* a_domain);
}