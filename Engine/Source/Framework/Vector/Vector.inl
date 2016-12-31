
namespace BlazeFramework
{
	template<typename type>
	Vector<type>::Vector()
	{
	}

	template<typename type>
	Vector<type>::Vector(std::initializer_list<type> initializerList) : m_collectionOfItems(initializerList)
	{
	}

	template<typename type>
	Vector<type>::Vector(uint32 size, int32 defaultValues) : m_collectionOfItems(size, defaultValue)
	{
	}

	template<typename type>
	Vector<type>::Vector(uint32 size)
	{
		m_collectionOfItems.reserve(size);
	}

	template<typename type>
	Vector<type>::~Vector()
	{
	}

	template<typename type>
	void Vector<type>::PushBack(type itemToPushBack)
	{
		m_collectionOfItems.push_back(itemToPushBack);
	}

	template<typename type>
	type Vector<type>::AtPosition(uint32 position)
	{
		return m_collectionOfItems.at(position);
	}
}
