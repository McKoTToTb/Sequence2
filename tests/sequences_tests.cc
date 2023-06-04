#include <gtest/gtest.h>
#include <sequence/sequence.h>

using namespace SEQUENCE;

TEST(sequenceTests, SumStubTest1) {
	const auto s = Sequence::create_SQUARE(3);
    int r1 = s->calculate_n(1);
    int r2 = s->calculate_n(2);
    int r3 = s->calculate_n(3);
    int r4 = s->calculate_n(4);
    int r5 = s->calculate_n(5);
    // Assert
    EXPECT_EQ(r1, 4);
    EXPECT_EQ(r2, 7);
    EXPECT_EQ(r3, 12);
    EXPECT_EQ(r4, 19);
    EXPECT_EQ(r5, 28);
}

TEST(sequenceTests, SumStubTest2) {
    const auto s = Sequence::create_FACTORIAL();
    int r1 = s->calculate_n(1);
    int r2 = s->calculate_n(2);
    int r3 = s->calculate_n(3);
    int r4 = s->calculate_n(4);
    int r5 = s->calculate_n(5);
    // Assert
    EXPECT_EQ(r1, 1);
    EXPECT_EQ(r2, 2);
    EXPECT_EQ(r3, 6);
    EXPECT_EQ(r4, 24);
    EXPECT_EQ(r5, 120);
}

TEST(sequenceTests, SumStubTest3) {
    SequenceList mas;
    mas.add(Sequence::create_SQUARE(3));
    mas.add(Sequence::create_FACTORIAL());
    mas.add(Sequence::create_SQUARE(5));
    mas.add(Sequence::create_SQUARE(10));
    mas.add(Sequence::create_FACTORIAL());
    int size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 5);
    SequencePtr item = mas[3];
    item->print();
    *mas[3] = *Sequence::create_FACTORIAL();
    item->print();
    mas[3]->print();
    EXPECT_EQ(item->get_type(), FACTORIAL);
    int r = search(mas, 4);
    EXPECT_EQ(r, 0);
    for (int i = 0; i < size_of_mas; ++i)
        mas[i]->print();
    mas.insert(Sequence::create_SQUARE(3), 3);
    size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 6);
    r = search(mas, 4);
    EXPECT_EQ(r, 3);
    for (int i = 0; i < size_of_mas; ++i)
        mas[i]->print();
    mas.erase_index(1);
    size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 5);
    for (int i = 0; i < size_of_mas; ++i)
        mas[i]->print();
}