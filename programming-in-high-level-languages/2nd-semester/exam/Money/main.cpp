/**
 * БИЛЕТ 5
 * ---
 * Разработать класс деньги для работы с денежными суммами, с перегрузкой
 * операторов. И конвертацией в другую валюту
 * ---
 * Стандарт: C++11
 */

#include <iostream>


// ---------- CLASS DECLARATION ---------- //


const float DOLLAR_TO_EURO = 0.87;
const float EURO_TO_DOLLAR = 1.14;

enum CURRENCIES {
	DOLLAR,
	EURO
};

class Money {
protected:
	double amount = 0;
	CURRENCIES currency = DOLLAR;

public:
	Money();
	Money(double _amount, CURRENCIES _currency);
	Money(const Money& money);

	void convertTo(CURRENCIES newCurrency);

	Money operator- () const;

	friend Money operator+ (const Money& a, const Money& b);
	friend Money operator- (const Money& a, const Money& b);
	friend std::ostream& operator<< (std::ostream& out, const Money& money);
};


// ---------- MAIN FUNCTION ---------- //


int main() {

	Money money1 = Money(50, CURRENCIES::EURO);
	Money money2 = Money(100, CURRENCIES::DOLLAR);

	std::cout << money1 + money2 << std::endl;
	std::cout << money1 - money2 << std::endl;

	money2.convertTo(CURRENCIES::EURO);
	std::cout << money2 << std::endl;

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Money::Money() = default;

Money::Money(double _amount, CURRENCIES _currency) : amount{_amount}, currency{_currency} {}

Money::Money(const Money& money) : Money(money.amount, money.currency) {}

void Money::convertTo(CURRENCIES newCurrency)
{
	if (this->currency == newCurrency) return;

	switch(newCurrency) {
		case DOLLAR:
			this->amount *= EURO_TO_DOLLAR;
			break;
		case EURO:
			this->amount *= DOLLAR_TO_EURO;
			break;
		default:
			return;
	}

	this->currency = newCurrency;
}

Money Money::operator- () const
{
	return Money(-this->amount, this->currency);
}

Money operator+ (const Money& a, const Money& b)
{
	Money result, tmp;

	if (a.currency == b.currency)
		result.amount = a.amount + b.amount;
	else {
		tmp = Money(b);
		tmp.convertTo(a.currency);
		result.amount = a.amount + tmp.amount;
	}

	result.currency = a.currency;
	return result;
}

Money operator- (const Money& a, const Money& b)
{
	Money result = operator+(a, -b);
	if (result.amount < 0) result.amount = 0;
	return result;
}

std::ostream& operator<< (std::ostream& out, const Money& money)
{
	return out << money.amount << " " << ((money.currency == DOLLAR) ? "dollars" : "euros") << std::endl;
}