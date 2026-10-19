#pragma once

#include <iostream>

#include "Notification.hpp"
#include "ISerializable.hpp"
#include "./../../mylib/StringUtility.hpp"

class EmailNotification : public Notification, public ISerializable
{
private:
	const char SERIALIZE_DELIMITER = '+';
	char* address;

public:
	EmailNotification(const char* address, const char* title, const char* text)
		: Notification(title, text)
	{
		this->address = StringUtility::copy(address);
	}

	EmailNotification(const EmailNotification& other) = delete;

	virtual ~EmailNotification()
	{
		delete[] address;
	}

	virtual const char* channel() const override
	{
		return "Email";
	}

	virtual bool send() const override
	{
		std::cout << "Sent email notification with title \"" << title << "\" on " << address << "." << std::endl;
		return true;
	}


	virtual char* serialize() const override
	{
		int lengthOfTitle = StringUtility::getLength(title);
		int lengthOfText = StringUtility::getLength(text);
		int lengthOfAddress = StringUtility::getLength(address);
		int length = lengthOfTitle + lengthOfText + lengthOfAddress;

		char* serialized = new char[length + 3];

		int totalIndex = 0;
		
		// copy title
		for (int i = 0; i < lengthOfTitle; i++)
		{
			serialized[totalIndex++] = title[i];
		}
		serialized[totalIndex++] = SERIALIZE_DELIMITER;

		// copy text
		for (int i = 0; i < lengthOfText; i++) 
		{
			serialized[totalIndex++] = text[i];
		}
		serialized[totalIndex++] = SERIALIZE_DELIMITER;

		// copy address
		for (int i = 0; i < lengthOfAddress; i++)
		{
			serialized[totalIndex++] = address[i];
		}
		serialized[totalIndex++] = '\0';

		return serialized;
	}

	EmailNotification& operator=(EmailNotification& other) = delete;
};