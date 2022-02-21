#pragma once

#include <list>

namespace Gotobed
{
	template<class T>
	class BSSimpleList
	{
	public:
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;

		struct Node
		{
			T		value;
			Node*	next;
		};

		class iterator
		{
		public:
							iterator(Node* a_node) : node(a_node) {};
			reference		operator*() const { return node->value; };
			pointer			operator->() const { return std::addressof(node->value); };
			iterator&		operator++() { node = node->next; return *this; };
			iterator		operator++(int) { auto tmp = *this; node = node->next; return tmp; };
			bool			operator==(const iterator& a_rhs) const { return node == a_rhs.node; };
			bool			operator!=(const iterator& a_rhs) const { return !(*this == a_rhs); };

		private:
			Node*	node{ nullptr };
		};

		class const_iterator
		{
		public:
							const_iterator(Node* a_node) : node(a_node) {};
			const_reference	operator*() const { return node->value; };
			const_pointer	operator->() const { return std::addressof(node->value); };
			const_iterator&	operator++() { node = node->next; return *this; };
			const_iterator	operator++(int) { auto tmp = *this; node = node->next; return tmp; };
			bool			operator==(const const_iterator& a_rhs) const { return node == a_rhs.node; };
			bool			operator!=(const const_iterator& a_rhs) const { return !(*this == a_rhs); };

		private:
			Node*	node{ nullptr };
		};

		using iterator_category = std::forward_iterator_tag;

		bool			empty() { return !head.value && !head.next; };
		iterator		begin() { return iterator(&head); };
		const_iterator	begin() const { return const_iterator(&head); };
		iterator		end() { return iterator(nullptr); };
		const_iterator	end() const { return const_iterator(nullptr); };

	private:
		Node	head;
	};
}