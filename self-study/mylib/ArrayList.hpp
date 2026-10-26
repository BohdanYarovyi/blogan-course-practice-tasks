#pragma once

#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class ArrayList
{
  protected:
	const int INITIAL_DEFAULT_CAPACITY = 16;

	int actualCapacity;
	int actualSize;
	T** array;

  public:
	ArrayList()
	    : actualSize(0), actualCapacity(INITIAL_DEFAULT_CAPACITY)
	{
		array = new T*[actualCapacity];
	}

	virtual ~ArrayList()
	{
		for (int i = 0; i < actualSize; i++)
		{
			delete array[i];
		}
		delete[] array;
	}

	virtual void add(const T& element)
	{
		expandIfNoSpace();
		array[actualSize] = new T(element);
		actualSize++;
	}

	virtual T& get(int index) const
	{
		std::cout << index;
		if (index < 0 || index >= actualSize)
		{
			throw std::out_of_range("Wrong index to access an element.");
		}

		return *array[index];
	}

	virtual T remove(int index)
	{
		if (index < 0 || index >= actualSize)
		{
			throw std::out_of_range("Wrong index to access an element.");
		}

		if (actualSize == 0)
		{
			throw std::range_error("List is empty.");
		}

		T copy = *array[index];
		delete array[index];
		array[index] = nullptr;
		moveLeft(index);
		actualSize--;

		return  copy;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayList<T>& list)
	{
		out << "ArrayList(" << list.actualSize << ") [";
		for (int i = 0; i < list.actualSize; i++) {
			out << *list.array[i];

			if (i < list.actualSize - 1)
			{
				out << ", ";
			}
		}
		out << "]";

		return out;
	}

  private:
	void expandIfNoSpace()
	{
		if (!isPlaceEvailable())
		{
			expandArray();
		}
	}

	bool isPlaceEvailable() const
	{
		return actualCapacity - actualSize;
	}

	void expandArray()
	{
		int oldCapacity = actualCapacity;
		T** oldArray = array;
		actualCapacity *= 2;
		array = new T*[actualCapacity];

		for (int i = 0; i < oldCapacity; i++)
		{
			array[i] = oldArray[i];
		}
		delete[] oldArray;
	}

	void moveRight(int index)
	{
		assert(index >= 0);
		assert(index < actualSize);

		expandIfNoSpace();
		for (int i = actualSize; i > index; i--)
		{
			array[i] = array[i - 1];
		}
		array[index] = nullptr;
	}

	void moveLeft(int index)
	{
		assert(index >= 0);
		assert(index < actualSize);
		assert(array[index] == nullptr);

		for (int i = index + 1; i < actualSize; i++)
		{
			array[i - 1] = array[i];
		}
		array[actualSize - 1] = nullptr;
	}
};
