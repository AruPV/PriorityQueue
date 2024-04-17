#include <gtest/gtest.h>
#include "../incl/priority-queue.hpp"

class UtilTest: public testing::Test{};


TEST_F(UtilTest, power_two){
	EXPECT_EQ(is_power_of_two(2), true);
	EXPECT_EQ(is_power_of_two(3), false);
	EXPECT_EQ(is_power_of_two(4), true);
	EXPECT_EQ(is_power_of_two(5), false);
	EXPECT_EQ(is_power_of_two(6), false);
	EXPECT_EQ(is_power_of_two(6), false);
	EXPECT_EQ(is_power_of_two(7), false);
	EXPECT_EQ(is_power_of_two(8), true);
}

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
		PriorityQueueTest(){
			once_int_int_pq.insert(1,2);
			twice_int_int_pq.insert(1,2);
			twice_int_int_pq.insert(2,2);
			rev_twice_int_int_pq.insert(2,2);
			rev_twice_int_int_pq.insert(1,2);

			int big_size = 100;
			for (int i = 0; i <= big_size; i++){

				big_int_int_pq.insert(i, i+1);
				rev_big_int_int_pq.insert(big_size-i, big_size-i+1);

			}

			ten_int_int_pq.insert(9,0);
			/*
			 *  (9,0)
			 */
			ten_int_int_pq.insert(7,0);
			/*
			 *  (7,0)
			 *  (9,0)
			 */
			ten_int_int_pq.insert(5,0);
			/*
			 *  (5,0)
			 *  (9,0)(7,0)
			 */
			ten_int_int_pq.insert(10,0);
			/*
			 *  (5,0)
			 *  (9,0)(7,0)
			 *  (10,0)
			 */
			ten_int_int_pq.insert(5,0);
			/*
			 *  (5,0)
			 *  (5,0)(7,0)
			 *  (10,0)(9,0)
			 */
			ten_int_int_pq.insert(11,0);
			/*
			 *  (5,0)
			 *  (5,0)(7,0)
			 *  (10,0)(9,0)(11,0)
			 */
			ten_int_int_pq.insert(3,0);
			/*
			 *  (3,0)
			 *  (5,0)(5,0)
			 *  (10,0)(9,0)(11,0)(7,0)
			 */
			ten_int_int_pq.insert(4,0);
			/*
			 *  (3,0)
			 *  (4,0)(5,0)
			 *  (5,0)(9,0)(11,0)(7,0)
			 *  (10,0)
			 */
			ten_int_int_pq.insert(7,0);
			/*
			 *  (3,0)
			 *  (4,0)(5,0)
			 *  (5,0)(9,0)(11,0)(7,0)
			 *  (10,0)(7,0)
			 */
			ten_int_int_pq.insert(6,0);
			/*
			 *  (3,0)
			 *  (4,0)(5,0)
			 *  (5,0)(6,0)(11,0)(7,0)
			 *  (10,0)(7,0)(9,0)
			 */
			ten_int_int_pq.insert(15,0);
			/*
			 *  (3,0)
			 *  (4,0)(5,0)
			 *  (5,0)(6,0)(11,0)(7,0)
			 *  (10,0)(7,0)(9,0)(15,0)
			 */
		}
		PriorityQueue<int, int> empty_int_int_pq;
		PriorityQueue<int, int> once_int_int_pq;
		PriorityQueue<int, int> twice_int_int_pq;
		PriorityQueue<int, int> rev_twice_int_int_pq;
		PriorityQueue<int, int> big_int_int_pq;
		PriorityQueue<int, int> rev_big_int_int_pq;
		PriorityQueue<int, int> ten_int_int_pq;

};

TEST_F(PriorityQueueTest, empty_pq){
	EXPECT_EQ(empty_int_int_pq.is_empty(), true);
	EXPECT_EQ(empty_int_int_pq.size(), 0);
	EXPECT_EQ(empty_int_int_pq.to_string(), "[EMPTY]");
}

