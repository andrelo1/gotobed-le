#pragma once

namespace jc::JArray
{
	std::int32_t		object(void* a_domain);
	std::int32_t		objectWithSize(void* a_domain, std::int32_t a_size);
	std::int32_t		objectWithInts(void* a_domain, VMArray<std::int32_t> a_values);
	std::int32_t		objectWithStrings(void* a_domain, VMArray<BSFixedString> a_values);
	std::int32_t		objectWithFloats(void* a_domain, VMArray<float> a_values);
	std::int32_t		objectWithBooleans(void* a_domain, VMArray<bool> a_values);
	std::int32_t		objectWithForms(void* a_domain, VMArray<TESForm*> a_values);
	std::int32_t		subArray(void* a_domain, std::int32_t a_obj, std::int32_t a_startIndex, std::int32_t a_endIndex);
	void				addFromArray(void* a_domain, std::int32_t a_obj, std::int32_t a_source, std::int32_t a_insertAtIndex = -1);
	void				addFromFormList(void* a_domain, std::int32_t a_obj, BGSListForm* a_source, std::int32_t a_insertAtIndex = -1);
	std::int32_t		getInt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default = 0);
	float				getFlt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, float a_default = 0.0f);
	BSFixedString		getStr(void* a_domain, std::int32_t a_obj, std::int32_t a_index, BSFixedString a_default = "");
	std::int32_t		getObj(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_default = 0);
	TESForm*			getForm(void* a_domain, std::int32_t a_obj, std::int32_t a_index, TESForm* a_default = nullptr);
	std::int32_t		findInt(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex = 0);
	std::int32_t		findFlt(void* a_domain, std::int32_t a_obj, float a_value, std::int32_t a_searchStartIndex = 0);
	std::int32_t		findStr(void* a_domain, std::int32_t a_obj, BSFixedString a_value, std::int32_t a_searchStartIndex = 0);
	std::int32_t		findObj(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_searchStartIndex = 0);
	std::int32_t		findForm(void* a_domain, std::int32_t a_obj, TESForm* a_value, std::int32_t a_searchStartIndex = 0);
	void				setInt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value);
	void				setFlt(void* a_domain, std::int32_t a_obj, std::int32_t a_index, float a_value);
	void				setStr(void* a_domain, std::int32_t a_obj, std::int32_t a_index, BSFixedString a_value);
	void				setObj(void* a_domain, std::int32_t a_obj, std::int32_t a_index, std::int32_t a_value);
	void				setForm(void* a_domain, std::int32_t a_obj, std::int32_t a_index, TESForm* a_value);
	void				addInt(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index = -1);
	void				addFlt(void* a_domain, std::int32_t a_obj, float a_value, std::int32_t a_index = -1);
	void				addStr(void* a_domain, std::int32_t a_obj, BSFixedString a_value, std::int32_t a_index = -1);
	void				addObj(void* a_domain, std::int32_t a_obj, std::int32_t a_value, std::int32_t a_index = -1);
	void				addForm(void* a_domain, std::int32_t a_obj, TESForm* a_value, std::int32_t a_index = -1);
	std::int32_t		count(void* a_domain, std::int32_t a_obj);
	void				clear(void* a_domain, std::int32_t a_obj);
	void				eraseIndex(void* a_domain, std::int32_t a_obj, std::int32_t a_index);
	void				eraseRange(void* a_domain, std::int32_t a_obj, std::int32_t a_first, std::int32_t a_last);
	std::int32_t		valueType(void* a_domain, std::int32_t a_obj, std::int32_t a_index);
	void				swapItems(void* a_domain, std::int32_t a_obj, std::int32_t a_index1, std::int32_t a_index2);
	std::int32_t		sort(void* a_domain, std::int32_t a_obj);
	std::int32_t		unique(void* a_domain, std::int32_t a_obj);
	bool				writeToIntegerPArray(void* a_domain, std::int32_t a_obj, VMArray<std::int32_t> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, std::int32_t a_defaultRead = 0);
	bool				writeToFloatPArray(void* a_domain, std::int32_t a_obj, VMArray<float> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, float a_defaultRead = 0.0f);
	bool				writeToFormPArray(void* a_domain, std::int32_t a_obj, VMArray<TESForm*> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, TESForm* a_defaultRead = nullptr);
	bool				writeToStringPArray(void* a_domain, std::int32_t a_obj, VMArray<BSFixedString> a_targetArray, std::int32_t a_writeAtIdx = 0, std::int32_t a_stopWriteAtIdx = -1, std::int32_t a_readIdx = 0, BSFixedString a_defaultRead = "");
}