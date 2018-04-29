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
#include <boost/property_tree/ini_parser.hpp>
using namespace boost;

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

    SetString("#SYSTEM_save_path", ".");

    uint32_t Size;
    char* pData = sResourceMgr->Read("system/system.ini", Size);
    assert(pData);

    string ini = NpaFile::ToUtf8(pData, Size);
    istringstream iss(ini);
    property_tree::ptree tree;
    property_tree::ini_parser::read_ini(iss, tree);

    string bland = tree.get<string>("プロダクト.bland");
    string name = tree.get<string>("プロダクト.name");
    string version = tree.get<string>("プロダクト.version");

    start = tree.get<string>("スクリプト.start");
    close = tree.get<string>("スクリプト.close");
    menu = tree.get<string>("スクリプト.menu");

    uint32_t bgm = tree.get<uint32_t>("サウンド.bgm_volume");
    uint32_t se = tree.get<uint32_t>("サウンド.bgm_volume");
    uint32_t voice = tree.get<uint32_t>("サウンド.bgm_volume");

    SetString("#SYSTEM_version", version);
    SetInt("#SYSTEM_sound_volume_bgm", bgm);
    SetInt("#SYSTEM_sound_volume_bgm_default", bgm);
    SetInt("#SYSTEM_sound_volume_se", se);
    SetInt("#SYSTEM_sound_volume_se_default", se);
    SetInt("#SYSTEM_sound_volume_voice", voice);
    SetInt("#SYSTEM_sound_volume_voice_default", voice);

    delete pData;
}

SGInterpreter::~SGInterpreter()
{
    delete sExe;
    delete sResourceMgr;
}
