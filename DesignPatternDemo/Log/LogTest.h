#pragma once

#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <sstream>
#include <memory>

#define LOG_DATA __namespace__, __FILE__, __func__, __LINE__

#define WRITE_LOG_ERROR(text) Log::getInstance()->write(Log::logType::Error, LOG_DATA, text)
#define WRITE_LOG_WARNING(text) Log::getInstance()->write(Log::logType::Warning, LOG_DATA, text)
#define WRITE_LOG_COMMENT(text) Log::getInstance()->write(Log::logType::Comment, LOG_DATA, text)
#define WRITE_LOG_EVENT(text) Log::getInstance()->write(Log::logType::Event, LOG_DATA, text)
#define WRITE_LOG_DEBUG(text) Log::getInstance()->write(Log::logType::Debug, LOG_DATA, text)
#define WRITE_LOG_MESSAGE(text) Log::getInstance()->write(Log::logType::Message, LOG_DATA, text)

class Log
{
public:
	Log() : _logLevel(logType::Message)
	{
		
	}

	static Log* getInstance()
	{
		static std::unique_ptr<Log> _instance;

		if (!_instance)
		{
			_instance = std::make_unique<Log>();
		}

		return _instance.get();
	}


	void init()
	{
		CreateDirectoryA("Log", nullptr);
		_logFile.open("Log\\log.xml");

		_logFile << "<?xml version=\"1.0\"?>" << std::endl;
		_logFile << "<?xml-stylesheet type=\"text/xsl\" href=\"ComplexXSLT.xsl\" ?>" << std::endl;
		_logFile << "<RunTimeLog>" << std::endl
			<< "<LogHeader>" << std::endl
			<< "<OutputLevel>Comprehensive debugging information (Level 2)</OutputLevel>" << std::endl
			<< "<Session>" << std::endl
			<< "<Started>" << std::endl
			<< "<Time>";

		SYSTEMTIME time;
		GetLocalTime(&time);

		TIME_ZONE_INFORMATION tzi;
		GetTimeZoneInformation(&tzi);

		std::ostringstream ss;
		ss << std::setiosflags(std::ios::fixed);
		ss << time.wHour << ":";
		ss << std::setfill('0') << std::setw(2) << time.wMinute << ":";
		ss << std::setfill('0') << std::setw(2) << time.wSecond << "(" << tzi.Bias / 60 << "h=UTC)";

		std::string str;
		str = ss.str();

		_logFile << str.c_str();
		_logFile << "</Time>" << std::endl;
		_logFile << "<Date>";
		_logFile << time.wDay << "." << time.wMonth << "." << time.wYear;
		_logFile << "</Date>" << std::endl;
		_logFile << "</Started>" << std::endl;

		_logFile << "<Configuration>" << std::endl;
		_logFile << "<Environment>" << "WINDOWS VERSION" << "</Environment>" << std::endl;

		_logFile << "<NumProcessors>" << "NUMBER OF CPU" << "</NumProcessors>" << std::endl;



		//for loop for more CPUs

		_logFile << "<Processor id=\"" << "CPU ID" << "\">" << std::endl
			<< "<Type>" << "CPU str NAME" << " (" << "CPU TYPE" << ")</Type>" << std::endl
			<< "<Family>" << "CPU INDENTIFIER" << "</Family>" << std::endl
			<< "<Vendor>" << "CPU VENDOR" << "</Vendor>" << std::endl
			<< "<Features>" << "n/a" << "</Features>" << std::endl
			<< "<ClockSpeed>" << "CPU CLOCK" << "</ClockSpeed>" << std::endl
			<< "</Processor>" << std::endl;


		_logFile << "<Memory>" << std::endl;
		_logFile << "<Total>"
			<< "TOTAL VIRTUAL MEMORY"
			<< " ("
			<< "TOTAL PSIHICAL MEMORY"
			<< " phys.)</Total>" << std::endl
			<< "<Available>"
			<< "VIRTUAL MEMORY AVAILABLE"
			<< " ("
			<< "PSIHICAL MEMORY AVAILABLE"
			<< " phys.)</Available>" << std::endl
			<< "</Memory>" << std::endl;


		_logFile << "<Graphics>" << std::endl
			<< "<Type>" << "GPU NAME" << "</Type>" << std::endl
			<< "<Manufacturer>" << "GPU MANUFACTURER" << "</Manufacturer>" << std::endl
			<< "</Graphics>" << std::endl;

		_logFile << "</Configuration>" << std::endl
			<< "</Session>" << std::endl
			<< "</LogHeader>" << std::endl;
		_logFile.flush();
		_streamPosition = _logFile.tellp();
		_ticksStart = GetTickCount();
		_logId = 0;

	}

	enum logType
	{
		Error,
		Warning,
		Comment,
		Event,
		Debug,
		Message
	};

	void write(logType logType,
		std::string strNameSpace,
		std::string strSourceFile,
		std::string strFunction,
		int iSourceLine,
		std::string strMessage)
	{
		if (logType > _logLevel)
		{
			return;
		}

		strSourceFile = strSourceFile.substr(strSourceFile.find_last_of("\\") + 1);


		_logFile.seekp(_streamPosition);
		_logFile << "<LogEvent id=\"" << _logId << "\">" << std::endl;

		_logFile << "<Type>";

		std::string logTypeStr;

		switch (logType)
		{
		case Log::Error:
			logTypeStr = "Error";
			break;
		case Log::Warning:
			logTypeStr = "Warning";
			break;
		case Log::Comment:
			logTypeStr = "Comment";
			break;
		case Log::Event:
			logTypeStr = "Event";
			break;
		case Log::Debug:
			logTypeStr = "Debug";
			break;
		case Log::Message:
			logTypeStr = "Message";
			break;
		default:
			logTypeStr = "Default";
			break;
		}

		_logFile << logTypeStr;


		_logFile << "</Type>" << std::endl;

		_logFile << "  <TimeIndex>" << (float)(GetTickCount() - _ticksStart) / 1000.0f << "</TimeIndex>" << std::endl;
		_logFile << "  <Namespace>" << strNameSpace.c_str() << "</Namespace>" << std::endl;
		_logFile << "  <File>" << strSourceFile.c_str() << "</File>" << std::endl;
		_logFile << "  <Function>" << strFunction.c_str() << "</Function>" << std::endl;
		_logFile << "  <LineNumber>" << iSourceLine << "</LineNumber>" << std::endl;
		_logFile << "  <Message disable-output-escaping=\"yes\">" << strMessage.c_str() << "</Message>" << std::endl;
		_logFile << "</LogEvent>" << std::endl;


		_streamPosition = _logFile.tellp();
		_logFile << "</RunTimeLog>" << std::endl;
		_logFile.flush();
		++_logId;
	}


	

	std::ofstream _logFile;
	std::streampos _streamPosition;
	unsigned int _logId;
	DWORD _ticksStart;
	logType _logLevel;
};