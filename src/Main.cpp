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
#include "SGWindow.hpp"
#include "SGExe.hpp"
#include "SGInterpreter.hpp"
#include "npaversion.hpp"
#include "npengineversion.hpp"
#include "version.hpp"
#include <iostream>
#include <boost/program_options.hpp>
using namespace std;
using namespace boost::program_options;

int main(int argc, char** argv)
{
    ExePublisher Version;
    bool Debug;
    options_description desc("Options");
    desc.add_options()
        ("help", "Print this message")
        ("version", "Print version")
        ("exe", value<int>((int*)&Version)->default_value(EXE_NITROPLUS), "Source of STEINSGATE.exe\n    0 - Nitroplus\n    1 - JAST\n    2 - Fuwanovel")
        ("script", value<string>(), "Path to nss script to execute")
        ("debug", value<bool>(&Debug)->default_value(false), "Start script debugger")
    ;

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
    {
        cout << desc << "\n";
        return 1;
    }
    if (vm.count("version"))
    {
        cout << "libnpa " << NPA_VERSION << endl;
        cout << "libnpengine "  << NPENGINE_VERSION << endl;
        cout << "steins-gate " << VERSION << endl;
        return 1;
    }

    SGWindow* pWindow = new SGWindow;
    SGInterpreter* pInterpreter = new SGInterpreter(pWindow, Version);

    if (vm.count("script"))
        pInterpreter->ExecuteLocalScript(vm["script"].as<string>());
    else
        pInterpreter->ExecuteScript("nss/0_boot.nss");

    if (Debug)
        pInterpreter->StartDebugger();

    pWindow->SetInterpreter(pInterpreter);
    pWindow->Run();
    delete pWindow;
}
