/**
 * БИЛЕТ 6
 * ---
 * Разработать класс набор битов с перегрузкой операторов
 * ---
 * Стандарт: C++11
 */

#include <iostream>
#include <bitset>


// ---------- CLASS DECLARATION ---------- //


class BitSet {
protected:
	unsigned char* bytes  = nullptr;
	unsigned int bytesNum = 0;

	// возвращает байт в виде 00000001, где 1 стоит на указанной позиции (от 0 до 7)
	// position = 3 => 00010000 и по аналогии
	static unsigned char getByteMask(unsigned short position);

public:
	// bitNum - требуемое количество битов
	explicit BitSet(unsigned int bitNum);
	~BitSet();

	// возвращает значение бита на указанной позиции (от 0)
	bool at(unsigned int position) const;
	// устанавливает значение бита (0 или 1) на указанной позиции (от 0)
	void set(unsigned int position, bool bitValue);
	// возвращает БАЙТ на указанной позиции (от 0)
	unsigned char* operator[] (unsigned int byte);

	// выводит последовательность битов
	friend std::ostream& operator<< (std::ostream& out, const BitSet& bitSet);
};


// ---------- MAIN FUNCTION ---------- //


int main() {

	BitSet bitSet = BitSet(12);

	bitSet.set(5, true);
	std::cout << bitSet << std::endl << std::endl;

	bitSet.set(15, true);
	std::cout << bitSet << std::endl;
	std::cout << bitSet.at(15) << std::endl << std::endl;

	bitSet.set(8, true);
	std::cout << bitSet << std::endl << std::endl;

	bitSet.set(5, false);
	std::cout << bitSet << std::endl << std::endl;
	
	*bitSet[0] = (unsigned char)(12);
	std::cout << bitSet << std::endl << std::endl;

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


// bitNum - требуемое количество битов
BitSet::BitSet(unsigned int bitNum)
{
	this->bytesNum = bitNum / 8 + 1;
	this->bytes    = new unsigned char [this->bytesNum];

	for (unsigned int i = 0; i < this->bytesNum; i++) this->bytes[i] = 0;
}

BitSet::~BitSet()
{
	delete [] this->bytes;
}

// возвращает байт в виде 00000001, где 1 стоит на указанной позиции (от 0 до 7)
// position = 3 => 00010000 и по аналогии
unsigned char BitSet::getByteMask(unsigned short position)
{
	return 1UL << ((unsigned)7 - position);
}

// возвращает значение бита на указанной позиции (от 0)
bool BitSet::at(unsigned int position) const
{
	if (position/8 >= this->bytesNum) return false;
	return this->bytes[position/8] & BitSet::getByteMask(position%8);
}

// устанавливает значение бита (0 или 1) на указанной позиции (от 0)
void BitSet::set(unsigned int position, bool bitValue)
{
	if (position/8 >= this->bytesNum) return;

	auto tmp = BitSet::getByteMask(position%8);

	if (bitValue)
		this->bytes[position/8] |= tmp;
	else
		this->bytes[position/8] &= ~tmp;
}

// возвращает БАЙТ на указанной позиции (от 0)
unsigned char* BitSet::operator[] (unsigned int byte)
{
	if (byte >= this->bytesNum) return nullptr;
	return &this->bytes[byte];
}

// выводит последовательность битов
std::ostream& operator<< (std::ostream& out, const BitSet& bitSet)
{
	for (unsigned int bit = 0; bit < bitSet.bytesNum * 8; bit++)
		out << bitSet.at(bit) << ((bit != 0 && bit % 10 == 7) ? " " : "");
	return out;
}
