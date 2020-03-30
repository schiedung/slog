#ifndef SLOG_H
#define SLOG_H

#include <iostream>

namespace slog
{

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/// log level type
enum class level
{
    debug    = 0,
    info     = 1,
    warning  = 2,
    error    = 3,
    off      = 5
};

static level log_level    = level::debug; ///< global log level
static int   log_sublevel = 0; ///< global log sub-level

///< global log sub-level
static std::ostream nullstream = std::ostream(nullptr);

/// cout style debug-level info class
struct debug_type
{
    /// cout style << operator to output messages
    template< class T>
    constexpr std::ostream& operator << (T& rhs)
    {
#ifndef NLOG_DEBUG
       if (log and log_level <= level::debug)
       {
           return std::cout << "[debug] " << rhs;
       }
       else log = true;
#endif
       return nullstream;
    }

    /// ()operator to set numeric message sub-levels
    debug_type& operator() (int sublevel)
    {
#ifndef LOGSUBLEVEL
        if(sublevel < log_sublevel)
        {
            log = false;
        };
#endif
        return *this;
    }

  private:
    bool log = true; ///< true if massage is logged

};
static debug_type debug; ///< instance of debug message logger

/// cout style info-level info class
struct info_type
{
    /// cout style << operator to output messages
    template< class T>
    constexpr std::ostream& operator << (T& rhs)
    {
#ifndef NLOG_INFO
        if (log_level <= level::info)
        {
            return std::cout << "["<< GREEN << "info" << RESET  << "] " << rhs;
        }
#endif
        return nullstream;
    }

    /// ()operator to set numeric message sub-levels
    info_type& operator() (int sublevel)
    {
#ifndef LOGSUBLEVEL
        if(sublevel < log_sublevel)
        {
            log = false;
        };
#endif
        return *this;
    }

  private:
    bool log = true; ///< true if massage is logged

};
static info_type info;

/// cout style warning-level info class
struct warning_type
{
    /// cout style << operator to output messages
    template< class T>
    constexpr std::ostream& operator << (T& rhs)
    {
#ifndef NLOG_WARINING
        if (log_level <= level::warning)
        {
            return std::clog << "["<< BOLDYELLOW << "warning" << RESET  << "] " << rhs;
        }
#endif
        return nullstream;
    }

    /// ()operator to set numeric message sub-levels
    warning_type& operator() (int sublevel)
    {
#ifndef LOGSUBLEVEL
        if(sublevel < log_sublevel)
        {
            log = false;
        };
#endif
        return *this;
    }

  private:
    bool log = true; ///< true if massage is logged

};
static warning_type warn;

/// cout style error-level info class
struct error_type
{
    /// cout style << operator to output messages
    template< class T>
    constexpr std::ostream& operator << (T& rhs)
    {
#ifndef NLOG_ERROR
        if (log_level <= level::error)
        {
            return std::cerr << "["<< BOLDRED << "error" << RESET  << "] " << rhs;
        }
#endif
        return nullstream;
    }

    /// ()operator to set numeric message sub-levels
    error_type& operator() (int sublevel)
    {
#ifndef LOGSUBLEVEL
        if(sublevel < log_sublevel)
        {
            log = false;
        };
#endif
        return *this;
    }

  private:
    bool log = true; ///< true if massage is logged

};
static error_type error;
}
#endif /* SLOG_H */
