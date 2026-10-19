#pragma once

class ISerializable
{
public:
	virtual char* serialize() const = 0;

	virtual ~ISerializable() = default;
};