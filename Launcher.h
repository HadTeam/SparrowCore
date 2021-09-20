#pragma once
#include <QProcess>
#include "commandline.h"
#include "minecraft.h"

namespace Sparrow::launch {
	class __declspec(dllexport) Launcher
	{
		QProcess launch(LaunchArgument arg);
	};
}