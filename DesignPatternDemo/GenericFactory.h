#pragma once

#include <map>
#include <memory>
#include <functional>

template<typename T, typename O>
std::unique_ptr<O> createInstance(void* callbackInterface)
{
	return std::make_unique<T>(callbackInterface);
}

template<typename K, typename O>
class GenericFactory
{
public:

	GenericFactory(const GenericFactory&) = delete; // Prevent construction by copying
	GenericFactory& operator=(const GenericFactory&) = delete; // Prevent assignment
	GenericFactory& operator=(GenericFactory&&) = delete;

	GenericFactory() : _callbackInterface(nullptr)
	{

	}

	virtual ~GenericFactory()
	{

	}

	static GenericFactory* getInstance()
	{
		static std::unique_ptr<GenericFactory> _instance;

		if (!_instance)
		{
			_instance = std::make_unique<GenericFactory>();
		}

		return _instance.get();
	}
	
	void setCallbackInterface(void* callbackInterface)
	{
		_callbackInterface = callbackInterface;
	}

	std::unique_ptr<O> create(K name)
	{
		return _registeredGameObjects[name](_callbackInterface);
	}

	template<typename T>
	void registerInstance(K name)
	{
		_registeredGameObjects[name] = &createInstance<T, O>;
	}

private:
	std::map<K, std::function<std::unique_ptr<O>(void*)>> _registeredGameObjects;
	void* _callbackInterface;
};