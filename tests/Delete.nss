/* void Delete(Handle) */
chapter main
{
    CreateColor("color1", 0, 0, 0, 1024, 576, "green");
    CreateColor("color2", 0, 0, 0, 1024, 576, "red");
    /* Lock means undeleteable */
    Request("color1", Lock);
    WaitKey();
    Delete("*");
    WaitKey();
    Exit();
}
