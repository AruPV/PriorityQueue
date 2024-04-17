#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>

template<typename T>
std::string stringify(T t){
	return std::to_string(t);
}

template<>
inline std::string stringify<std::string>(std::string string){
	return string;
}

template<typename K, typename V>
class Entry{

	public:
		K   key;
		V   value;
		int index;

		Entry(K key, V value)           : key{key}, value{value}{}
		Entry(K key, V value, int index): key{key}, value{value}, index{index}{}

		bool operator< (Entry& other){ return (this->key < other.key); }
		bool operator> (Entry& other){ return (this->key > other.key); }
		bool operator<=(Entry& other){ return (!(*this>other)); }
		bool operator>=(Entry& other){ return (!(*this<other)); }
		bool operator==(Entry& other){
			bool eq_keys   = this->key   == other.key;
			bool eq_values = this->value == other.value;
			return (eq_keys && eq_values);
		}

		std::string to_string(){
			/*****************************************************************
			 * Produces std::string representation of the entry. Will break  *
			 * if either of the templated types is not in the standard       *
			 * library                                                       *
			 *****************************************************************/
			std::string output_str;
			auto key_string  = stringify(key);
			auto val_string  = stringify(value);
			output_str = output_str 
				+ "("
				+ key_string
				+ ","
				+ val_string
				+ ")" ;
			return output_str;
		}

};

template<typename K, typename V>
class PriorityQueue{
	
	private:
		typedef Entry<K,V>            Entry;
		typedef std::optional<Entry&> OptEntryRef;

		std::vector<Entry> container;

		
		OptEntryRef parent(Entry& entry){
			const int i = entry.index;

			if (i >= this->size() || i < 0){ throw std::out_of_range("Index out of bounds.");}
			if (i == 0){ return std::nullopt;}		

			const bool is_odd    = i % 2;
			const int difference = is_odd ? 1 : 2;

			const int parent_index = (i-difference)/2;
			return OptEntryRef(this[entry.index]);
		}

		OptEntryRef right_child(Entry& entry){
			const int i = entry.index;

			if (i >= this->size()){ throw std::out_of_range("Index out of bounds.");}

			const int child_index = (i * 2) + 2;
			if (child_index > (this->size()-1)){ return std::nullopt;}

			return (OptEntryRef(this[child_index]));
		}

		OptEntryRef left_child(Entry& entry){
			const int i = entry.index;

			if (i >= this->size()){ throw std::out_of_range("Index out of bounds.");}

			const int child_index = (i * 2) + 1;
			if (child_index > (this->size()-1)){ return std::nullopt;}

			return (OptEntryRef(this[child_index]));
		}

		void swap_entries(Entry& first_entry, Entry& second_entry){
			std::swap(first_entry, second_entry);
			std::swap(first_entry.index, second_entry.index);
		}

	public:
		PriorityQueue(){}

		size_t size()  { return(container.size()); }
		bool is_empty(){ return(container.empty()); }

		Entry& operator[](int i){
			if (i >=this->size){ throw std::invalid_argument("Index out of bounds.");}
			return container[i];
		}

		void insert(K key, V value){
			container.push_back(Entry(key,value,size()));
			Entry& new_entry = container.back();
			new_entry.index = size()-1;
			int cur_ind = new_entry.index;
			while(new_entry.index < parent(new_entry).index){}

		}

		Entry remove_min(){}
		Entry& min(){}
		std::string to_string(){}

};
