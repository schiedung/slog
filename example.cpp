#include "slog.h"

int main (int argc, char *arc[])
{
    int A = 321;
    double B  = 124E-2;
    
    for (size_t i = 0; i < 100000; i++)
    {
        slog::debug << "message\n";
        slog::debug << "value: " << i << "\n";
    }

    slog::info << "message\n";
    slog::info << "value: " << A << "\n";
    slog::info << "value: " << B << "\n";

    slog::warn << "message\n";
    slog::warn << "value: " << A << "\n";
    slog::warn << "value: " << B << "\n";

    slog::error << "message\n";
    slog::error << "value: " << A << "\n";
    slog::error << "value: " << B << "\n";
    
    return 0;
}
