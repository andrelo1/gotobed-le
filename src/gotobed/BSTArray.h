#pragma once

namespace Gotobed
{
	template<class T>
	class BSTArray
	{
	public:
		using reference = T&;
		using const_reference = const T&;
		using iterator = T*;
		using const_iterator = const T*;
		using size_type = std::uint32_t;

						BSTArray() = default;
						~BSTArray() { deallocate(); _size = 0; };
		size_type		size() const { return _size; };
		bool			empty() const { return _size == 0; };
		size_type		capacity() const { return _capacity; };
		T*				data() { return _data; };
		const T*		data() const { return _data; };
		iterator		begin() { return _data; };
		const_iterator	begin() const { return _data; };
		iterator		end() { return _data + _size; };
		const_iterator	end() const { return _data + _size; };
		reference		operator[](size_type a_pos) { return _data[a_pos]; };
		const_reference	operator[](size_type a_pos) const { return _data[a_pos]; };
		reference		front() { return _data[0]; };
		const_reference	front() const { return _data[0]; };
		reference		back() { return _data[_size - 1]; };
		const_reference	back() const { return _data[_size - 1]; };

		void resize(size_type a_size)
		{
			if (a_size > _capacity) {
				reallocate(_capacity + calc_capacity_growth(a_size - _capacity));
			}

			if (a_size > _size) {
				for (auto it = end(); _size != a_size; ++it, ++_size) {
					std::construct_at(it);
				}
			} else if (a_size < _size) {
				for (auto it = end() - 1; _size != a_size; --it, --_size) {
					std::destroy_at(it);
				}
			}
		};

		void resize(size_type a_size, const T& a_value)
		{
			if (a_size > _capacity) {
				reallocate(_capacity + calc_capacity_growth(a_size - _capacity));
			}

			if (a_size > _size) {
				for (auto it = end(); _size != a_size; ++it, ++_size) {
					std::construct_at(it, a_value);
				}
			} else if (a_size < _size) {
				for (auto it = end() - 1; _size != a_size; --it, --_size) {
					std::destroy_at(it);
				}
			}
		};

		iterator insert(iterator a_pos, const T& a_value)
		{
			if (_size == _capacity) {
				auto i = std::distance(begin(), a_pos);
				reallocate(_capacity + calc_capacity_growth(1));
				a_pos = begin() + i;
			}

			std::memmove(a_pos + 1, a_pos, (end() - a_pos) * sizeof(T));
			std::construct_at(a_pos, a_value);
			_size++;

			return a_pos;
		}

		iterator erase(iterator a_pos)
		{
			std::destroy_at(a_pos);
			std::memmove(a_pos, a_pos + 1, (end() - a_pos - 1) * sizeof(T));
			_size--;

			return a_pos;
		};

		void push_back(const T& a_value)
		{
			if (_size == _capacity) {
				reallocate(_capacity + calc_capacity_growth(1));
			}

			std::construct_at(end() - 1, a_value);
			_size++;
		};

		void pop_back()
		{
			std::destroy_at(end() - 1);
			_size--;
		};

		template<class... Args>
		reference emplace_back(Args&&... args)
		{
			if (_size == _capacity) {
				reallocate(_capacity + calc_capacity_growth(1));
			}

			std::construct_at(end(), std::forward<Args>(args)...);
			_size++;

			return back();
		}

	private:
		static constexpr size_type CAPACITY_MIN = 4;
		static constexpr size_type CAPACITY_MAX = std::numeric_limits<size_type>::max();

		size_type calc_capacity_growth(size_type a_hint) const
		{
			auto growth = std::max(_capacity, a_hint);
			return std::clamp(growth, _capacity < CAPACITY_MIN ? CAPACITY_MIN - _capacity : 0, CAPACITY_MAX - _capacity);
		}

		void reallocate(size_type a_capacity)
		{
			auto new_data = a_capacity ? reinterpret_cast<T*>(FormHeap_Allocate(a_capacity * sizeof(T))) : nullptr;

			if (_data && new_data) {
				std::memcpy(new_data, _data, std::min(_capacity, a_capacity) * sizeof(T));
			}

			if (_data) {
				FormHeap_Free(_data);
			}

			_data = new_data;
			_capacity = a_capacity;
		};

		void deallocate()
		{
			if (_data) {
				FormHeap_Free(_data);
			}

			_data = nullptr;
			_capacity = 0;
		}

		T*			_data{ nullptr };
		size_type	_capacity{ 0 };
		size_type	_size{ 0 };
	};

	static_assert(sizeof(BSTArray<std::uint8_t>) == 0xC);
}