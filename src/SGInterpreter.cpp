/* 
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014-2016 Mislav Blažević <krofnica996@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */
#include "SGInterpreter.hpp"
#include "SGResourceMgr.hpp"
#include "SGWindow.hpp"
#include "npafile.hpp"

SGInterpreter::SGInterpreter(SGWindow* pWindow, ExePublisher Version) : NSBInterpreter(pWindow)
{
    // How many NULL bytes terminate string in exe
    uint8_t CharWidth;

    switch (Version)
    {
        case EXE_FUWANOVEL:
        case EXE_NITROPLUS:
            NpaFile::SetLocale("ja_JP.CP932");
            CharWidth = 1;
            break;
        case EXE_JAST:
            NpaFile::SetLocale("en_US.UTF-16");
            CharWidth = 2;
            break;
    }

    sResourceMgr = new SGResourceMgr;
    sExe = new SGExe("STEINSGATE.exe", Version, CharWidth);

    // Hack
    SetVar("#SYSTEM_save_path", Variable::MakeString("."));
}

SGInterpreter::~SGInterpreter()
{
    delete sExe;
    delete sResourceMgr;
}
