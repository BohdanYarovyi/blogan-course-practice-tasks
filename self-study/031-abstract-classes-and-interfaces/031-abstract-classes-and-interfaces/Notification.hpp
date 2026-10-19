#pragma once

#include <iostream>

#include "IPrintable.hpp"
#include "./../../mylib/StringUtility.hpp"

class Notification : public IPrintable
{
protected:
	char* title;
	char* text;

	Notification(const char* title, const char* text)
	{
		this->title = StringUtility::copy(title);
		this->text = StringUtility::copy(text);
	}

	Notification(const Notification& other) = delete;

	Notification& operator=(const Notification& other) = delete;

	virtual ~Notification() override
	{
		delete[] title;
		delete[] text;
	}

	virtual const char* channel() const = 0;

public:
	virtual bool send() const = 0;

	virtual void print() const override
	{
		std::cout << "Notification(channel=" << channel() << ", title=" << title << ", text=" << text << ")" << std::endl;
	}
};