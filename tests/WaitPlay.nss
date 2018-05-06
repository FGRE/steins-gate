/* void WaitPlay(Handle, unk) */
chapter main
{
    CreateSound("sound", "SE", "sound/se/comp_slow");
    Request("sound", Play);
    WaitPlay("sound", null);
    Exit();
}
