#pragma once
#include <QProcess>
#include "commandline.h"
#include "minecraft.h"

namespace Sparrow::launch {
	class __declspec(dllexport) LaunchArgument {
		CommandLine CommandLine_jvmArgs;
		Minecraft Minecraft;
		//TODO User User;
	};
	class __declspec(dllexport) Launcher
	{
		QProcess launch(LaunchArgument arg);
	};
}