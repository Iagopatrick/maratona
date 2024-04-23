#include <map>
#include <iostream>
template <typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(V const &val)
		: m_valBegin(val)
	{
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		// INSERT YOUR SOLUTION HERE
		if (!(keyBegin < keyEnd))
		{
			return;
		}
		if (m_valBegin == val)
		{	
			if(m_map.size() < 2){
				if(m_map.size() < 1){
					//invalid assignment
					exit(1);
				}
				
				m_map.insert(keyEnd, val);
				return;
			}
			if(m_map.end()->second == val){
				exit(1);
			}
			// it's in keyEnd
			const auto & key = m_map.begin();
			const auto & key1 = m_map.begin()++;
			
			if(!(key->first < keyEnd) && !(keyEnd < key1->first)){
				m_map.insert(keyEnd, val);
				return;
			}else if(key1->first < keyEnd || keyEnd < key->first){
				m_map.insert(keyEnd, val);	
				return;
			}else if(!(key->first < keyBegin) && !(keyBegin < key1->first)){
				m_map.insert(keyBegin, val)
				return;
			}else if(key1->first < keyBegin || keyBegin < key->first){
				m_map.insert(keyBegin, val);	
				return;
			}else{
				exit(1);
			}
			
			

		}
		else
		{
			// it's in keyBegin
			m_map.insert(keyEnd, val);
			
		}
	}

	// look-up of the value associated with key
	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}

	void IntervalMapTest()
	{
		for(int i = 0; i < m_map.size(); i++){
			std::cout << m_map[i] << " ";
			

		}
		std::cout << "\n";
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main()
{
	interval_map<int, char> m('A');
	
	
	m.assign(1, 10, 'A');

	
	

	

	m.IntervalMapTest();

	return 0;
}