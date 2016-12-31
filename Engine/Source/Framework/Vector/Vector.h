#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include <vector>
#include <initializer_list>

namespace BlazeFramework
{
	template<typename type>
	class Vector
	{
	public:
		Vector();
		//So that I can use {1,2,3} initialization style for my class
		Vector(std::initializer_list<type> initializer);
		//Makes it so the programmer has to explicitly declare default initialization values for each
		//element in the vector
		Vector(uint32 size, int32 defaultValues);
		//Creates vector of whatever size but does not initialize any values. This might be good for
		//avoiding any unnecessary allocations as this will only reserve the capacity (potentially 
		//better speed than other constructor). 
		Vector(uint32 size);
		~Vector();

		void PushBack(type itemToPushBack);
		type AtPosition(uint32 position);

	private:
		std::vector<type> m_collectionOfItems;
	};
}

//Need to include this in header so compiler/linker won't complain about the template definitions.
//.inl is replaceing .cpp to make it clear that this file is primarily an inline file for header
#include "Vector.inl"