
#ifndef SIMPLELOGGER_H
#define SIMPLELOGGER_H

#include <iostream>

//---------------------------------------------------------------------------

class SimpleLogger
{
public:
	static SimpleLogger & GetInstance ()
	{
		static SimpleLogger instance;
		return instance;
	}

	void SetEnabled (const bool bEnabled)
	{
		m_bEnabled = bEnabled;
	}

	template<class T>
	SimpleLogger & operator<< (T value)
	{
		if ( m_bEnabled )
		{
			std::clog << value;
		}

		return GetInstance();
	}

	typedef std::ostream& ostream_manipulator (std::ostream&);
	SimpleLogger & operator<< (ostream_manipulator * pf)
	{
		if ( m_bEnabled )
		{
			std::clog << pf;
		}

		return GetInstance();
	}

private:
	SimpleLogger () : m_bEnabled(true) {}
	SimpleLogger (SimpleLogger const &);
	void operator= (SimpleLogger const &);

	bool m_bEnabled;
};

#define SH_DEBUG SimpleLogger::GetInstance()

//---------------------------------------------------------------------------

#endif	// SIMPLELOGGER_H
