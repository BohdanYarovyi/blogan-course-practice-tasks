#pragma once

#include <exception>

#include "./../mylib/StringUtility.hpp"

class ArrayException : public std::exception
{
  private:
	char* message;

  public:
	ArrayException(const char* message)
	{
		this->message = StringUtility::copy(message);
	}

	~ArrayException()
	{
		delete[] message;
	}

	const char* getMessage() const
	{
		return message;
	}

	virtual const char* what() const noexcept override
	{
		return getMessage();
	}
};
