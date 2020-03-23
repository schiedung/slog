#include "slog.h"

int main (int argc, char *arc[])
{
    int A = 321;
    double B  = 124E-2;
    
    slog::debug << "message\n";
    slog::debug << "value: " << A << "\n";
    slog::debug << "value: " << B << "\n";

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
