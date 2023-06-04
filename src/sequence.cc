#include "..\include\sequence\sequence.h"
#include <sequence/sequence.h>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace SEQUENCE;
using namespace std;

Sequence::Sequence(SequenceType type, int c) : type(type), c(c) {}

SequenceType Sequence::get_type() const {
	return type;
}

int Sequence::get_c() const {
	return c;
}

SequencePtr Sequence::create_SQUARE(int c)
{
	return new Sequence(SQUARE, c);
}

SequencePtr Sequence::create_FACTORIAL()
{
	return new Sequence(FACTORIAL, 0);
}

int Sequence::calculate_n(int n) const {
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	switch (type)
	{
	case(SQUARE):
		return n * n + c;
	case(FACTORIAL):
		int result = 1;
		for (int i = 1; i <= n; ++i) {
			result *= i;
		}
		return result;
	}
}

SequencePtr Sequence::clone() const {
	return new Sequence(type, c);
}

Sequence& Sequence::operator=(const Sequence & copy)
{
	type = copy.get_type();
	c = copy.get_c();
	return *this;
}

std::ostream& SEQUENCE::operator<<(std::ostream& out, const Sequence& item)
{
	switch (item.get_type())
	{
	case SQUARE:
		out << "(SQUARE, " << item.get_c() << ")" << endl;
		break;
	case FACTORIAL:
		out << "(FACTORIAL)" << endl;
		break;
	}
	return out;
}

bool SEQUENCE::operator==(const Sequence & lhs, const Sequence & rhs) {
	return
		lhs.get_type() == rhs.get_type() &&
		lhs.get_c() == rhs.get_c();
}

bool SEQUENCE::operator!=(const Sequence & lhs, const Sequence & rhs) {
	return !(lhs == rhs);
}

void Sequence::print() const {
	switch (type)
	{
	case SEQUENCE::SQUARE:
		cout << "(SQUARE, " << c << ")" << endl;
		break;
	case SEQUENCE::FACTORIAL:
		cout << "(FACTORIAL)" << endl;
		break;
	}
}