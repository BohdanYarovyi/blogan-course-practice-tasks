#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"
#include "Notification.hpp"
#include "ISerializable.hpp"

class PushNotification : public Notification, public ISerializable
{
protected:
	const char SERIALIZE_DELIMITER = '_';
	char* deviceId;

public:
	PushNotification(const char* deviceId, const char* title, const char* text)
		: Notification(title, text)
	{
		this->deviceId = StringUtility::copy(deviceId);
	}

	PushNotification(const PushNotification& other) = delete;

	virtual ~PushNotification()
	{
		delete[] deviceId;
	}

	virtual const char* channel() const override
	{
		return "Push";
	}

	virtual bool send() const override
	{
		std::cout << "Sent push notification with title \"" << title << "\" on device with id \'" << deviceId << "\'." << std::endl;
		return true;
	}

	virtual char* serialize() const override
	{
		int lengthOfTitle = StringUtility::getLength(title);
		int lengthOfText = StringUtility::getLength(text);
		int lengthOfId = StringUtility::getLength(deviceId);
		int length = lengthOfTitle + lengthOfText + lengthOfId;

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
		for (int i = 0; i < lengthOfId; i++)
		{
			serialized[totalIndex++] = deviceId[i];
		}
		serialized[totalIndex++] = '\0';

		return serialized;
	}

	PushNotification& operator=(const PushNotification& other) = delete;
};