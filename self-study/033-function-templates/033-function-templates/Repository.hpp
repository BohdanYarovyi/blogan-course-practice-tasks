#pragma once

#include <iostream>

// Repository<T>
template <typename T> 
class Repository
{
protected:
	T value;
	
public:
	Repository(T value)
		: value(value)
	{
	}

	~Repository() = default;

	void print() const;
};

template <typename T>
inline void Repository<T>::print() const
{
	std::cout << "Value: " << value << std::endl;
}

template <>
inline void Repository<double>::print() const
{
	std::cout << std::scientific << "Value: " << value << std::endl;
}

// Repository<T*>
template <typename T>
class Repository<T*>
{
private:
	T* pValue;

public:
	Repository(T* pValue)
	{
		this->pValue = new T(*pValue);
	}

	~Repository()
	{
		delete[] pValue;
	}

	void print() const
	{
		std::cout << *pValue << '\n';
	}
};