#pragma once

namespace jc::JValue
{
	std::int32_t		retain(void* a_domain, std::int32_t a_obj, BSFixedString a_tag = "");
	std::int32_t		release(void* a_domain, std::int32_t a_obj);
	std::int32_t		releaseAndRetain(void* a_domain, std::int32_t a_previousObject, std::int32_t a_newObject, BSFixedString a_tag = "");
	void				releaseObjectsWithTag(void* a_domain, BSFixedString a_tag);
	std::int32_t		zeroLifetime(void* a_domain, std::int32_t a_obj);
	std::int32_t		addToPool(void* a_domain, std::int32_t a_obj, BSFixedString a_poolName);
	void				cleanPool(void* a_domain, BSFixedString a_poolName);
	std::int32_t		shallowCopy(void* a_domain, std::int32_t a_obj);
	std::int32_t		deepCopy(void* a_domain, std::int32_t a_obj);
	bool				isExists(void* a_domain, std::int32_t a_obj);
	bool				isArray(void* a_domain, std::int32_t a_obj);
	bool				isMap(void* a_domain, std::int32_t a_obj);
	bool				isFormMap(void* a_domain, std::int32_t a_obj);
	bool				isIntegerMap(void* a_domain, std::int32_t a_obj);
	bool				empty(void* a_domain, std::int32_t a_obj);
	std::int32_t		count(void* a_domain, std::int32_t a_obj);
	void				clear(void* a_domain, std::int32_t a_obj);
	std::int32_t		readFromFile(void* a_domain, BSFixedString a_filePath);
	std::int32_t		readFromDirectory(void* a_domain, BSFixedString a_directoryPath, BSFixedString a_extension = "");
	std::int32_t		objectFromPrototype(void* a_domain, BSFixedString a_prototype);
	void				writeToFile(void* a_domain, std::int32_t a_obj, BSFixedString a_filePath);
	bool				hasPath(void* a_domain, std::int32_t a_obj, BSFixedString a_path);
	std::int32_t		solvedValueType(void* a_domain, std::int32_t a_obj, BSFixedString a_path);
	float				solveFlt(void* a_domain, std::int32_t a_obj, BSFixedString a_path, float a_default = 0.0f);
	std::int32_t		solveInt(void* a_domain, std::int32_t a_obj, BSFixedString a_path, std::int32_t a_default = 0);
	BSFixedString		solveStr(void* a_domain, std::int32_t a_obj, BSFixedString a_path, BSFixedString a_default = "");
	std::int32_t		solveObj(void* a_domain, std::int32_t a_obj, BSFixedString a_path, std::int32_t a_default = 0);
	TESForm*			solveForm(void* a_domain, std::int32_t a_obj, BSFixedString a_path, TESForm* a_default = nullptr);
	bool				solveFltSetter(void* a_domain, std::int32_t a_obj, BSFixedString a_path, float a_value, bool a_createMissingKeys = false);
	bool				solveIntSetter(void* a_domain, std::int32_t a_obj, BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveStrSetter(void* a_domain, std::int32_t a_obj, BSFixedString a_path, BSFixedString a_value, bool a_createMissingKeys = false);
	bool				solveObjSetter(void* a_domain, std::int32_t a_obj, BSFixedString a_path, std::int32_t a_value, bool a_createMissingKeys = false);
	bool				solveFormSetter(void* a_domain, std::int32_t a_obj, BSFixedString a_path, TESForm* a_value, bool a_createMissingKeys = false);
	float				evalLuaFlt(void* a_domain, std::int32_t a_obj, BSFixedString a_luaCode, float a_default = 0.0f);
	std::int32_t		evalLuaInt(void* a_domain, std::int32_t a_obj, BSFixedString a_luaCode, std::int32_t a_default = 0);
	BSFixedString		evalLuaStr(void* a_domain, std::int32_t a_obj, BSFixedString a_luaCode, BSFixedString a_default = "");
	std::int32_t		evalLuaObj(void* a_domain, std::int32_t a_obj, BSFixedString a_luaCode, std::int32_t a_default = 0);
	TESForm*			evalLuaForm(void* a_domain, std::int32_t a_obj, BSFixedString a_luaCode, TESForm* a_default = nullptr);
}