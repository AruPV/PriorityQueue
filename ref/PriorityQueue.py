from __future__ import annotations

import heapq
import random
import string

#################
class Entry[K,V]:
    __slots__ = ('key', 'value')

    def __init__(self, priority: K, data: V) -> None:
        self.key  : K = priority
        self.value: V = data

    def __str__(self) -> str:
        return f"({self.key},{self.value})"

    def __eq__(self, other: Entry[K,V]) -> bool:
        return self.key == other.key and self.value == other.value

    def __lt__(self, other: Entry[K,V]) -> bool:
        return self.key < other.key

    # not the Pythonic way to use __repr__ but allows us to print list of Entry
    def __repr__(self) -> str: 
        return f"({repr(self.key)},{'∅' if self.value is None else repr(self.value)})"

#######################
class PriorityQueue[K,V]:
    __slots__ = ('_container')

    def __init__(self):
        self._container: list[Entry] = list()

    def __len__(self)  -> int:   return len(self._container)
    def is_empty(self) -> bool:  return len(self._container) == 0

    def insert(self, key: K, item: V) -> None: 
        pass

    def remove_min(self) -> Entry[K,V]:
        pass

    def min(self) -> Entry:
        pass

    def __str__(self) -> str:
        return str(self._container)

##########################
if __name__ == "__main__":
    pq = PriorityQueue()
    print(f"len of pq = {len(pq)}")
    # more tests below

