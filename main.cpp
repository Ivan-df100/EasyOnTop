#include <iostream>
#include <windows.h>

void switch_topmost() {
	HWND hwnd = GetForegroundWindow();

	bool is_topmost = GetWindowLongPtr(hwnd, GWL_EXSTYLE) & WS_EX_TOPMOST;

	if (!is_topmost) {
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	else {
		SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
}

int main()
{
	std::cout << "AlwaysOnTop++ @df100 (Use ctrl+alt+g for switch top mode on window)";

	RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_ALT, 0x47);
	MSG message;

	while (1) {
		if (GetMessage(&message, NULL, 0, 0) > 0) {
			if (message.message == WM_HOTKEY) {
				if (message.wParam == 1) {
					switch_topmost();
				}
			}
		}
	}
}
