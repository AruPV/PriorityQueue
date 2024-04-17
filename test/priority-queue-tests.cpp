#include <gtest/gtest.h>
#include "../src/priority-queue.hpp"


class EntryTest : public testing::Test {
	protected:
		Entry<int,int> int_int_entry      = Entry<int,int>(0,1);
		Entry<int,int> int_int_entry_copy = Entry<int,int>(0,1);
		Entry<int,int> int_int_entry_big  = Entry<int,int>(421,903);

		Entry<int,std::string> int_str_entry      = Entry(1,      std::string("test"));
		Entry<int,std::string> int_str_entry_copy = Entry(1,      std::string("test"));
		Entry<int,std::string> int_str_entry_big  = Entry(123123, std::string("laskdjlaksjd"));
};

TEST_F(EntryTest, int_int_str){
	EXPECT_EQ(int_int_entry.to_string(),     std::string("(0,1)"));
	EXPECT_EQ(int_int_entry_big.to_string(), std::string("(421,903)"));
}

TEST_F(EntryTest, int_str_str){
	EXPECT_EQ(int_str_entry.to_string(),     std::string("(1,test)"));
	EXPECT_EQ(int_str_entry_big.to_string(), std::string("(123123,laskdjlaksjd)"));
}

TEST_F(EntryTest, int_int_eq){
	EXPECT_EQ(int_int_entry == int_int_entry,      true);
	EXPECT_EQ(int_int_entry == int_int_entry_copy, true);
}

TEST_F(EntryTest, int_str_eq){
	EXPECT_EQ(int_str_entry == int_str_entry,      true);
	EXPECT_EQ(int_str_entry == int_str_entry_copy, true);
}

TEST_F(EntryTest, int_int_lt){
	EXPECT_EQ(int_int_entry     < int_int_entry,      false);
	EXPECT_EQ(int_int_entry     < int_int_entry_copy, false);
	EXPECT_EQ(int_int_entry     < int_int_entry_big,  true);
	EXPECT_EQ(int_int_entry_big < int_int_entry,      false);
}

TEST_F(EntryTest, int_str_lt){
	EXPECT_EQ(int_str_entry     < int_str_entry,      false);
	EXPECT_EQ(int_str_entry     < int_str_entry_copy, false);
	EXPECT_EQ(int_str_entry     < int_str_entry_big,  true);
	EXPECT_EQ(int_str_entry_big < int_str_entry,      false);
}

TEST_F(EntryTest, int_int_bt){
	EXPECT_EQ(int_int_entry     > int_int_entry,      false);
	EXPECT_EQ(int_int_entry     > int_int_entry_copy, false);
	EXPECT_EQ(int_int_entry     > int_int_entry_big,  false);
	EXPECT_EQ(int_int_entry_big > int_int_entry,      true);
}

TEST_F(EntryTest, int_str_bt){
	EXPECT_EQ(int_str_entry     > int_str_entry,      false);
	EXPECT_EQ(int_str_entry     > int_str_entry_copy, false);
	EXPECT_EQ(int_str_entry     > int_str_entry_big,  false);
	EXPECT_EQ(int_str_entry_big > int_str_entry,      true);
}

TEST_F(EntryTest, int_int_lqt){
	EXPECT_EQ(int_int_entry     <= int_int_entry,      true);
	EXPECT_EQ(int_int_entry     <= int_int_entry_copy, true);
	EXPECT_EQ(int_int_entry     <= int_int_entry_big,  true);
	EXPECT_EQ(int_int_entry_big <= int_int_entry,      false);
}

TEST_F(EntryTest, int_str_lqt){
	EXPECT_EQ(int_str_entry     <= int_str_entry,      true);
	EXPECT_EQ(int_str_entry     <= int_str_entry_copy, true);
	EXPECT_EQ(int_str_entry     <= int_str_entry_big,  true);
	EXPECT_EQ(int_str_entry_big <= int_str_entry,      false);
}

TEST_F(EntryTest, int_int_bqt){
	EXPECT_EQ(int_int_entry     >= int_int_entry,      true);
	EXPECT_EQ(int_int_entry     >= int_int_entry_copy, true);
	EXPECT_EQ(int_int_entry     >= int_int_entry_big,  false);
	EXPECT_EQ(int_int_entry_big >= int_int_entry,      true);
}

TEST_F(EntryTest, int_str_bqt){
	EXPECT_EQ(int_str_entry     >= int_str_entry,      true);
	EXPECT_EQ(int_str_entry     >= int_str_entry_copy, true);
	EXPECT_EQ(int_str_entry     >= int_str_entry_big,  false);
	EXPECT_EQ(int_str_entry_big >= int_str_entry,      true);
}

class PriorityQueueTest: public testing::Test {
	protected:
		PriorityQueue<int, int> empty_int_int_pq;

};

TEST_F(PriorityQueueTest, empty_pq){
	EXPECT_EQ(empty_int_int_pq.is_empty(), true);
	EXPECT_EQ(empty_int_int_pq.size(), 0);
}
