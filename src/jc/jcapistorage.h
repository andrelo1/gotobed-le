#pragma once

namespace jc
{
	struct reflection_interface;
	struct domain_interface;

	namespace api::detail
	{
		struct Storage
		{
			static Storage&		get();

			const reflection_interface*	reflectionInterface{ nullptr };
			const domain_interface*		domainInterface{ nullptr };

								// JDB
			float				(*JDB_solveFlt)(void*, BSFixedString, float) { nullptr };
			std::int32_t		(*JDB_solveInt)(void*, BSFixedString, std::int32_t) { nullptr };
			BSFixedString		(*JDB_solveStr)(void*, BSFixedString, BSFixedString) { nullptr };
			std::int32_t		(*JDB_solveObj)(void*, BSFixedString, std::int32_t) { nullptr };
			TESForm*			(*JDB_solveForm)(void*, BSFixedString, TESForm*) { nullptr };
			bool				(*JDB_solveFltSetter)(void*, BSFixedString, float, bool) { nullptr };
			bool				(*JDB_solveIntSetter)(void*, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JDB_solveStrSetter)(void*, BSFixedString, BSFixedString, bool) { nullptr };
			bool				(*JDB_solveObjSetter)(void*, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JDB_solveFormSetter)(void*, BSFixedString, TESForm*, bool) { nullptr };
			void				(*JDB_setObj)(void*, BSFixedString, std::int32_t) { nullptr };
			bool				(*JDB_hasPath)(void*, BSFixedString) { nullptr };
			std::int32_t		(*JDB_allKeys)(void*) { nullptr };
			std::int32_t		(*JDB_allValues)(void*) { nullptr };
			void				(*JDB_writeToFile)(void*, BSFixedString) { nullptr };
			void				(*JDB_readFromFile)(void*, BSFixedString) { nullptr };
			std::int32_t		(*JDB_root)(void*) { nullptr };

								// JFormDB
			void				(*JFormDB_setEntry)(void*, BSFixedString, TESForm*, std::int32_t) { nullptr };
			std::int32_t		(*JFormDB_makeEntry)(void*, BSFixedString, TESForm*) { nullptr };
			std::int32_t		(*JFormDB_findEntry)(void*, BSFixedString, TESForm*) { nullptr };
			float				(*JFormDB_solveFlt)(void*, TESForm*, BSFixedString, float) { nullptr };
			std::int32_t		(*JFormDB_solveInt)(void*, TESForm*, BSFixedString, std::int32_t) { nullptr };
			BSFixedString		(*JFormDB_solveStr)(void*, TESForm*, BSFixedString, BSFixedString) { nullptr };
			std::int32_t		(*JFormDB_solveObj)(void*, TESForm*, BSFixedString, std::int32_t) { nullptr };
			TESForm*			(*JFormDB_solveForm)(void*, TESForm*, BSFixedString, TESForm*) { nullptr };
			bool				(*JFormDB_solveFltSetter)(void*, TESForm*, BSFixedString, float, bool) { nullptr };
			bool				(*JFormDB_solveIntSetter)(void*, TESForm*, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JFormDB_solveStrSetter)(void*, TESForm*, BSFixedString, BSFixedString, bool) { nullptr };
			bool				(*JFormDB_solveObjSetter)(void*, TESForm*, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JFormDB_solveFormSetter)(void*, TESForm*, BSFixedString, TESForm*, bool) { nullptr };
			bool				(*JFormDB_hasPath)(void*, TESForm*, BSFixedString) { nullptr };
			std::int32_t		(*JFormDB_allKeys)(void*, TESForm*, BSFixedString) { nullptr };
			std::int32_t		(*JFormDB_allValues)(void*, TESForm*, BSFixedString) { nullptr };
			std::int32_t		(*JFormDB_getInt)(void*, TESForm*, BSFixedString) { nullptr };
			float				(*JFormDB_getFlt)(void*, TESForm*, BSFixedString) { nullptr };
			BSFixedString		(*JFormDB_getStr)(void*, TESForm*, BSFixedString) { nullptr };
			std::int32_t		(*JFormDB_getObj)(void*, TESForm*, BSFixedString) { nullptr };
			TESForm*			(*JFormDB_getForm)(void*, TESForm*, BSFixedString) { nullptr };
			void				(*JFormDB_setInt)(void*, TESForm*, BSFixedString, std::int32_t) { nullptr };
			void				(*JFormDB_setFlt)(void*, TESForm*, BSFixedString, float) { nullptr };
			void				(*JFormDB_setStr)(void*, TESForm*, BSFixedString, BSFixedString) { nullptr };
			void				(*JFormDB_setObj)(void*, TESForm*, BSFixedString, std::int32_t) { nullptr };
			void				(*JFormDB_setForm)(void*, TESForm*, BSFixedString, TESForm*) { nullptr };

