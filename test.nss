#include "nss/function.nss"

chapter main
{
    #GameLoading = "SteinsGate";
    CreateSound("TestBGM", "BGM", "sound/bgm/bgm03");
    CreateText("TESTTEXT", 10000, "center", "middle", 0, 0, "メリークリスマス");
    SetLoopPoint("TestBGM", 11000, 15000);
    Request("TestBGM", "Play");
    Wait(1000);
    Request("TestBGM", "Pause");
    Wait(1000);
    Request("TestBGM", "Resume");
    $a = 3;
    $b = $a - 1;
    $b--;
    $a++;
    CreateColor("タイトルカラー", 150, 0, 0, 1024, 576, "#FFFF00");
    SetShortcut("Q", "nss/0_boot.nss");
    WaitKey();
    Delete("タイトルカラー");
    CreateWindow("TODO", 20001, 0, 0, 1024, 576, "false");
<PRE @box00>[text00010]
<voice name="？？？" class="VID_MAY" src="voice/MAY_0000" mode="on">
「ねぇねぇ。なにブツブツ言ってるのー？」

右耳に当てているケータイ電話。通話口からはなにも聞こえてこない。ノイズすらない。完全に無音。

夏の強烈な日射しを受けて。

ぽたりと、俺の<RUBY text="あごさき">顎先</RUBY>から汗が<RUBY text="ひとしずく">一滴</RUBY>落ち、アスファルトに染みを作った。

</PRE>
    SetText();
    Move($SYSTEM_present_text, 0, 126, 387, "null", "false");
    WaitText($SYSTEM_present_text, "null");
    CreateName("CHERP");
    LoadImage("POOP", "cg/ibg/ibg003.png");
    CreateClipTexture("CHERP/DERP", 500, "center", "middle", 412, 188, 100, 100, POOP);
    Fade("CHERP/DERP", 0, 0, "null", "true");
    Fade("CHERP/DERP", 3000, 1000, "null", "false");
    Move("CHERP/DERP", 3000, 100, 100, "Axl2", "true");
    SetAlias("CHERP/DERP", "DERP");
    Wait(1000);
    Delete("@DER*");
    Delete(POOP);
    CreateMovie("Movie", 11100, 0, 0, "false", "false", "dx/timeleapbg.ngs", "true");
    Request("Movie", "Play");
    WaitKey(DurationTime("Movie"));
    Delete("Movie");
    StArray();
    CreateTexture("TEST0", 500, 0, 0, "cg/ev/EV_C02C.jpg");
    SetShade("TEST0", "SEMIHEAVY");
    WaitKey(3000);
    Delete("TEST0");
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    Fade("TEST2", 0, 0, "null", "true");
    Fade("TEST2", 1000, 1000, "null", "true");
    WaitKey(2000);
    Fade("TEST2", 1000, 0, "null", "true");
    CreateTexture("TEST", 600, 0, 0, "cg/ev/EV_Z01A.jpg");
    Move("TEST", 0, 210, -70, "null", "true");
    SetVertex("TEST", 306, 404);
    Zoom("TEST", 0, 5000, 5000, "null", "true");
    Request("TEST", "Smoothing");
    Move("TEST", 1330, 0, 0, "Axl2", "false");
    Zoom("TEST", 1330, 1050, 1050, "Axl2", "true");
    CreateTexture("TEST3", 9000, 0, 0, "cg/bg/BG_BLACK.jpg");
    DrawTransition("TEST3", 4000, 0, 250, 250, "null", "cg/data/mask17.png", "true");
    DrawTransition("TEST3", 4000, 250, 0, 250, "null", "cg/data/mask17.png", "true");
    WaitKey(3000);
    Delete("TEST3");
    func("herp", "derp");
    Delete("*/*");
    Delete("*");
}

function func($herp, $derp)
{
    CreateProcess("TEST3", 0, 0, 0, "thread");
    Request("TEST3", "Start");
}

function thread()
{
    VariableValue("$", "herp", "cherp");
    $temp = VariableValue("$", "derp");
    WriteFile($herp, $temp);
}
