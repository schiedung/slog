#include "slog.h"
#include <string>

int main (int argc, char *arc[])
{
    slog::log_sublevel = 2;

    for (unsigned int i = 0; i < argc; i++)
    {
        const std::string command(arc[i]);

        if (command == "-ld" or command == "--log_level_debug")
        {
            slog::log_level = slog::level::debug;
        }
        else if (command == "-li" or command == "--log_level_info")
        {
            slog::log_level = slog::level::info;
        }
        else if (command == "-lw" or command == "--log_level_warning")
        {
            slog::log_level = slog::level::warning;
        }
        else if (command == "-le" or command == "--log_level_error")
        {
            slog::log_level = slog::level::error;
        }
        else if (command == "-lo" or command == "--log_level_off")
        {
            slog::log_level = slog::level::error;
        }
        else if (command == "-ls" or command == "--log_sub_level")
        {
            slog::log_sublevel = std::atoi(arc[i+1]);
        }
    }

    const int A = 321;
    const double B  = 124E-2;
    const std::string C = "Hello World";


    for (size_t i = 0; i < 100000; i++)
    {
        slog::debug(1) << "message\n";
        slog::debug(1) << "value: " << i << "\n";
    }

    slog::debug    << "debug\n";
    slog::debug(0) << "top level message " << A << "\n";
    slog::debug(1) << "sub level message " << B << "\n";
    slog::debug(2) << "sub level message " << C << "\n";
    slog::debug(3) << "sub level message\n";

    slog::info    << "info\n";
    slog::info(0) << "top level message " << A << "\n";
    slog::info(1) << "sub level message " << B << "\n";
    slog::info(2) << "sub level message " << C << "\n";
    slog::info(3) << "sub level message\n";

    slog::warn    << "warning\n";
    slog::warn(0) << "top level message " << A << "\n";
    slog::warn(1) << "sub level message " << B << "\n";
    slog::warn(2) << "sub level message " << C << "\n";
    slog::warn(3) << "sub level message\n";

    slog::error    << "error \n";
    slog::error(0) << "top level message " << A << "\n";
    slog::error(1) << "sub level message " << B << "\n";
    slog::error(2) << "sub level message " << C << "\n";
    slog::error(3) << "sub level message\n";

    return 0;
}