TEST_F(PriorityQueueTest, pushing_to_pq){
	EXPECT_EQ(empty_int_int_pq.is_empty(), true);
	EXPECT_EQ(empty_int_int_pq.size(), 0);
	empty_int_int_pq.insert(2,3);
	EXPECT_EQ(empty_int_int_pq.is_empty(), false);
	EXPECT_EQ(empty_int_int_pq.size(), 1);
	empty_int_int_pq.insert(3,4);
	EXPECT_EQ(empty_int_int_pq.is_empty(), false);
	EXPECT_EQ(empty_int_int_pq.size(), 2);
}

TEST_F(PriorityQueueTest, eq_of_pushed_pq){
	EXPECT_EQ(twice_int_int_pq.to_string(), rev_twice_int_int_pq.to_string());
	twice_int_int_pq.insert(54,12);
	EXPECT_NE(twice_int_int_pq.to_string(), rev_twice_int_int_pq.to_string());
	rev_twice_int_int_pq.insert(54,12);
	EXPECT_EQ(twice_int_int_pq.to_string(), rev_twice_int_int_pq.to_string());
}

TEST_F(PriorityQueueTest, negative_int_pq){
	ASSERT_EQ(twice_int_int_pq.to_string(), rev_twice_int_int_pq.to_string());
	twice_int_int_pq.insert(-1,12);
	EXPECT_EQ(twice_int_int_pq.to_string(), "(-1,12)\n(2,2)(1,2)");
}

TEST_F(PriorityQueueTest, long_pq){
	EXPECT_EQ(rev_big_int_int_pq.size(), 101);
	EXPECT_EQ(big_int_int_pq.size(),     101);
}

TEST_F(PriorityQueueTest, ten_pq){
	EXPECT_EQ(ten_int_int_pq.to_string(), "(3,0)\n(4,0)(5,0)\n(5,0)(6,0)(11,0)(7,0)\n(10,0)(7,0)(9,0)(15,0)");
	/*
	 *  (3,0)
	 *  (4,0)(5,0)
	 *  (5,0)(6,0)(11,0)(7,0)
	 *  (10,0)(7,0)(9,0)(15,0)
	 */
}

TEST_F(PriorityQueueTest, twice_int_remove_min){
	ASSERT_EQ(twice_int_int_pq.to_string(), rev_twice_int_int_pq.to_string());
	EXPECT_EQ(twice_int_int_pq.remove_min().key,1);
	EXPECT_EQ(twice_int_int_pq.to_string(),"(2,2)");
}

TEST_F(PriorityQueueTest, ten_int_remove_min){
	ASSERT_EQ(ten_int_int_pq.to_string(), "(3,0)\n(4,0)(5,0)\n(5,0)(6,0)(11,0)(7,0)\n(10,0)(7,0)(9,0)(15,0)");
	EXPECT_EQ(ten_int_int_pq.remove_min().key,3);
	ASSERT_EQ(ten_int_int_pq.to_string(), "(4,0)\n(5,0)(5,0)\n(7,0)(6,0)(11,0)(7,0)\n(10,0)(15,0)(9,0)");
	/*
	 *  (4,0)
	 *  (5,0)(5,0)
	 *  (7,0)(6,0)(11,0)(7,0)
	 *  (10,0)(15,0)(9,0)
	 */
}

TEST_F(PriorityQueueTest, ten_int_min){
	ASSERT_EQ(ten_int_int_pq.to_string(), "(3,0)\n(4,0)(5,0)\n(5,0)(6,0)(11,0)(7,0)\n(10,0)(7,0)(9,0)(15,0)");
	EXPECT_EQ(ten_int_int_pq.min().key,3);
	EXPECT_EQ(ten_int_int_pq.to_string(), "(3,0)\n(4,0)(5,0)\n(5,0)(6,0)(11,0)(7,0)\n(10,0)(7,0)(9,0)(15,0)");
}

TEST_F(PriorityQueueTest, remove_from_empty){
	ASSERT_EQ(empty_int_int_pq.to_string(), "[EMPTY]");
	EXPECT_THROW(empty_int_int_pq.remove_min(), std::out_of_range);
}
TEST_F(PriorityQueueTest, min_from_empty){
	ASSERT_EQ(empty_int_int_pq.to_string(), "[EMPTY]");
	EXPECT_THROW(empty_int_int_pq.min(), std::out_of_range);
}
