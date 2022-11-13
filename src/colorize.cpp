#include "colorize.h"
// Colorize console output
CustomString colorText(const char *c, const char *color) {
	return CustomString(CustomString("\x1B[") + CustomString(color) + "m" +
						CustomString(c) + CustomString("\033[0m"));
}

CustomString colorText(CustomString const &c, const char *color) {
	return CustomString(CustomString("\x1B[") + CustomString(color) + "m" + c +
						CustomString("\033[0m"));
}