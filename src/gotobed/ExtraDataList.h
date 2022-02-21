#pragma once

namespace Gotobed
{
	class ExtraDataList
	{
	public:
		using reference = BSExtraData&;
		using const_reference = const BSExtraData&;
		using pointer = BSExtraData*;
		using const_pointer = const BSExtraData*;

		class iterator
		{
		public:
							iterator(BSExtraData* a_data) : data(a_data) {};
			reference		operator*() const { return *data; };
			pointer			operator->() const { return data; };
			iterator&		operator++() { data = data->next; return *this; };
			iterator		operator++(int) { auto tmp = *this; data = data->next; return tmp; };
			bool			operator==(const iterator& a_rhs) const { return data == a_rhs.data; };
			bool			operator!=(const iterator& a_rhs) const { return !(*this == a_rhs); };

		private:
			BSExtraData*	data{ nullptr };
		};

		class const_iterator
		{
		public:
							const_iterator(BSExtraData* a_data) : data(a_data) {};
			const_reference	operator*() const { return *data; };
			const_pointer	operator->() const { return data; };
			const_iterator&	operator++() { data = data->next; return *this; };
			const_iterator	operator++(int) { auto tmp = *this; data = data->next; return tmp; };
			bool			operator==(const const_iterator& a_rhs) const { return data == a_rhs.data; };
			bool			operator!=(const const_iterator& a_rhs) const { return !(*this == a_rhs); };

		private:
			BSExtraData*	data{ nullptr };
		};


		struct PresenceBitfield
		{
			bool	HasType(std::uint32_t a_type);

			std::uint8_t	bits[0x18];
		};

		bool			empty() { return !data; };
		iterator		begin() { return iterator(data); };
		const_iterator	begin() const { return const_iterator(data); };
		iterator		end() { return iterator(nullptr); };
		const_iterator	end() const { return const_iterator(nullptr); };

		bool			HasType(std::uint32_t a_type);
		BSExtraData*	GetByType(std::uint32_t a_type);
		BSExtraData*	Add(BSExtraData* a_data);
		void			Remove(BSExtraData* a_data, bool a_delete);

		std::int32_t	GetCount();

		BSExtraData*		data;
		PresenceBitfield*	presence;
	};
}