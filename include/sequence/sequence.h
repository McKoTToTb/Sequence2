#pragma once
#include <iostream>
#include <cstdlib>

namespace SEQUENCE
{
	enum SequenceType
	{
		SQUARE,
		FACTORIAL,
	};
	class Sequence;
	using SequencePtr = Sequence*;
	class Sequence
	{
	private:
		SequenceType type;
		int c;
		Sequence(SequenceType type, int c);
	public:
		SequenceType get_type() const;
		int get_c() const;
		static SequencePtr create_SQUARE(int c);
		static SequencePtr create_FACTORIAL();
		int calculate_n(int n) const;
		SequencePtr clone() const;
		void print() const;
		Sequence& operator=(const Sequence& copy);
		friend std::ostream& operator<<(std::ostream& out, const Sequence& item);
	};

	bool operator==(const Sequence& lhs, const Sequence& rhs);
	bool operator!=(const Sequence& lhs, const Sequence& rhs);

	class SequenceList
	{
		SequencePtr* _sequences;
		size_t _size;
	public:
		SequenceList();
		SequenceList(const SequenceList& list);
		int size() const;
		void swap(SequenceList& list) noexcept;
		SequenceList& operator=(const SequenceList& list);
		SequencePtr operator[](int index) const;
		void add(SequencePtr item);
		void insert(SequencePtr item, int index);
		void erase_index(int index);
		~SequenceList();
	};
	int search(const SequenceList& list, const int n);
}