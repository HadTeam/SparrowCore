#pragma once

#include <QProcess>
#include "CommanLline.h"
#include "Minecraft.h"

namespace Sparrow::launch {
    class Launcher {
        QProcess launch(LaunchArgument arg);
    };
}