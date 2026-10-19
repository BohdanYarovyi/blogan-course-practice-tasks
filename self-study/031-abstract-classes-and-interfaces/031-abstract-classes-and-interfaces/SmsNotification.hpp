#pragma once

#include <iostream>

#include "./../../mylib/StringUtility.hpp"
#include "Notification.hpp"

class SmsNotification : public Notification
{
protected:
	char* phone;

public:
	SmsNotification(const char* phone, const char* title, const char* text)
		: Notification(title, text)
	{
		this->phone = StringUtility::copy(phone);
	}

	SmsNotification(const SmsNotification& other) = delete;

	virtual ~SmsNotification()
	{
		delete[] phone;
	}

	virtual const char* channel() const override
	{
		return "SMS";
	}

	virtual bool send() const override
	{
		std::cout << "Sent SMS notification with title \"" << title << "\" on the phone " << phone << "." << std::endl;
		return true;
	}

	SmsNotification& operator=(const SmsNotification& other) = delete;
};