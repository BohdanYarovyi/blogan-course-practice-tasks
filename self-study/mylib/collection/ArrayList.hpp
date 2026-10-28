#pragma once

#include <iostream>
#include <stdexcept>

#include "List.hpp"

static const int INITIAL_CAPACITY = 16;

template <typename T>
class ArrayList : public List<T>
{
private:
	int capacity;
	int size;
	T** elements;

public:
	ArrayList()
	{
		this->capacity = INITIAL_CAPACITY;
		this->size = 0;
		this->elements = new T*[capacity];
	}

	ArrayList(const ArrayList& other)
	{
		this->size = 0;
		this->capacity = other.capacity;
		this->elements = new T*[other.capacity];

		for (int i = 0; i < other.size; i++)
		{
			this->add(*other.elements[i]);
		}
	}

	virtual ~ArrayList() override
	{
		for (int i = 0; i < size; i++)
		{
			delete elements[i];
		}
		delete[] elements;
	}

	ArrayList& operator=(const ArrayList& other) = delete;

	virtual void add(const T& element) override
	{
		add(element, size);
	}

	virtual void add(const T& element, int index) override
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		}

		if (size == capacity) 
		{
			grow();
		}

		if (index < size)
		{
			moveRight(index);
		}
		
		elements[index] = new T(element);
		size++;
	}

	virtual T& get(int index) const override
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		}

		return *elements[index];
	}

	virtual T remove(int index) override
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		}
	
		T element = *elements[index];
		delete elements[index];
		moveLeft(index);
		size--;
		return element;
	}

	virtual int getSize() const override
	{
		return this->size;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayList& list) 
	{
		out << "ArrayList(size=" << list.size << ")[";
		for (int i = 0; i < list.size; i++)
		{
			out << *list.elements[i];

			if (i < list.size - 1)
			{
				out << ", ";
			}
		}
		out << "]";

		return out;
	}

private:
	void grow()
	{
		T** old = elements;
		capacity *= 2;
		elements = new T*[capacity];

		for (int i = 0; i < size; i++)
		{
			elements[i] = old[i];
		}
		delete[] old;
	}

	void moveRight(int index)
	{
		for (int i = size; i > index; i--)
		{
			elements[i] = elements[i-1];
		}
		elements[index] = nullptr;
	}

	void moveLeft(int index)
	{
		for (int i = index; i < size - 1; i++)
		{
			elements[i] = elements[i+1];
		}
		elements[size-1] = nullptr;
	}
};


template <typename T>
class ArrayList<T*> : public List<T*>
{
private:
	int capacity;
	int size;
	T** pointers;

public:
	ArrayList()
	{
		this->capacity = INITIAL_CAPACITY;
		this->size = 0;
		this->pointers = new T*[capacity];
	}

	ArrayList(const ArrayList& other) = delete;

	virtual ~ArrayList() override
	{
		delete[] pointers;
	}

	ArrayList& operator=(const ArrayList& other) = delete;

	virtual void add(T* const& pointer) override 
	{
		add(pointer, size);
	}

	virtual void add(T* const& pointer, int index) override 
	{
		if (index < 0 || index > size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		}

		if (size == capacity)
		{
			grow();
		}

		if (index < size)
		{
			moveRight(index);
		}

		pointers[index] = pointer;
		size++;
	}

	virtual T*& get(int index) const override
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		} 

		return pointers[index];
	}

	virtual T* remove(int index) override
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Index is out of ArrayList range");
		}

		T* pointer = pointers[index];
		moveLeft(index);
		size--;
		return pointer;
	}

	virtual int getSize() const override
	{
		return size;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayList& list) 
	{
		out << "ArrayList<*>(size=" << list.size << ")[";
		for (int i = 0; i < list.size; i++)
		{

			out << list.pointers[i];
			if (i < list.size - 1)
			{
				out << ", ";
			}
		}
		out << "]";

		return out;
	}

private:
	void grow()
	{
		T** old = pointers;
		capacity *= 2;
		pointers = new T*[capacity];

		for (int i = 0; i < size; i++)
		{
			pointers[i] = old[i];
		}
		delete[] old;
	}

	void moveRight(int index)
	{
		for (int i = size; i > index; i--)
		{
			pointers[i] = pointers[i-1];
		}
		pointers[index] = nullptr;
	}

	void moveLeft(int index)
	{
		for (int i = index; i < size - 1; i++)
		{
			pointers[i] = pointers[i+1];
		}
		pointers[size-1] = nullptr;
	}

};