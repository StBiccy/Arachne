#pragma once

#include "Event.h"

#include <sstream>

//		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, Tick, Update, Render,
namespace Arachne {

	class ARACHNE_API WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent() {}


		EVENT_CLASS_TYPE(WindowMoved)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int Height)
			: m_Width(width), m_Height(Height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: Width: " << m_Width << " Height:" << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class ARACHNE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(){}


		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}


		EVENT_CLASS_TYPE(WindowFocus)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}


		EVENT_CLASS_TYPE(WindowLostFocus)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API TickEvent : public Event
	{
	public:
		TickEvent() {}


		EVENT_CLASS_TYPE(Tick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API UpdateEvent : public Event
	{
	public:
		UpdateEvent() {}


		EVENT_CLASS_TYPE(Update)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARACHNE_API RenderEvent : public Event
	{
	public:
		RenderEvent() {}


		EVENT_CLASS_TYPE(Render)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
