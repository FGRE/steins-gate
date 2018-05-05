/* void SetShortcut(Key, Script) */
chapter main
{
    /* Triggering a shortcut is a blocking operation */
    SetShortcut("M", "nss/sys_menu.nss");
    SetShortcut("S", "nss/sys_save.nss");
    SetShortcut("L", "nss/sys_load.nss");
    SetShortcut("C", "nss/sys_config.nss");
    SetShortcut("B", "nss/sys_backlog.nss");
    SetShortcut("H", "nss/extra_tips.nss");
    WaitKey();
    Exit();
}
