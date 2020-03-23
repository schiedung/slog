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

enum class level
{
    debug    = 0,
    info     = 1,
    warning  = 2,
    error    = 3,
    off      = 5
};

static level log_level = level::debug;

static std::ostream nullstream = std::ostream(nullptr);

struct debug_type
{
    template< class T>
    constexpr std::ostream& operator << (T& rhs)
    {
#ifndef NLOG_DEBUG
       if (log_level <= level::debug)
       {
           return std::cout << "[debug] " << rhs;
       }
#endif
       return nullstream;
    }
};
static debug_type debug;

struct info_type
{
    friend constexpr std::ostream& operator << (std::ostream&, info_type& rhs);
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
};
static info_type info;

struct warning_type
{
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
};
static warning_type warn;

struct error_type
{
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
};
static error_type error;
}
#endif /* SLOG_H */
