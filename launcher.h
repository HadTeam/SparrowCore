#pragma once
#include <QProcess>
#include "commandline.h"
#include "minecraft.h"

namespace Sparrow::launch {
	class LaunchArgument {
		CommandLine CommandLine_jvmArgs;
		Minecraft Minecraft;
		//TODO User User;
	};
	class Launcher
	{
		QProcess launch(LaunchArgument arg);
	};
}