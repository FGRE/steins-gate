/*
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014-2016,2018 Mislav Blažević <krofnica996@gmail.com>
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
#include "nsbmagic.hpp"
#include "nsbconstants.hpp"
#include "scriptfile.hpp"
#include "NSBContext.hpp"
#include <boost/property_tree/ini_parser.hpp>
using namespace boost;

SGConfig* sCfg;

SGConfig::SGConfig()
{
    uint32_t Size;
    char* pData = sResourceMgr->Read("system/system.ini", Size);
    assert(pData);

    string ini = NpaFile::ToUtf8(pData, Size);
    istringstream iss(ini);
    property_tree::ptree tree;
    property_tree::ini_parser::read_ini(iss, tree);

    bland = tree.get<string>("プロダクト.bland");
    name = tree.get<string>("プロダクト.name");
    version = tree.get<string>("プロダクト.version");

    start = tree.get<string>("スクリプト.start");
    close = tree.get<string>("スクリプト.close");
    menu = tree.get<string>("スクリプト.menu");

    title = tree.get<string>("ウィンドウ.title");
    debug = tree.get<int32_t>("ウィンドウ.debug");

    font_face = tree.get<string>("フォント.face");
    font_size = tree.get<uint32_t>("フォント.size");
    font_weight = tree.get<uint32_t>("フォント.weight");
    font_inline = tree.get<string>("フォント.inline");
    font_outline = tree.get<string>("フォント.outline");
    font_margin_line = tree.get<uint32_t>("フォント.margin_line");
    font_margin_low = tree.get<uint32_t>("フォント.margin_low");

    bad_start = tree.get<string>("テキスト.bad_start");
    bad_end = tree.get<string>("テキスト.bad_end");
    ruby_rate = tree.get<uint32_t>("テキスト.ruby_rate");

    bgm_volume = tree.get<uint32_t>("サウンド.bgm_volume");
    se_volume = tree.get<uint32_t>("サウンド.bgm_volume");
    voice_volume = tree.get<uint32_t>("サウンド.bgm_volume");

    icon_line = tree.get<string>("アイコン.icon_line");
    icon_page = tree.get<string>("アイコン.icon_page");
    icon_auto = tree.get<string>("アイコン.icon_auto");

    script = tree.get<string>("バックログ.script");
    icon_voice = tree.get<string>("バックログ.icon_voice");
    word_in_row = tree.get<uint32_t>("バックログ.word_in_row");

    enable = tree.get<string>("セーブ.enable");

    all_name = tree.get<string>("ボイス.all_name");

    compiler = tree.get<string>("コンパイラ.compiler");

    delete[] pData;
}

SGInterpreter::SGInterpreter(SGWindow* pWindow) : NSBInterpreter(pWindow)
{
    SetString("#SYSTEM_save_path", ".");
    SetString("#SYSTEM_version", sCfg->version);
    SetInt("#SYSTEM_sound_volume_bgm", sCfg->bgm_volume);
    SetInt("#SYSTEM_sound_volume_bgm_default", sCfg->bgm_volume);
    SetInt("#SYSTEM_sound_volume_se", sCfg->se_volume);
    SetInt("#SYSTEM_sound_volume_se_default", sCfg->se_volume);
    SetInt("#SYSTEM_sound_volume_voice", sCfg->voice_volume);
    SetInt("#SYSTEM_sound_volume_voice_default", sCfg->voice_volume);

    Builtins[MAGIC_ALLOW_PHONE_CALL] = { (void(NSBInterpreter::*)())&SGInterpreter::AllowPhoneCall, 4};
    Builtins[MAGIC_SEND_MAIL_EDIT] = { (void(NSBInterpreter::*)())&SGInterpreter::SendMailEdit, 0};
    Builtins[MAGIC_UNK101] = { (void(NSBInterpreter::*)())&SGInterpreter::UNK101, 1 };
    Builtins[MAGIC_UNK143] = { (void(NSBInterpreter::*)())&SGInterpreter::UNK143, 1 };
    Builtins[MAGIC_UNK128] = { (void(NSBInterpreter::*)())&SGInterpreter::UNK128, 0 };

    pWindow->AddTexture(pPhone = new Phone(pWindow));
}

SGInterpreter::~SGInterpreter()
{
    delete pPhone;
}

void SGInterpreter::HandleEvent(const SDL_Event& Event)
{
    NSBInterpreter::HandleEvent(Event);
    switch (Event.type)
    {
        case SDL_QUIT:
            ExecuteScriptThread(sCfg->close);
            break;
        case SDL_MOUSEMOTION:
            MouseMoved(Event.motion.x, Event.motion.y);
            break;
        case SDL_MOUSEBUTTONDOWN:
            MouseClicked(Event);
            break;
        case SDL_KEYDOWN:
            if (Event.key.keysym.sym == SDLK_p)
            {
                SDL_PumpEvents();
                if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LALT])
                    PhoneToggle();
            }
    }
}

void SGInterpreter::MouseClicked(const SDL_Event& Event)
{
    if (Event.button.button == SDL_BUTTON_LEFT)
        pPhone->LeftMouseClicked(Event.button.x, Event.button.y);
    else if (Event.button.button == SDL_BUTTON_RIGHT)
        pPhone->RightMouseClicked(this);
}

void SGInterpreter::MouseMoved(int x, int y)
{
    pPhone->MouseMoved(x, y);
}

void SGInterpreter::WriteHack(const char* ScriptName, uint32_t LineNumber, uint16_t NewMagic)
{
    sResourceMgr->GetScriptFile(ScriptName)->GetLine(LineNumber)->Magic = NewMagic;
}

void SGInterpreter::OnVariableChanged(const string& Name)
{
    NSBInterpreter::OnVariableChanged(Name);
    // Handle hardcoded phone operations
    if (Name == "$SF_Phone_Open")
    {
        pPhone->Toggle(GetInt("$SF_Phone_Open") != 0);
        pContext->WaitAction(pPhone, -1);
    }
    else if (Name == "$SW_PHONE_MODE")
        SGPhoneMode();
    else if (Name == "$SF_PhoneMailReciveNew")
        pPhone->MailReceive(GetInt("$SF_PhoneMailReciveNew"));
    else if (Name == "$SF_PhoneSD_Disp")
        pPhone->SDDisplay(GetInt("$SF_PhoneSD_Disp"));
    else if (Name == "$LR_DATE")
        pPhone->SetDate(GetInt("$LR_DATE"));
    else if (Name == "$SW_PHONE_PRI")
        SGPhonePriority();
    else if (Name == "$SW_PHONE_ADRMENUCUR")
        PhoneAddressMenuHighlight();

    // Hack
    if (Name == "#SYSTEM_skip_absolute")
        GetVar(Name)->Set(Variable::MakeString("true"));
}

void SGInterpreter::PhoneAddressMenuHighlight()
{
    int32_t Index = GetInt("$SW_PHONE_ADRMENUCUR");
    pPhone->AddressMenuHighlight(Index);
    SetInt("$SW_PHONE_ADRCURCNO", Index);
}

void SGInterpreter::PhoneToggle()
{
    bool Open = GetInt("$SF_Phone_Open") != 0;
    if (pPhone->Toggle(!Open))
    {
        SetInt("$SF_Phone_Open", !Open);
        pContext->WaitAction(pPhone, -1);
    }
}

void SGInterpreter::SGPhonePriority()
{
    pPhone->SetPriority(GetInt("$SW_PHONE_PRI"));
    pWindow->RemoveTexture(pPhone);
    pWindow->AddTexture(pPhone);
}

void SGInterpreter::SGPhoneMode()
{
    string Mode = GetString("$SW_PHONE_MODE");
    pPhone->UpdateMode(ConstantToValue<ePhoneMode>(Mode));
}

void SGInterpreter::SendMailEdit()
{
    int32_t Index = ConstantToValue<PhoneMail>(GetString("$SW_PHONE_SENDMAILNO"));
    string Subject = sExe->ReadStringIndirect(VA_PHONE_MAIL, Index, 0x40, 0x34);
    string Sender = sExe->ReadStringIndirect(VA_PHONE_MAIL, Index, 0x40, 0x38);
    string Body = sExe->ReadStringIndirect(VA_PHONE_MAIL, Index, 0x40, 0x3C);
    pPhone->PhoneSendMailEdit(Subject, Sender, Body);
}

void SGInterpreter::AllowPhoneCall()
{
    uint16_t Mask = 0;
    for (uint8_t i = 0; i < 4; ++i)
        Mask |= (1 << PopInt());
    pPhone->SetPhoneCallAllowMask(Mask);
}

// AddressBookSet
void SGInterpreter::UNK101()
{
    pPhone->AddressbookSet(PopInt());
}

// AddressBookReset
void SGInterpreter::UNK143()
{
    pPhone->AddressbookReset(PopInt());
}

void SGInterpreter::UNK128()
{
    // HACK
    Return();
}
