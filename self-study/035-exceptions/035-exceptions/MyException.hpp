#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"

class MyException
{
private:
	int reasonCode;
	char* message;

public:
	MyException(int reasonCode, const char* message)
		: reasonCode(reasonCode)
	{
		this->message = StringUtility::copy(message);
	}

	MyException(const MyException& other)
	{
		this->reasonCode = other.reasonCode;
		this->message = StringUtility::copy(other.message);
	}

	~MyException()
	{
		delete[] message;
	}

	int getReasonCode() const
	{
		return reasonCode;
	}

	const char* getMessage() const
	{
		return message;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyException& exception)
	{
		out << "MyException(reasonCode=" << exception.reasonCode << ", message=" << exception.message << ")";
		return out;
	}
};