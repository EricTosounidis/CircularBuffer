#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	
	CircularBuffer() {
		_head = 0;
		_tail = 0;
		_size = 0;
		_current = 0;
		_capacity = cap;
	};

	

	T const& head() const { return c.at(_head); };
	T const& tail() const { return c.at(_tail); };

	void push_back(T val) noexcept {
		if (_size < _capacity) {
			c.at(_current) = val;
			_tail = _current;
			_current = (_current + 1) % _capacity;
			_size++;
		}
		else {
			_head = (_head + 1) % _capacity;
			_tail = (_tail + 1) % _capacity;
			_current = (_tail + 1) % _capacity;
			c[_tail] = val;
		}
	}

	void pop() {
		if (_size <= 0) {
			throw std::underflow_error("pop(): empty buffer");
		}
		_head++;
		_size--;
		if (_head >= _capacity) {
			_head = 0;
		}
	}

int size() const noexcept {return _size;}

int capacity() noexcept {return _capacity;}

bool empty() const noexcept { return c.empty();} //returns true if buffer is empty

bool full() const noexcept { return (c.size() == _capacity); }  //returns true if buffer is full

typename Container::iterator begin() { return c.begin(); }

typename Container::iterator end() { return c.end(); }


friend ostream& operator<<(ostream& os, CircularBuffer& buf) {
	os << "Buffer Info: head: " << buf._head << ", tail: " << buf._tail << ", current: " << buf._current << ", capacity: " << buf.capacity() 
	<< ", size " << buf.size() << endl;
	os << " Container: ";
	for (auto i : buf) {
		os << i << " ";
	}
	os << endl << endl;
	return os;
}
private:
	Container c; // will be std::array<T, cap>
	int _head; //oldest item in buffer
	int _tail; //newest item in buffer
	int _size; //# of elem in buffer
	int _current; //next write position in buffer
	int _capacity;
};
#endif

