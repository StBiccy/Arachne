#pragma once

#include "Arachne/Core.h"


namespace Arachne {
	
	// events will be called immediatly,
	// this will be changed in the future so they can be stored and called during the event phase of the update
	// may also be adding and removing events depending on if they are needed
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		Tick, Update, Render,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// this will allow me to filter events
	// if I want to get events in a specfic catgory I just need to use this.
	// 
	// using BIT we create a binnary feild, which will allow us to put events into mutiple catagories:
	// E.G MouseButtonPressed is an imput and mouse event there for MouseButtonPressed would have a
	//  Category of (00001010) representing both input and mouse Category
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::##type; }\
							virtual EventType GetEventType() const override {return GetStaticType(); }\
							virtual const char* GetName() const override {return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category; }


	class ARACHNE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory Category)
		{
			return GetCategoryFlags() & Category;
		}
	protected:
		bool m_Handeled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handeled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	//inline std::string format_as(const Event& e) {
	//	return e.ToString();
	//}


	//this is supposed to work
	
	//inline std::ostream& operator<<(std::ostream& os, const Event& e)
	//{
	//	return os << e.ToString();
	//}
}