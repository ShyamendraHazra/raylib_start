#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string>
#include <hex_to_rgb.h>
#include <fstream>
#include <file_io.h>

void CustomLog(int msgType, const char *text, va_list args);

int main()
{
    SetTraceLogCallback(CustomLog);

    InitWindow(800, 450, "raylib [core] example - basic window");


    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(hexToRGBA("1E201E"));
            DrawText("Congrats! You created your first window!", 190, 200, 20, hexToRGBA("697565"));
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void CustomLog(int msgType, const char *text, va_list args)
{
    char timeStr[64] = { 0 };
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%H:%M:%S", tm_info);

    std::string logType;
    std::string file_name = "logs/ray_log_" + std::string(timeStr) + ".log";
    
    switch (msgType)
    {
        case LOG_INFO: logType = "[INFO] "; break;
        case LOG_ERROR: logType = "[ERROR]"; break;
        case LOG_WARNING: logType = "[WARN] "; break;
        case LOG_DEBUG: logType = "[DEBUG]"; break;
        default: logType = "[UNKNOWN]"; break;
    }

    // Format the message
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), text, args);

    // Construct the complete log line
    std::string logLine = "[" + std::string(timeStr) + "] " + logType + " : " + buffer + "\n";

    // Write to file in a single operation
    if(write_file(file_name, logLine)) {
        exit(EXIT_FAILURE);
    }
    
}