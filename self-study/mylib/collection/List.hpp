#pragma once

template <typename T>
class List
{
public:
	virtual ~List() = default;

	virtual void add(const T& element) = 0;

	virtual void add(const T& element, int index) = 0;

	virtual T& get(int index) const = 0;

	virtual T remove(int index) = 0;

	virtual int getSize() const = 0;
};