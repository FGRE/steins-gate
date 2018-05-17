/* void Request(Handle, Request) */
chapter main
{
    CreateColor("color", 0, 0, 0, 1024, 576, "red");
    WaitKey();
    Request("color", "Erase");
    WaitKey();
    Request("color", "Enter");
    WaitKey();
    Exit();
}
