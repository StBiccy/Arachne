#include "Event.h"

#include <sstream>

namespace Arachne {

	class ARACHNE_API MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent (X:" << m_MouseX << ", Y:" << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class ARACHNE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent (X offset:" << m_XOffset << ", Y offset:" << m_YOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

		class ARACHNE_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }


			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

		class ARACHNE_API MouseButtonPressedEvent : public MouseButtonEvent
		{
		public:
			MouseButtonPressedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
		};

		class ARACHNE_API MouseButtonReleasedEvent : public MouseButtonEvent
		{
		public:
			MouseButtonReleasedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
		};
}

