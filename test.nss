chapter main
{
    $a = 3;
    $b = $a - 1;
    $b--;
    $a++;
    CreateWindow("TODO", 20001, 0, 0, 1024, 576, "false");
<PRE @box00>[text00010]
<voice name="？？？" class="VID_MAY" src="voice/MAY_0000" mode="on">
「ねぇねぇ。なにブツブツ言ってるのー？」

右耳に当てているケータイ電話。通話口からはなにも聞こえてこない。ノイズすらない。完全に無音。

夏の強烈な日射しを受けて。

ぽたりと、俺の<RUBY text="あごさき">顎先</RUBY>から汗が<RUBY text="ひとしずく">一滴</RUBY>落ち、アスファルトに染みを作った。

</PRE>
    Move($SYSTEM_present_text, 0, 126, 387, "null", "false");
    WaitText($SYSTEM_present_text, "null");
    CreateName("CHERP");
    CreateTexture("CHERP/DERP", 500, "center", "middle", "cg/ibg/ibg003.png");
    Fade("CHERP/DERP", 0, 0, "derp", "true");
    Fade("CHERP/DERP", 3000, 1000, "derp", "false");
    Move("CHERP/DERP", 3000, 100, 100, "Axl2", "true");
    Fade("CHERP/DERP", 3000, 0, "derp", "true");
    SetAlias("CHERP/DERP", "DERP");
    Wait(1000);
    Delete("@DERP");
    CreateMovie("Movie", 11100, 0, 0, "false", "false", "dx/timeleapbg.ngs", "true");
    Request("Movie", "Play");
    WaitKey(DurationTime("Movie"));
    Delete("Movie");
    CreateSound("TestSE", "SE", "sound/se/cosupure.ogg");
    Request("TestSE", "Play");
    Wait(DurationTime("TestSE"));
    StArray();
    CreateTexture("TEST0", 500, 0, 0, "cg/ev/EV_C02C.jpg");
    ApplyBlur("TEST0", "SEMIHEAVY");
    WaitKey(3000);
    Delete("TEST0");
    CreateTexture("TEST2", 500, 0, 0, "cg/bg/tit001.jpg");
    Fade("TEST2", 0, 0, "derp", "true");
    Fade("TEST2", 1000, 1000, "derp", "true");
    WaitKey(2000);
    Fade("TEST2", 1000, 0, "derp", "true");
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
