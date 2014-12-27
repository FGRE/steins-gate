/* 
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014 Mislav Blažević <krofnica996@gmail.com>
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
#include "SGResourceMgr.hpp"
#include "scriptfile.hpp"
#include "isgfile.hpp"

static const char* ArchieveFileNames[] =
{
    "cg.npa",
    "nss.npa",
    "voice.npa",
    "sound.npa",
    nullptr
};

SGResourceMgr::SGResourceMgr()
{
    Archives.resize(sizeof(ArchieveFileNames) / sizeof(const char*) - 1);
    for (uint32_t i = 0; ArchieveFileNames[i]; ++i)
        Archives[i] = new ISGFile(ArchieveFileNames[i]);
    assert(!Archives.empty());
}

ScriptFile* SGResourceMgr::ReadScriptFile(const std::string& Path)
{
    // Check Archives
    uint32_t NsbSize;
    char* NsbData = Read(Path.substr(0, Path.size() - 1) + "b", NsbSize);
    uint32_t MapSize;
    char* MapData = Read(Path.substr(0, Path.size() - 3) + "map", MapSize);

    // Both files found
    if (NsbData && MapData)
        return new ScriptFile(Path, NsbData, NsbSize, MapData, MapSize);
    return nullptr;
}
