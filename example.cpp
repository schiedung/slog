#include "slog.h"
#include <string>

int main (int argc, char *arc[])
{
    const int A = 321;
    const double B  = 124E-2;
    const std::string C = "Hello World";


    for (size_t i = 0; i < 100000; i++)
    {
        slog::debug << "message\n";
        slog::debug << "value: " << i << "\n";
    }

    slog::debug(-1) << "Sublevel -1\n";
    slog::debug( 0) << "Sublevel  0\n";
    slog::debug( 1) << "Sublevel  1\n";

    slog::info << "info message\n";
    slog::info(0) << "value: " << A << "\n";
    slog::info(1) << "value: " << B << "\n";
    slog::info(2) << "value: " << C << "\n";

    slog::warn << "warning message\n";
    slog::warn(0) << "value: " << A << "\n";
    slog::warn(1) << "value: " << B << "\n";
    slog::warn(2) << "value: " << C << "\n";

    slog::error << "message\n";
    slog::error(0) << "value: " << A << "\n";
    slog::error(1) << "value: " << B << "\n";
    slog::error(2) << "value: " << C << "\n";

    return 0;
}
