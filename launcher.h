#pragma once

#include <QProcess>
#include "commandline.h"
#include "minecraft.h"

namespace Sparrow::launch {
    class Launcher {
        QProcess launch(LaunchArgument arg);
    };
}