#include "../incl/priority-queue.hpp"
#include <iostream>

void eleven(){
	PriorityQueue<int,char> slides_pq;
	slides_pq.insert(4,'C');
	slides_pq.insert(5,'A');
	slides_pq.insert(6,'Z');
	slides_pq.insert(15,'K');
	slides_pq.insert(9,'F');
	slides_pq.insert(7,'Q');
	slides_pq.insert(20,'B');
	slides_pq.insert(16,'X');
	slides_pq.insert(25,'J');
	slides_pq.insert(14,'E');
	slides_pq.insert(12,'H');
	slides_pq.insert(11,'S');
	slides_pq.insert(13,'W');

	std::cout << slides_pq.to_string() << "\n";

	slides_pq.insert(2,'T');

	std::cout << slides_pq.to_string() << "\n";
}

void eighteen(){
	PriorityQueue<int,char> slides_pq;
	slides_pq.insert(4,'C');
	slides_pq.insert(5,'A');
	slides_pq.insert(6,'Z');
	slides_pq.insert(15,'K');
	slides_pq.insert(9,'F');
	slides_pq.insert(7,'Q');
	slides_pq.insert(20,'B');
	slides_pq.insert(16,'X');
	slides_pq.insert(25,'J');
	slides_pq.insert(14,'E');
	slides_pq.insert(12,'H');
	slides_pq.insert(11,'S');
	slides_pq.insert(13,'W');

	std::cout << slides_pq.to_string() << "\n";

	slides_pq.remove_min();

	std::cout << slides_pq.to_string() << "\n";

}

int main(){
	eleven();
	eighteen();
}
