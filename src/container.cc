#include <cstdio>
#include <stdexcept>
#include <sequence/sequence.h>
using namespace SEQUENCE;
using namespace std;

SequenceList::SequenceList() :_sequences(nullptr), _size(0) {}
    
SequenceList::SequenceList(const SequenceList& list) :_sequences(new Sequence* [list._size]), _size(list._size) {
    for (int i = 0; i < _size; ++i) {
        _sequences[i] = new Sequence(*list._sequences[i]);
    }
}

int SequenceList::size() const {
    return _size;
}

void SequenceList::swap(SequenceList& list) noexcept {
    std::swap(this->_sequences, list._sequences);
    std::swap(this->_size, list._size);
}
SequenceList& SequenceList::operator=(const SequenceList& list) {
    SequenceList copy(list);
    copy.swap(*this);
    return *this;
}
SequenceList::~SequenceList() {
    for (int i = 0; i < _size; ++i) {
        delete _sequences[i];
    }
    delete[] _sequences;
}

SequencePtr SequenceList::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw runtime_error("[SequenceList::operator[]] Index out of range.");
    }
    return _sequences[index];
}

void SequenceList::add(SequencePtr const item) {
    auto new_sequences = new SequencePtr[_size + 1];
    for (int i = 0; i < _size; ++i) {
        new_sequences[i] = _sequences[i];
    }
    new_sequences[_size] = item;
    delete[] _sequences;
    _sequences = new_sequences;
    ++_size;
}

void SequenceList::insert(SequencePtr const item, int index) {
    ++_size;
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
    auto new_sequences = new SequencePtr[_size];
    for (int i = 0; i < index; ++i) {
        new_sequences[i] = _sequences[i];
    }
    new_sequences[index] = item;
    for (int i = index + 1; i < _size; ++i) {
        new_sequences[i] = _sequences[i - 1];
    }
    delete[] _sequences;
    _sequences = new_sequences;
}

void SequenceList::erase_index(int index) {
    if (_size == 0) {
        throw runtime_error("SequenceList is empty");
    }
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
    auto new_sequences = new SequencePtr[_size - 1];
    for (int i = 0; i < index; ++i) {
        new_sequences[i] = _sequences[i];
    }
    for (int i = index; i < _size - 1; ++i) {
        new_sequences[i] = _sequences[i + 1];
    }
    delete[] _sequences;
    _sequences = new_sequences;
    --_size;
}
int SEQUENCE::search(const SequenceList& sequences, const int n) {
    if (n < 1) {
        throw runtime_error("n < 1");
    }
    int min_i = -1;
    for (int i = 0; i < sequences.size(); i++)
    {
        int min_n;
        if (min_i != -1) {
            min_n = sequences[min_i]->calculate_n(n);
        }
        else min_n = sequences[0]->calculate_n(n);
        int current_n = sequences[i]->calculate_n(n);
        if (min_n >= current_n)
        {
            min_i = i;
        }
    }
    return min_i;
}