								// JValue
			std::int32_t		(*JValue_retain)(void*, std::int32_t, BSFixedString) { nullptr };
			std::int32_t		(*JValue_release)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JValue_releaseAndRetain)(void*, std::int32_t, std::int32_t, BSFixedString) { nullptr };
			void				(*JValue_releaseObjectsWithTag)(void*, BSFixedString) { nullptr };
			std::int32_t		(*JValue_zeroLifetime)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JValue_addToPool)(void*, std::int32_t, BSFixedString) { nullptr };
			void				(*JValue_cleanPool)(void*, BSFixedString) { nullptr };
			std::int32_t		(*JValue_shallowCopy)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JValue_deepCopy)(void*, std::int32_t) { nullptr };
			bool				(*JValue_isExists)(void*, std::int32_t) { nullptr };
			bool				(*JValue_isArray)(void*, std::int32_t) { nullptr };
			bool				(*JValue_isMap)(void*, std::int32_t) { nullptr };
			bool				(*JValue_isFormMap)(void*, std::int32_t) { nullptr };
			bool				(*JValue_isIntegerMap)(void*, std::int32_t) { nullptr };
			bool				(*JValue_empty)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JValue_count)(void*, std::int32_t) { nullptr };
			void				(*JValue_clear)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JValue_readFromFile)(void*, BSFixedString) { nullptr };
			std::int32_t		(*JValue_readFromDirectory)(void*, BSFixedString, BSFixedString) { nullptr };
			std::int32_t		(*JValue_objectFromPrototype)(void*, BSFixedString) { nullptr };
			void				(*JValue_writeToFile)(void*, std::int32_t, BSFixedString) { nullptr };
			bool				(*JValue_hasPath)(void*, std::int32_t, BSFixedString) { nullptr };
			std::int32_t		(*JValue_solvedValueType)(void*, std::int32_t, BSFixedString) { nullptr };
			float				(*JValue_solveFlt)(void*, std::int32_t, BSFixedString, float) { nullptr };
			std::int32_t		(*JValue_solveInt)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			BSFixedString		(*JValue_solveStr)(void*, std::int32_t, BSFixedString, BSFixedString) { nullptr };
			std::int32_t		(*JValue_solveObj)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			TESForm*			(*JValue_solveForm)(void*, std::int32_t, BSFixedString, TESForm*) { nullptr };
			bool				(*JValue_solveFltSetter)(void*, std::int32_t, BSFixedString, float, bool) { nullptr };
			bool				(*JValue_solveIntSetter)(void*, std::int32_t, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JValue_solveStrSetter)(void*, std::int32_t, BSFixedString, BSFixedString, bool) { nullptr };
			bool				(*JValue_solveObjSetter)(void*, std::int32_t, BSFixedString, std::int32_t, bool) { nullptr };
			bool				(*JValue_solveFormSetter)(void*, std::int32_t, BSFixedString, TESForm*, bool) { nullptr };
			float				(*JValue_evalLuaFlt)(void*, std::int32_t, BSFixedString, float) { nullptr };
			std::int32_t		(*JValue_evalLuaInt)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			BSFixedString		(*JValue_evalLuaStr)(void*, std::int32_t, BSFixedString, BSFixedString) { nullptr };
			std::int32_t		(*JValue_evalLuaObj)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			TESForm*			(*JValue_evalLuaForm)(void*, std::int32_t, BSFixedString, TESForm*) { nullptr };

								// JArray
			std::int32_t		(*JArray_object)(void*) { nullptr };
			std::int32_t		(*JArray_objectWithSize)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JArray_objectWithInts)(void*, VMArray<std::int32_t> ) { nullptr };
			std::int32_t		(*JArray_objectWithStrings)(void*, VMArray<BSFixedString>) { nullptr };
			std::int32_t		(*JArray_objectWithFloats)(void*, VMArray<float>) { nullptr };
			std::int32_t		(*JArray_objectWithBooleans)(void*, VMArray<bool>) { nullptr };
			std::int32_t		(*JArray_objectWithForms)(void*, VMArray<TESForm*>) { nullptr };
			std::int32_t		(*JArray_subArray)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_addFromArray)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_addFromFormList)(void*, std::int32_t, BGSListForm*, std::int32_t) { nullptr };
			std::int32_t		(*JArray_getInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			float				(*JArray_getFlt)(void*, std::int32_t, std::int32_t, float) { nullptr };
			BSFixedString		(*JArray_getStr)(void*, std::int32_t, std::int32_t, BSFixedString) { nullptr };
			std::int32_t		(*JArray_getObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			TESForm*			(*JArray_getForm)(void*, std::int32_t, std::int32_t, TESForm*) { nullptr };
			std::int32_t		(*JArray_findInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			std::int32_t		(*JArray_findFlt)(void*, std::int32_t, float, std::int32_t) { nullptr };
			std::int32_t		(*JArray_findStr)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			std::int32_t		(*JArray_findObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			std::int32_t		(*JArray_findForm)(void*, std::int32_t, TESForm*, std::int32_t) { nullptr };
			void				(*JArray_setInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_setFlt)(void*, std::int32_t, std::int32_t, float) { nullptr };
			void				(*JArray_setStr)(void*, std::int32_t, std::int32_t, BSFixedString) { nullptr };
			void				(*JArray_setObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_setForm)(void*, std::int32_t, std::int32_t, TESForm*) { nullptr };
			void				(*JArray_addInt)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_addFlt)(void*, std::int32_t, float, std::int32_t) { nullptr };
			void				(*JArray_addStr)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			void				(*JArray_addObj)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_addForm)(void*, std::int32_t, TESForm*, std::int32_t) { nullptr };
			std::int32_t		(*JArray_count)(void*, std::int32_t) { nullptr };
			void				(*JArray_clear)(void*, std::int32_t) { nullptr };
			void				(*JArray_eraseIndex)(void*, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_eraseRange)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			std::int32_t		(*JArray_valueType)(void*, std::int32_t, std::int32_t) { nullptr };
			void				(*JArray_swapItems)(void*, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			std::int32_t		(*JArray_sort)(void*, std::int32_t) { nullptr };
			std::int32_t		(*JArray_unique)(void*, std::int32_t) { nullptr };
			bool				(*JArray_writeToIntegerPArray)(void*, std::int32_t, VMArray<std::int32_t>, std::int32_t, std::int32_t, std::int32_t, std::int32_t) { nullptr };
			bool				(*JArray_writeToFloatPArray)(void*, std::int32_t, VMArray<float>, std::int32_t, std::int32_t, std::int32_t, float) { nullptr };
			bool				(*JArray_writeToFormPArray)(void*, std::int32_t, VMArray<TESForm*>, std::int32_t, std::int32_t, std::int32_t, TESForm*) { nullptr };
			bool				(*JArray_writeToStringPArray)(void*, std::int32_t, VMArray<BSFixedString>, std::int32_t, std::int32_t, std::int32_t, BSFixedString) { nullptr };

											// JMap
			std::int32_t					(*JMap_object)(void*) { nullptr };
			std::int32_t					(*JMap_getInt)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			float							(*JMap_getFlt)(void*, std::int32_t, BSFixedString, float) { nullptr };
			BSFixedString					(*JMap_getStr)(void*, std::int32_t, BSFixedString, BSFixedString) { nullptr };
			std::int32_t					(*JMap_getObj)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			TESForm*						(*JMap_getForm)(void*, std::int32_t, BSFixedString, TESForm*) { nullptr };
			void							(*JMap_setInt)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			void							(*JMap_setFlt)(void*, std::int32_t, BSFixedString, float) { nullptr };
			void							(*JMap_setStr)(void*, std::int32_t, BSFixedString, BSFixedString) { nullptr };
			void							(*JMap_setObj)(void*, std::int32_t, BSFixedString, std::int32_t) { nullptr };
			void							(*JMap_setForm)(void*, std::int32_t, BSFixedString, TESForm*) { nullptr };
			bool							(*JMap_hasKey)(void*, std::int32_t, BSFixedString) { nullptr };
			std::int32_t					(*JMap_valueType)(void*, std::int32_t, BSFixedString) { nullptr };
			std::int32_t					(*JMap_allKeys)(void*, std::int32_t) { nullptr };
			std::vector<BSFixedString>		(*JMap_allKeysPArray)(void*, std::int32_t) { nullptr };
			std::int32_t					(*JMap_allValues)(void*, std::int32_t) { nullptr };
			bool							(*JMap_removeKey)(void*, std::int32_t, BSFixedString) { nullptr };
			std::int32_t					(*JMap_count)(void*, std::int32_t) { nullptr };
			void							(*JMap_clear)(void*, std::int32_t) { nullptr };
			void							(*JMap_addPairs)(void*, std::int32_t, std::int32_t, bool) { nullptr };
			BSFixedString					(*JMap_nextKey)(void*, std::int32_t, BSFixedString, BSFixedString) { nullptr };
			BSFixedString					(*JMap_getNthKey)(void*, std::int32_t, std::int32_t) { nullptr };
		};
	}
}